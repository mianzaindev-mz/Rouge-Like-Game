#include "enemy.h"
#include <iostream>

Enemy createGoblin(int row, int col)
{
    Enemy e;
    e.name         = "Goblin";
    e.health       = 40;
    e.maxHealth    = 40;
    e.attackDamage = 6;
    e.symbol       = 'g';
    e.type         = EnemyType::Goblin;
    e.pos.row      = row;
    e.pos.col      = col;
    return e;
}

Enemy createTroll(int row, int col)
{
    Enemy e;
    e.name         = "Troll";
    e.health       = 120;
    e.maxHealth    = 120;
    e.attackDamage = 15;
    e.symbol       = 'T';
    e.type         = EnemyType::Troll;
    e.pos.row      = row;
    e.pos.col      = col;
    return e;
}

Enemy createSkeleton(int row, int col)
{
    Enemy e;
    e.name         = "Skeleton";
    e.health       = 30;
    e.maxHealth    = 30;
    e.attackDamage = 8;
    e.symbol       = 'S';
    e.type         = EnemyType::Skeleton;
    e.pos.row      = row;
    e.pos.col      = col;
    return e;
}

void damageEnemy(Enemy& enemy, int amount)
{
    if (!enemy.alive) return;
    enemy.health -= amount;
    if (enemy.health <= 0)
    {
        enemy.health = 0;
        enemy.alive  = false;
    }
}

bool isEnemyAlive(const Enemy& enemy)
{
    return enemy.alive;
}

void printEnemy(const Enemy& enemy)
{
    std::cout << "[" << enemy.symbol << "] "
              << enemy.name
              << " HP: "  << enemy.health << "/" << enemy.maxHealth
              << " ATK: " << enemy.attackDamage
              << (enemy.alive ? " (Alive)" : " (Dead)")
              << "\n";
}

bool isAdjacent(const Position& a, const Position& b)
{
    int rowDiff = a.row - b.row;
    int colDiff = a.col - b.col;
    if (rowDiff < 0) rowDiff = -rowDiff;
    if (colDiff < 0) colDiff = -colDiff;
    return (rowDiff <= 1 && colDiff <= 1) && !(rowDiff == 0 && colDiff == 0);
}