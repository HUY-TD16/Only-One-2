#pragma once

#include <SDL_image.h>
#include <SDL.h>
#include "LTexture.h"
#include <iostream>
#include <string>

extern SDL_Renderer* gRenderer;

class Interface {
public:
	Interface();
	void GameOver();
	void Pause();
	void Menu();
	void Timer(Uint32 currentTime);
	void ProgressBars(Uint32 currentTime, Uint32 lastInvincibilityTime, Uint32 lastDashTime , Uint32 lastClearTime);
	// Menu button
	SDL_Rect StartTextRect = { SCREEN_WIDTH / 2 - 80 , 100 , 160 , 100 };
	SDL_Rect TutorialTextRect = { SCREEN_WIDTH / 2 - 100, 200 , 200 , 100 };
	SDL_Rect HighscoreTextRect = { SCREEN_WIDTH / 2 - 150 , 300 , 300 , 100 };
	SDL_Rect MusicTextRect = { SCREEN_WIDTH / 2 - 60 , 400 , 120 , 100 };

	// Pause button
	SDL_Rect PauseRect = { 10 , 10 , 20 , 20 };

private:
	LTexture RecordText;
	int tic, second, minutes;
	std::string recordText;
	LTexture MenuDisplay;
	LTexture MenuText;
	LTexture PauseDisplay;
	LTexture SkillDisplay;

};