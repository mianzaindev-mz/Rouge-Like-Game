#pragma once
#include <string>
#include "enemy.h"

// Player Status Options
enum class PlayerStatus { Healthy, Hurt, Wounded, Critical, Dead };

//Player data - all stats one player
struct Player
{
    int health              = 100;
    int maxHealth           = 100;
    int gold                = 0;
    float speed             = 1.0f;
    bool alive              = true;
    char symbol             = '@';
    int room                = 1;
    Position pos        = {3, 2}; //Default Starting Position
};

// Function declarations 
PlayerStatus getStatus(const Player& player);
bool         isAlive(const Player& player);
void         takeDamage(Player& player, int amount);
void         heal(Player& player, int amount);