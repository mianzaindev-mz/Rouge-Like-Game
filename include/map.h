#pragma once
#include <string>

constexpr int MAP_WIDTH = 12;
constexpr int MAP_HEIGHT = 8;
constexpr int UNEXPLORED = 5;

enum class TileType
{
    Floor,
    Wall,
    Door,
    Chest,
    Stairs
};

struct Room
{
    int         tiles[MAP_HEIGHT][MAP_WIDTH] = {};    // zero-initializes entire array
    std::string name = "Unknown";
    bool        visited = false;
    int         enemyCount = 0;
    int         number = 1;
};

void initRoom(Room& room, const std::string& name);
void setTile(Room& room, int row, int col, int tileType);
int  getTile(const Room& room, int row, int col);
bool isWalkable(const Room& room, int row, int col);
void floodReveal(Room& room, int row, int col);