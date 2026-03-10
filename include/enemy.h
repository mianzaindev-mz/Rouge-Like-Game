#pragma once
#include <string>
#include "map.h"

enum class EnemyType
 {
    Goblin,
    Troll,
    Skeleton,
    Dragon
};

struct Position 
{
    int row = 0;
    int col = 0;
};

struct Enemy
{
    std::string name = "Unknown";
    int         health = 50;
    int         maxHealth = 50;
    int         attackDamage = 10;
    char        symbol = 'e';
    bool        alive = true;
    EnemyType   type = EnemyType::Goblin;
    Position    pos;
};

//Factory Function
Enemy   createGoblin(int row, int col);
Enemy   createTroll(int row, int col);
Enemy   createSkeleton(int row, int col);

//Enemy Operations
void   damageEnemy(Enemy& enemy, int amount);
bool   isEnemyAlive(const Enemy& enemy);
void   printEnemy(const Enemy& enemy);
bool   isAdjacent(const Position& a, const Position& b);

