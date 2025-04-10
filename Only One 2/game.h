#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include "player.h"
#include "skill.h"
#include "global.h"
#include "fireball.h"
#include "lasers.h"
#include "explosions.h"
#include "collision.h"
#include "interface.h"
enum class State {
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};
class Game {
public:
    Game();
    ~Game();
    void update(float deltaTime, Uint32 currentTime);
    void render();
    void handleInput(SDL_Event& event);
    void resetGame();
    void loadHighScores();
    void saveHighScores();
private:
    Player player;
    Skills skill;
    FireBall fireball;
    Lasers laser;
    Explosion explosion;
    Collision collsision;
    Interface interface;
    std::vector<ClearEffect> clearEffect;
    //Time
    Uint32 gameStartTime;
    Uint32 lastSpawnTime;
    Uint32 lastFrameTime;
    Uint32 lastLaserTime;
    Uint32 lastExplosionTime;
    Uint32 finalTime;
    State state;
    std::vector<int> highScore;
    bool isNewHighScore;
    bool showTutorial;
    bool showHighScore;
    bool soundOn;

};