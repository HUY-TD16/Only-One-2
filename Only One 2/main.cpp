//#include <SDL.h>
//#include <SDL_image.h>
//#include <iostream>
//#include "global.h" 
//#include "LTexture.h"
//#include "player.h"
//#include "animation.h"
//#include "fireball.h"
//#include "collision.h"
//#include "lasers.h"
//#include "explosions.h"
//#include "interface.h"
//
//
//int main(int args, char* argc[]) {
//	LTexture gBackground;
//	
//	Player player;
//	Animation animation;
//	Collision collision;
//	Lasers laser;
//	Skills skill;
//	std::vector<ClearEffect> clearEffect;
//	std::srand(static_cast<unsigned>(std::time(NULL)));
//
//
//	if (!init()) {
//		std::cout << "false \n";
//	}
//	else if (!(
//		animation.loadSpritesheet(gRenderer, "Image/run_right.png", Action::RUN, Direction::RIGHT, 8) &&
//		animation.loadSpritesheet(gRenderer, "Image/run_left.png", Action::RUN, Direction::LEFT, 8) &&
//		animation.loadSpritesheet(gRenderer, "Image/run_front.png", Action::RUN, Direction::FRONT, 8) &&
//		animation.loadSpritesheet(gRenderer, "Image/run_back.png", Action::RUN, Direction::BACK, 8) &&
//		animation.loadSpritesheet(gRenderer, "Image/idle_right.png", Action::IDLE, Direction::RIGHT, 4) &&
//		animation.loadSpritesheet(gRenderer, "Image/idle_left.png", Action::IDLE, Direction::LEFT, 4) &&
//		animation.loadSpritesheet(gRenderer, "Image/idle_front.png", Action::IDLE, Direction::FRONT, 4) &&
//		animation.loadSpritesheet(gRenderer, "Image/idle_back.png", Action::IDLE, Direction::BACK, 4))) {
//		std::cout << "false media animation"; 
//	}
//	else if (!(gBackground.loadFromFile("Image/tileset.png"))) {
//		std::cout << "false load media\n";
//	}
//	else {
//		Explosion explosion;
//		FireBall fireball;
//		Interface interface;
//		bool quit = false;
//		SDL_Event e;
//		Uint32 lastFrameTime_ = SDL_GetTicks();
//		Uint32 lastSpawmTime = SDL_GetTicks();
//		Uint32 lastLaserTime = SDL_GetTicks();
//		Uint32 gameStartTime = SDL_GetTicks();
//		Uint32 lastExplosionTime = SDL_GetTicks();
//
//		while (!quit) {
//			Uint32 currentTime = SDL_GetTicks();     
//			float deltaTime = (currentTime - lastFrameTime_) / 1000.0f;
//			lastFrameTime_ = currentTime;
//			while (SDL_PollEvent(&e)) {
//				if (e.type == SDL_QUIT) {
//					quit = true;
//				}
//				player.handleEvent(e);
//				animation.handleInput(e);
//				skill.handleInput(SDL_GetKeyboardState(NULL), currentTime, e, player , clearEffect, fireball.getFireball());
//				//SDL_GetMouseState(&x, &y);
//			}
//			//std::cout << x << " " << y << std::endl;
//			//std::cout << currentTime << " " << lastSpawmTime << std::endl;
//			player.move();
//			animation.update();
//			skill.update(currentTime);
//			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//			SDL_RenderClear(gRenderer);
//			interface.Menu();
//			//gBackground.render(-100,-100 );
//			animation.render(gRenderer, player.getX()-40*1.5, player.getY()-32*1.5);
//			fireball.spawn( currentTime , player , lastSpawmTime);
//			fireball.update(deltaTime , currentTime);
//			laser.spawn(currentTime, player, lastLaserTime, gameStartTime);
//			laser.update(currentTime);
//			laser.render(gRenderer);
//			explosion.spawn(currentTime, lastExplosionTime, gameStartTime);
//			explosion.update(currentTime);
//			explosion.render(gRenderer);
//			clearEffect.erase(
//				std::remove_if(clearEffect.begin(), clearEffect.end(), [currentTime](const ClearEffect& e) {
//					return currentTime - e.SpawnTime >= 1000;
//					}),
//				clearEffect.end()
//			);
//
//			if (collision.checkCollision(player, skill.res() , fireball.getFireball(), fireball, laser.getLaser(), laser, explosion.getExplosion(), explosion)) {
//				quit = true;
//			}
//			fireball.render(gRenderer);
//			interface.ProgressBars(currentTime, skill.getLastInvicibility(), skill.getLastDashTime(), skill.getLastClear());
//			interface.Timer(currentTime);
//			//interface.Pause();
//			//interface.GameOver(currentTime, true);
//			SDL_RenderPresent(gRenderer);
//			SDL_Delay(16);
//		}
//
//	}
//	close();
//	return 0;
//}