#pragma once
#include "enemy.h"
#include <string>

enum class PlayerStatus { Healthy, Hurt, Wounded, Critical, Dead };

struct Player
{
    int     health    = 100;
    int     maxHealth = 100;
    int     gold      = 0;
    float   speed     = 1.0f;
    bool    alive     = true;
    char    symbol    = '@';
    int     room      = 1;
    Position pos      = {3, 2};
    Enemy*  target    = nullptr;    // ← pointer to current combat target
};

PlayerStatus getStatus(const Player& player);
bool         isAlive(const Player& player);
void         takeDamage(Player& player, int amount);
void         heal(Player& player, int amount);
bool         hasTarget(const Player& player);
void         clearTarget(Player& player);