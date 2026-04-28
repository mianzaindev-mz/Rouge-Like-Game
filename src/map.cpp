#include "map.h"

void initRoom(Room& room, const std::string& name)
{
    room.name = name;
    for (int r = 0; r < MAP_HEIGHT; ++r)
    {
        for (int c = 0; c < MAP_WIDTH; ++c)
        {
            if (r == 0 || r == MAP_HEIGHT - 1 || c == 0 || c == MAP_WIDTH - 1)
                room.tiles[r][c] = static_cast<int>(TileType::Wall);
            else
                room.tiles[r][c] = UNEXPLORED;
        }
    }
}

void setTile(Room& room, int row, int col, int tileType)
{
    if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_WIDTH)
        return;
    room.tiles[row][col] = tileType;
}

int getTile(const Room& room, int row, int col)
{
    if (row < 0 || row >= MAP_HEIGHT || col < 0 || col >= MAP_WIDTH)
        return static_cast<int>(TileType::Wall);
    return room.tiles[row][col];
}

bool isWalkable(const Room& room, int row, int col)
{
    int tile = getTile(room, row, col);    // ← fixed
    return tile == static_cast<int>(TileType::Floor) ||
           tile == static_cast<int>(TileType::Door)  ||
           tile == static_cast<int>(TileType::Chest) ||
           tile == static_cast<int>(TileType::Stairs);
}

void floodReveal(Room& room, int row, int col)
{
    if (row < 0 || row >= MAP_HEIGHT) return;
    if (col < 0 || col >= MAP_WIDTH)  return;

    int tile = getTile(room, row, col);
    if (tile == static_cast<int>(TileType::Wall)) return;
    if (tile != UNEXPLORED)                        return;

    setTile(room, row, col, static_cast<int>(TileType::Floor));

    floodReveal(room, row - 1, col);
    floodReveal(room, row + 1, col);
    floodReveal(room, row, col - 1);
    floodReveal(room, row, col + 1);
}