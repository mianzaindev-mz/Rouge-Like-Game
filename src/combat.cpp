#include "combat.h"
#include <iostream>

void resolveCombat(Player& player, Enemy enemies[], int enemyCount,
    const Position& newPos, bool& combatOccurred)
{
    for (int i = 0; i < enemyCount; ++i)
    {
        if (enemies[i].alive &&
            enemies[i].pos.row == newPos.row &&
            enemies[i].pos.col == newPos.col)
        {
            player.setTarget(&enemies[i]);
            combatOccurred = true;
            break;
        }
    }

    if (player.hasTarget())
    {
        Enemy* t = player.getTarget();
        std::cout << "Attacking " << t->name << "!\n";
        damageEnemy(*t, 25);

        if (!isEnemyAlive(*t))
        {
            std::cout << t->name << " defeated! +10 gold\n\n";
            player.addGold(10);
            player.clearTarget();
        }
        else
        {
            player.takeDamage(t->attackDamage);
            std::cout << t->name << " retaliates for "
                << t->attackDamage << " damage!\n\n";
        }
    }
}