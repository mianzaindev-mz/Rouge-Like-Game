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

    file << "health=" << player.getHealth() << "\n";
    file << "maxHealth=" << player.getMaxHealth() << "\n";
    file << "gold=" << player.getGold() << "\n";
    file << "room=" << roomNumber << "\n";
    file << "posRow=" << player.getRow() << "\n";
    file << "posCol=" << player.getCol() << "\n";

    file.close();
    std::cout << "Game saved.\n";
    return true;
}

bool loadGame(Player& player, int& roomNumber)
{
    std::ifstream file(SAVE_FILE);
    if (!file.is_open()) return false;

    std::string line;
    int loadHealth = player.getHealth();
    int loadGold = 0;
    int loadRow = player.getRow();
    int loadCol = player.getCol();

    while (std::getline(file, line))
    {
        int sep = static_cast<int>(line.find('='));
        if (sep == static_cast<int>(std::string::npos)) continue;

        std::string key = line.substr(0, sep);
        std::string value = line.substr(sep + 1);

        if (key == "health")  loadHealth = std::stoi(value);
        else if (key == "gold")    loadGold = std::stoi(value);
        else if (key == "room")    roomNumber = std::stoi(value);
        else if (key == "posRow")  loadRow = std::stoi(value);
        else if (key == "posCol")  loadCol = std::stoi(value);
    }

    int damage = player.getHealth() - loadHealth;
    if (damage > 0) player.takeDamage(damage);
    player.addGold(loadGold);
    player.moveTo(loadRow, loadCol);
    player.setRoom(roomNumber);

    file.close();
    std::cout << "Game loaded.\n";
    return true;
}

bool saveExists()
{
    std::ifstream file(SAVE_FILE);
    return file.is_open();
}