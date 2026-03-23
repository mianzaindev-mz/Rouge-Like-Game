#include "combat.h"
#include "saveload.h"
#include <iostream>

void resolveCombat(Player& player, Enemy enemies[], int enemyCount,
                   const Position& newPos, bool& combatOccurred)
{
    // Check for enemy at new position
    for (int i = 0; i < enemyCount; ++i)
    {
        if (enemies[i].alive &&
            enemies[i].pos.row == newPos.row &&
            enemies[i].pos.col == newPos.col)
        {
            player.target    = &enemies[i];
            combatOccurred   = true;
            break;
        }
    }

    // Resolve combat if target exists
    if (hasTarget(player))
    {
        std::cout << "Attacking " << player.target->name << "!\n";
        damageEnemy(*player.target, 25);

        if (!isEnemyAlive(*player.target))
        {
            std::cout << player.target->name
                      << " defeated! +10 gold\n\n";
            player.gold += 10;
            clearTarget(player);
        }
        else
        {
            takeDamage(player, player.target->attackDamage);
            std::cout << player.target->name << " retaliates for "
                      << player.target->attackDamage << " damage!\n\n";
        }
    }
}