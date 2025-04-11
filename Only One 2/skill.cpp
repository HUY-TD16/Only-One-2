#include "skill.h"
#include <cmath>
#include <iostream>

Skills::Skills() {
	lastInvincibilityTime = SDL_GetTicks();
	invincibilityEndTime = SDL_GetTicks();
	isInvincible = false;
	lastDashTime = SDL_GetTicks();
	lastClearTime = SDL_GetTicks();
}
void Skills::reset(Uint32 currentTime) {
	lastInvincibilityTime = currentTime;
	invincibilityEndTime = currentTime;
	lastDashTime = currentTime;
	lastClearTime = currentTime;
	isInvincible = false;
}
void Skills::handleInput(const Uint8* key, Uint32 currentTime, SDL_Event& event, Player& player, std::vector<ClearEffect>& clearEffect, std::vector<FireballIndex>& fireball) {
	if (key[SDL_SCANCODE_A] && (currentTime - lastInvincibilityTime >= invincibilityCoolDown )&& !isInvincible) {
		isInvincible = true;
		lastInvincibilityTime = currentTime;
		invincibilityEndTime = currentTime + invincibilityDuration;
		std::cout << "Invincibility activated\n";
	}
	if (key[SDL_SCANCODE_S] && (currentTime - lastDashTime >= dashCoolDown)) {
		int dx = player.VelX();
		int dy = player.VelY();

		if (dx != 0 || dy != 0 ) {
			float magnitude = std::sqrt(dx * dx + dy * dy);
			float dashDX = (dx / magnitude) * DASHDISTANCE;
			float dashDY = (dy / magnitude) * DASHDISTANCE;
			player.dash(static_cast<int>(std::round(dashDX)), static_cast<int>(std::round(dashDY)));
			lastDashTime = currentTime;
			std::cout << "Dash Activate\n";
		}
	}
	if (key[SDL_SCANCODE_D] && currentTime - lastClearTime >= clearCoolDown) {
		float playerCenterX = player.getX() + PLAYER_SIZE / 2.0f;
		float playerCenterY = player.getY() + PLAYER_SIZE / 2.0f;

		ClearEffect effect;
		effect.x = playerCenterX - clearRadius / 2.0f;
		effect.y = playerCenterY - clearRadius / 2.0f;
		effect.SpawnTime = currentTime;
		clearEffect.push_back(effect);
		auto it = std::remove_if(
			fireball.begin(), fireball.end(), [&](const FireballIndex& f) {
				float dist = std::sqrt(
					std::pow(f.fPosX + FIREBALL_SIZE / 2.0f - playerCenterX, 2) +
					std::pow(f.fPosY + FIREBALL_SIZE / 2.0f - playerCenterY, 2)
				);
				return dist <= clearRadius;
			}
		);

		// Chỉ xóa nếu có ít nhất 1 phần tử cần xóa
		if (it != fireball.end()) {
			fireball.erase(it, fireball.end());
		}
		lastClearTime = currentTime;
		std::cout << "Clear activate\n";
		
	}

}

void Skills::update(Uint32 currentTime) {
	if (isInvincible && currentTime >= invincibilityEndTime) {
		isInvincible = false;
		std::cout << "Invincibility ended\n";
	}
}