#pragma once

#include "player.h"  //Renderer needs to know about player stats
#include "enemy.h"   //Renderer needs to know about enemies
#include "map.h"    //Renderer needs to know about rooms

//All display/output functions
void renderHeader(float version, int width, int height);
void renderPlayer(const Player& player);
void renderStatusBar(const Player& player);
void renderMenu();
void renderRoom(int roomNumber);
void renderMap(const Room& room, const Player& player,
               const Enemy enemies[], int enemyCount);
void renderEnemies(const Enemy enemies[], int enemyCount);