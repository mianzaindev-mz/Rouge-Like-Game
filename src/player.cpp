#include "player.h"
#include <iostream>

PlayerStatus getStatus(const Player& player)
{
    if      (player.health <= 0)  return PlayerStatus::Dead;
    else if (player.health <= 25) return PlayerStatus::Critical;
    else if (player.health <= 50) return PlayerStatus::Wounded;
    else if (player.health <= 75) return PlayerStatus::Hurt;
    else                         return PlayerStatus::Healthy;
}

bool isAlive(const Player& player)
{
    return player.health > 0;
}

void takeDamage(Player& player, int amount)
{
    player.health -= amount;
    if (player.health < 0)
        player.health = 0;

        if (player.health == 0)
            player.alive = false;
}

void heal(Player& player, int amount)
{
    player.health += amount;
    if (player.health > player.maxHealth)
        player.health = player.maxHealth;
}

bool hasTarget(const Player& player)
{
    return player.target != nullptr && player.target->alive;
}

void clearTarget(Player& player)
{
    player.target = nullptr;
}