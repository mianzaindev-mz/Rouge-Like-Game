#include "saveload.h"
#include <fstream>
#include <iostream>
#include <string>

bool saveGame(const Player& player, int roomNumber)
{
    std::ofstream file(SAVE_FILE);
    if (!file.is_open())
    {
        std::cout << "Failed to save game.\n";
        return false;
    }

    file << "health="    << player.health    << "\n";
    file << "maxHealth=" << player.maxHealth << "\n";
    file << "gold="      << player.gold      << "\n";
    file << "room="      << roomNumber       << "\n";
    file << "posRow="    << player.pos.row   << "\n";
    file << "posCol="    << player.pos.col   << "\n";

    file.close();
    std::cout << "Game saved.\n";
    return true;
}

bool loadGame(Player& player, int& roomNumber)
{
    std::ifstream file(SAVE_FILE);
    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line))
    {
        int sep = static_cast<int>(line.find('='));
        if (sep == static_cast<int>(std::string::npos)) continue;

        std::string key   = line.substr(0, sep);
        std::string value = line.substr(sep + 1);

        if      (key == "health")    player.health    = std::stoi(value);
        else if (key == "maxHealth") player.maxHealth = std::stoi(value);
        else if (key == "gold")      player.gold      = std::stoi(value);
        else if (key == "room")      roomNumber       = std::stoi(value);
        else if (key == "posRow")    player.pos.row   = std::stoi(value);
        else if (key == "posCol")    player.pos.col   = std::stoi(value);
    }

    file.close();
    std::cout << "Game loaded.\n";
    return true;
}

bool saveExists()
{
    std::ifstream file(SAVE_FILE);
    return file.is_open();
}