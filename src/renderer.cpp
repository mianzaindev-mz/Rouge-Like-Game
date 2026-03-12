#include "renderer.h"
#include "player.h"
#include "enemy.h"
#include <iostream>

void renderHeader(float version, int width, int height)
{
    std::cout << "=== RogueEngine v" << version << " ===\n";
    std::cout << "World: " << width << "x" << height << "\n\n";
}

void renderStatusBar(const Player& player)
{
    std::cout << "Status: ";

    switch (getStatus(player))
    {
        case PlayerStatus::Healthy:  std::cout << "Healthy\n";   break;
        case PlayerStatus::Hurt:     std::cout << "Hurt\n";      break;
        case PlayerStatus::Wounded:  std::cout << "Wounded\n";   break;
        case PlayerStatus::Critical: std::cout << "Critical!\n"; break;
        case PlayerStatus::Dead:     std::cout << "Dead\n";      break;
    }
}

void renderMenu()
{
    std::cout << "\nMove: [W]North [S]South [A]West [D]East"
              << "  [R]est  [Q]uit\n> ";
}

void renderRoom(int roomNumber)
{
    std::cout << "\n--- Room " << roomNumber << " ---\n";

    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            if (row == 0 || row == 4 || col == 0 || col == 4)
                std::cout << "# ";
            else
                std::cout << ". ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void renderMap(const Room& room, const Player& player,
               const Enemy enemies[], int enemyCount)
{
    std::cout << "\n=== " << room.name << " ===\n";

    for (int row = 0; row < MAP_HEIGHT; ++row)
    {
        for (int col = 0; col < MAP_WIDTH; ++col)
        {
            // Draw player position
            if (row == player.pos.row && col == player.pos.col)
            {
                std::cout << "@ ";
                continue;
            }
            // Draw alive enemies
            bool enemyDrawn = false;
            for (int i = 0; i < enemyCount; ++i)
            {
                if (enemies[i].alive &&
                    row == enemies[i].pos.row && col == enemies[i].pos.col)
                {
                    std::cout << enemies[i].symbol << " ";
                    enemyDrawn = true;
                    break;
                }
            }
            if (enemyDrawn) continue;

            //Draw Tiles
            switch (room.tiles[row][col])
            {
                case static_cast<int>(TileType::Floor):
                    std::cout << ". "; break;
                case static_cast<int>(TileType::Wall):
                    std::cout << "# "; break;
                case static_cast<int>(TileType::Door):
                    std::cout << "D "; break;
                case static_cast<int>(TileType::Chest):
                    std::cout << "C "; break;
                case static_cast<int>(TileType::Stairs):
                    std::cout << "S "; break;
                default:
                    std::cout << "? "; break;
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void renderEnemies(const Enemy enemies[], int enemyCount)
{
    std::cout << "--- Enemies ---\n";
    bool anyAlive = false;
    for (int i = 0; i < enemyCount; ++i)
    {
        if (enemies[i].alive)
        {
            printEnemy(enemies[i]);
            anyAlive = true;
        }
    }
    if (!anyAlive)
        std::cout << "No enemies remain.\n";
}

void renderPlayer(const Player& player)
{
    std::cout << player.symbol
              << "  HP: "   << player.health << "/" << player.maxHealth
              << "  Gold: " << player.gold
              << "  Room: " << player.room;

    if (hasTarget(player))
        std::cout << "  TARGET: " << player.target->name
                  << " HP:" << player.target->health;

    std::cout << "\n";
}