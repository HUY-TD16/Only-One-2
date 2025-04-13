#pragma once
#include "global.h"
#include <iostream>

SDL_Renderer* gRenderer = nullptr;
SDL_Window* gWindow = nullptr;
TTF_Font* gFont = NULL;

void logErrorAndExit(const char* msg, const char* error) {
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
	SDL_Quit();
}
bool init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		logErrorAndExit("SDL_Init", SDL_GetError());
		return false;
	}
	gWindow = SDL_CreateWindow("Only One", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!gWindow) {
		logErrorAndExit("SDL_CreateWindow", SDL_GetError ());
		return false;
	}
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!gRenderer) {
		logErrorAndExit("Create REnder", SDL_GetError());
		return false;
	}
	gFont = TTF_OpenFont("Font/lazy.ttf", 28);
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	gFont = TTF_OpenFont("Font/lazy.ttf", 28);
	if (gFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
	int imgFlag = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlag) & imgFlag)) {
		logErrorAndExit("imgFlag" , SDL_GetError());
		return false ;
	}
	return true;
}
void close() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
bool isButtonClick(int x, int y, SDL_Rect button) {
	return (x >= button.x && x <= button.x + button.w && y >= button.y && y <= button.y + button.h);
}

//void loadMedia(Animation& animation) {
//	animation.loadSpritesheet(gRenderer, "Image/run_right.png", Action::RUN, Direction::RIGHT, 8);
//	animation.loadSpritesheet(gRenderer, "Image/run_left.png", Action::RUN, Direction::LEFT, 8) ;
//	animation.loadSpritesheet(gRenderer, "Image/run_front.png", Action::RUN, Direction::FRONT, 8) ;
//	animation.loadSpritesheet(gRenderer, "Image/run_back.png", Action::RUN, Direction::BACK, 8) ;
//	animation.loadSpritesheet(gRenderer, "Image/idle_right.png", Action::IDLE, Direction::RIGHT, 4) ;
//	animation.loadSpritesheet(gRenderer, "Image/idle_left.png", Action::IDLE, Direction::LEFT, 4) ;
//	animation.loadSpritesheet(gRenderer, "Image/idle_front.png", Action::IDLE, Direction::FRONT, 4) ;
//	animation.loadSpritesheet(gRenderer, "Image/idle_back.png", Action::IDLE, Direction::BACK, 4);
//}