#include <iostream>

enum class PlayerStatus 
{
    Healthy,
    Hurt,
    Wounded,
    Critical,
    Dead
};

enum class Direction 
{
    North,
    East,
    South,
    West
};

int main() 
{
    // Engine configuration constants
    constexpr int WINDOW_WIDTH = 80;
    constexpr int WINDOW_HEIGHT = 24;
    constexpr float VERSION = 0.3f;

    // Player starting stats
    int playerHealth = 100;
    int playerMaxHealth = 100;
    int playerGold = 0;
    float playerSpeed = 1.0f;
    bool playerAlive = true;
    char playerSymbol = '@';

    Direction facingDirection = Direction::North;
    PlayerStatus currentStatus;

    //Determine Player Status
    if (playerHealth <= 0)
        currentStatus = PlayerStatus::Dead;
    else if (playerHealth <= 25)
        currentStatus = PlayerStatus::Critical;
    else if (playerHealth <= 50)
        currentStatus = PlayerStatus::Wounded;
    else if (playerHealth <= 75)
        currentStatus = PlayerStatus::Hurt;
    else
        currentStatus = PlayerStatus::Healthy;



    std::cout << "=== RogueEngine v" << VERSION << " ===" << "\n";
    std::cout << "World: " << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << "\n";
    std::cout << "\n--- Player ---\n";
    std::cout << "Symbol: " << playerSymbol << "\n";
    std::cout << "Health: " << playerHealth << "/" << playerMaxHealth << "\n";
    std::cout << "Gold: " << playerGold << "\n";
    std::cout << "Speed: " << playerSpeed << "\n";
    std::cout << "Alive: " << (playerAlive ? "Yes" : "No") << "\n";
    std::cout << "\nPress Enter to exit...\n";

    //Print Status
    std::cout << "Status: ";
    switch (currentStatus)
    {
        case PlayerStatus::Healthy:  std::cout << "Healthy\n";  break;
        case PlayerStatus::Hurt:     std::cout << "Hurt\n";     break;
        case PlayerStatus::Wounded:  std::cout << "Wounded\n";  break;
        case PlayerStatus::Critical: std::cout << "Critical\n"; break;
        case PlayerStatus::Dead:     std::cout << "Dead\n";     break;
    }

    //Print Facing Direction
    std::cout << "Facing: ";
    switch (facingDirection)
    {
        case Direction::North: std::cout << "North\n"; break;
        case Direction::East:  std::cout << "East\n";  break;
        case Direction::South: std::cout << "South\n"; break;
        case Direction::West:  std::cout << "West\n";  break;
    }

    std::cin.get();
    return 0;
}