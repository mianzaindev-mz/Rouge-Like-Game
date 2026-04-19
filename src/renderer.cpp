#include "renderer.h"
#include "player.h"
#include "enemy.h"
#include <iostream>

void renderHeader(float version, int width, int height)
{
    std::cout << "=== RogueEngine v" << version << " ===\n";
    std::cout << "World: " << width << "x" << height << "\n\n";
}

void renderPlayer(const Player& player)
{
    std::cout << player.getSymbol()
        << "  HP: " << player.getHealth()
        << "/" << player.getMaxHealth()
        << "  Gold: " << player.getGold()
        << "  Room: " << player.getRoom();

    if (player.hasTarget())
        std::cout << "  TARGET: " << player.getTarget()->name
        << " HP:" << player.getTarget()->health;

    std::cout << "\n";
}

void renderStatusBar(const Player& player)
{
    std::cout << "Status: ";
    switch (player.getStatus())
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
}

void renderMap(const Room& room, const Player& player,
    const Enemy enemies[], int enemyCount)
{
    std::cout << "\n=== " << room.name << " ===\n";

    for (int row = 0; row < MAP_HEIGHT; ++row)
    {
        for (int col = 0; col < MAP_WIDTH; ++col)
        {
            if (row == player.getRow() && col == player.getCol())
            {
                std::cout << "@ ";
                continue;
            }

            bool enemyDrawn = false;
            for (int i = 0; i < enemyCount; ++i)
            {
                if (enemies[i].alive &&
                    row == enemies[i].pos.row &&
                    col == enemies[i].pos.col)
                {
                    std::cout << enemies[i].symbol << " ";
                    enemyDrawn = true;
                    break;
                }
            }
            if (enemyDrawn) continue;

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
            case UNEXPLORED:
                std::cout << "? "; break;
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