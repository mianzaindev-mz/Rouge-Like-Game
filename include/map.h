#pragma once
#include <string>

constexpr int MAP_WIDTH  = 12;
constexpr int MAP_HEIGHT = 8;

// Tile type identifiers
enum class TileType
{
    Floor,
    Wall,
    Door,
    Chest,
    Stairs
};

// A single dungeon room
struct Room
{
    int         tiles[MAP_HEIGHT][MAP_WIDTH];
    std::string name;
    bool        visited;
    int         enemyCount;
};

// Functions
void        initRoom(Room& room, const std::string& name);
void        setTile(Room& room, int row, int col, int tileType);
int         getTile(const Room& room, int row, int col);
bool        isWalkable(const Room& room, int row, int col);