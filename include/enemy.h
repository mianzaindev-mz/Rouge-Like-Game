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
    EnemyType   typ = EnemyType::Goblin;
    Position    pos;
};

//Factory Function
Enemy   creatGoblin(int row, int col);
Enemy   creatTroll(int row, int col);
Enemy   creatSkeleton(int row, int col);

//Enemy Operations
void   damageEvent(Enemy& enemy, int amount);
bool   isEnemyAlive(const Enemy& enemy);
void   printEnemy(const Enemy& enemy);
bool   isAdjacent(const Enemy& enemy, const Position& b);

