#include <iostream>

int main() 
{
    // Engine configuration constants
    constexpr int WINDOW_WIDTH = 80;
    constexpr int WINDOW_HEIGHT = 24;
    constexpr float VERSION = 0.2f;

    // Player starting stats
    int playerHealth = 100;
    int playerMaxHealth = 100;
    int playerGold = 0;
    float playerSpeed = 1.0f;
    bool playerAlive = true;
    char playerSymbol = '@';

    std::cout << "=== RogueEngine v" << VERSION << " ===" << "\n";
    std::cout << "World: " << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << "\n";
    std::cout << "\n--- Player ---\n";
    std::cout << "Symbol: " << playerSymbol << "\n";
    std::cout << "Health: " << playerHealth << "/" << playerMaxHealth << "\n";
    std::cout << "Gold: " << playerGold << "\n";
    std::cout << "Speed: " << playerSpeed << "\n";
    std::cout << "Alive: " << (playerAlive ? "Yes" : "No") << "\n";
    std::cout << "\nPress Enter to exit...\n";
    std::cin.get();
    return 0;
}