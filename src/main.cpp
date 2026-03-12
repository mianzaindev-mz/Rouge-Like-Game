#include <iostream>
#include "player.h"
#include "renderer.h"
#include "map.h"
#include "enemy.h"

enum class GameState { Running, PlayerDead, PlayerQuit };

int main()
{
    constexpr int   WINDOW_WIDTH  = 80;
    constexpr int   WINDOW_HEIGHT = 24;
    constexpr float VERSION       = 0.8f;

    // Initialize player
    Player player;

    // Initialize room
    Room currentRoom;
    initRoom(currentRoom, "Entrance Hall");
    setTile(currentRoom, 1, 5, static_cast<int>(TileType::Chest));
    setTile(currentRoom, 6, 6, static_cast<int>(TileType::Stairs));
    setTile(currentRoom, 0, 6, static_cast<int>(TileType::Door));

    // Initialize enemies
    constexpr int MAX_ENEMIES = 3;
    Enemy enemies[MAX_ENEMIES];
    enemies[0] = createGoblin(2, 8);
    enemies[1] = createSkeleton(5, 3);
    enemies[2] = createTroll(4, 9);

    GameState gameState = GameState::Running;

    renderHeader(VERSION, WINDOW_WIDTH, WINDOW_HEIGHT);

    while (gameState == GameState::Running)
    {
        // Render
        renderMap(currentRoom, player, enemies, MAX_ENEMIES);
        renderPlayer(player);
        renderStatusBar(player);
        renderEnemies(enemies, MAX_ENEMIES);

        std::cout << "\nMove: [W]North [S]South [A]West [D]East"
                  << "  [R]est  [Q]uit\n> ";

        // Input
        char input = ' ';
        std::cin >> input;
        std::cout << "\n";

        // Calculate new position
        Position newPos = player.pos;

        switch (input)
        {
            case 'w': case 'W': --newPos.row; break;
            case 's': case 'S': ++newPos.row; break;
            case 'a': case 'A': --newPos.col; break;
            case 'd': case 'D': ++newPos.col; break;
            case 'r': case 'R':
                heal(player, 20);
                std::cout << "You rest. HP restored.\n\n";
                break;
            case 'q': case 'Q':
                gameState = GameState::PlayerQuit;
                break;
            default:
                std::cout << "Unknown command.\n\n";
                break;
        }

        // Check for enemy at new position
        bool combatOccurred = false;
        for (int i = 0; i < MAX_ENEMIES; ++i)
        {
            if (enemies[i].alive &&
                enemies[i].pos.row == newPos.row &&
                enemies[i].pos.col == newPos.col)
            {
                player.target = &enemies[i];    // point to the enemy
                combatOccurred = true;
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
                player.gold   += 10;
                player.target  = nullptr;
            }
            else
            {
                takeDamage(player, player.target->attackDamage);
                std::cout << player.target->name << " retaliates for "
                          << player.target->attackDamage << " damage!\n\n";
            }
        }
        else if (!combatOccurred &&
                 isWalkable(currentRoom, newPos.row, newPos.col))
        {
            player.pos = newPos;

            int tile = getTile(currentRoom, player.pos.row, player.pos.col);
            if (tile == static_cast<int>(TileType::Chest))
            {
                player.gold += 25;
                std::cout << "Chest opened! +25 gold.\n\n";
                setTile(currentRoom, player.pos.row,
                        player.pos.col,
                        static_cast<int>(TileType::Floor));
            }
            else if (tile == static_cast<int>(TileType::Stairs))
            {
                std::cout << "Stairs lead deeper...\n\n";
            }
        }
        else if (!combatOccurred)
        {
            std::cout << "Blocked.\n\n";
        }

        if (!isAlive(player))
            gameState = GameState::PlayerDead;
    }

    // End screen
    switch (gameState)
    {
        case GameState::PlayerDead:
            std::cout << "=== YOU DIED === Gold: "
                      << player.gold << "\n";
            break;
        case GameState::PlayerQuit:
            std::cout << "=== QUIT === Gold: "
                      << player.gold << "\n";
            break;
        default:
            break;
    }

    return 0;
}