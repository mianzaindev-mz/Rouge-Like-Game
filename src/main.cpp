#include <iostream>
#include "player.h"
#include "renderer.h"
#include "map.h"
#include "enemy.h"
#include "saveload.h"
#include "combat.h"

enum class GameState { Running, PlayerDead, PlayerQuit };

int main()
{
    constexpr int   WINDOW_WIDTH  = 80;
    constexpr int   WINDOW_HEIGHT = 24;
    constexpr float VERSION       = 0.12f;

    // Initialize player
    Player player;

    // Initialize room
    Room currentRoom;
    initRoom(currentRoom, "Entrance Hall");
    setTile(currentRoom, 1, 5, static_cast<int>(TileType::Chest));
    setTile(currentRoom, 6, 6, static_cast<int>(TileType::Stairs));
    setTile(currentRoom, 0, 6, static_cast<int>(TileType::Door));

    // Load save if exists
    if (saveExists())
    {
        std::cout << "Save file found. Load game? [Y/N]: ";
        char choice;
        std::cin >> choice;
        std::cout << "\n";
        if (choice == 'y' || choice == 'Y')
            loadGame(player, currentRoom.number);
    }

    // Flood reveal from player starting position
    floodReveal(currentRoom, player.pos.row, player.pos.col);

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
                saveGame(player, currentRoom.number);
                std::cout << "You rest. HP restored.\n\n";
                break;
            case 'q': case 'Q':
                saveGame(player, currentRoom.number);
                gameState = GameState::PlayerQuit;
                break;
            default:
                std::cout << "Unknown command.\n\n";
                break;
        }

        // Combat and movement
        bool combatOccurred = false;
        resolveCombat(player, enemies, MAX_ENEMIES, newPos, combatOccurred);

        if (!combatOccurred &&
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