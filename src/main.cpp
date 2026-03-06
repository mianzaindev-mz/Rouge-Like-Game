#include <iostream>

enum class PlayerStatus { Healthy, Hurt, Wounded, Critical, Dead };
enum class Direction    { North, South, East, West };
enum class GameState    { Running, PlayerDead, PlayerQuit };

int main()
{
    constexpr int   WINDOW_WIDTH  = 80;
    constexpr int   WINDOW_HEIGHT = 24;
    constexpr float VERSION       = 0.4f;

    int   playerHealth    = 100;
    int   playerMaxHealth = 100;
    int   playerGold      = 0;
    float playerSpeed     = 1.0f;
    bool  playerAlive     = true;
    char  playerSymbol    = '@';
    int   currentRoom     = 1;

    GameState gameState = GameState::Running;

    std::cout << "=== RogueEngine v" << VERSION << " ===\n";
    std::cout << "World: " << WINDOW_WIDTH << "x" << WINDOW_HEIGHT << "\n\n";

    while (gameState == GameState::Running)
    {
        // Determine status
        PlayerStatus status;
        if      (playerHealth <= 0)  status = PlayerStatus::Dead;
        else if (playerHealth <= 25) status = PlayerStatus::Critical;
        else if (playerHealth <= 50) status = PlayerStatus::Wounded;
        else if (playerHealth <= 75) status = PlayerStatus::Hurt;
        else                         status = PlayerStatus::Healthy;

        // Render
        std::cout << "--- Room " << currentRoom << " ---\n";
        std::cout << playerSymbol << "  HP: " << playerHealth
                  << "/" << playerMaxHealth
                  << "  Gold: " << playerGold << "\n";

        std::cout << "Status: ";
        switch (status)
        {
            case PlayerStatus::Healthy:  std::cout << "Healthy\n";  break;
            case PlayerStatus::Hurt:     std::cout << "Hurt\n";     break;
            case PlayerStatus::Wounded:  std::cout << "Wounded\n";  break;
            case PlayerStatus::Critical: std::cout << "Critical!\n"; break;
            case PlayerStatus::Dead:     std::cout << "Dead\n";     break;
        }

        std::cout << "\n1) Move North  2) Move South  "
                  << "3) Rest (+20 HP)  4) Quit\n> ";

        // Input
        int choice = 0;
        std::cin >> choice;

        // Update
        switch (choice)
        {
            case 1:
                ++currentRoom;
                playerHealth -= 10;
                playerGold   += 5;
                std::cout << "You move North. Found 5 gold.\n\n";
                break;
            case 2:
                if (currentRoom > 1)
                {
                    --currentRoom;
                    std::cout << "You move South.\n\n";
                }
                else
                    std::cout << "You cannot go further South.\n\n";
                break;
            case 3:
                playerHealth += 20;
                if (playerHealth > playerMaxHealth)
                    playerHealth = playerMaxHealth;
                std::cout << "You rest. HP restored.\n\n";
                break;
            case 4:
                gameState = GameState::PlayerQuit;
                break;
            default:
                std::cout << "Invalid choice.\n\n";
                break;
        }

        if (playerHealth <= 0)
            gameState = GameState::PlayerDead;
    }

    // End screen
    switch (gameState)
    {
        case GameState::PlayerDead:
            std::cout << "=== YOU DIED === Reached room " << currentRoom << "\n";
            break;
        case GameState::PlayerQuit:
            std::cout << "=== QUIT === Gold collected: " << playerGold << "\n";
            break;
        default:
            break;
    }

    return 0;
}