#pragma once

#include <SDL.h>
#include <vector>
#include "entities.h"
#include "global.h"
#include "player.h"

class Skills {
public:
	Skills();
	void reset(Uint32 currentTime);
	void handleInput(const Uint8* key, Uint32 currentTime, SDL_Event& event, Player& player, std::vector<ClearEffect>& clearEffect, std::vector<FireballIndex>& fireball);
	void update(Uint32 currentTime);
	bool res() { return isInvincible; }
	Uint32 getLastInvicibility() { return lastInvincibilityTime; }
	Uint32 getLastDashTime() { return lastDashTime; }
	Uint32 getLastClear() { return lastClearTime; }
private:
	Uint32 lastInvincibilityTime;
	Uint32 invincibilityEndTime;
	const Uint32 invincibilityDuration = 2000;
	bool isInvincible;
	Uint32 lastDashTime;
	Uint32 lastClearTime;
	const float clearRadius = PLAYER_SIZE * 5.0f;
};