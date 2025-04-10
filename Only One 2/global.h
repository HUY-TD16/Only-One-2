﻿#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
//#include "animation.h"
#include <SDL_ttf.h>

// mÀN HÌNH 
extern SDL_Window* gWindow ;
extern SDL_Renderer* gRenderer ;
extern TTF_Font* gFont;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
// Kích thước và tốc độ 
const int PLAYER_VEL = 3  ;
const int PLAYER_SIZE = 20;
const int FIREBALL_SIZE = 20;
const float FIREBALL_SPEED = 200.00f;
const int DASHDISTANCE = 100;

// Thời gian
const Uint32 frameDelay = 100;
const Uint32 increaseInterval = 20000;
const Uint32 dashCoolDown = 5000;
const Uint32 clearCoolDown = 10000;
const Uint32 invincibilityCoolDown = 10000;

void updateFrameTime();
bool init();
void close();
//void loadMedia(Animation& animation);
void logErrorAndExit(const char* msg, const char* error);
bool isButtonClick(int x, int y, SDL_Rect button);

//enum class State {
//    MENU,
//    PLAYING,
//    PAUSED,
//    GAME_OVER
//};
//
//extern State state;
