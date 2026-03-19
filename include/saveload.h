#pragma once
#include "player.h"
#include <string>

constexpr char SAVE_FILE[] = "rogue_save.txt";

bool saveGame(const Player& player, int roomNumber);
bool loadGame(Player& player, int& roomNumber);
bool saveExists();