#pragma once
#include "player.h"
#include "enemy.h"

void resolveCombat(Player& player, Enemy enemies[], int enemyCount,
                   const Position& newPos, bool& combatOccurred);