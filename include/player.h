#pragma once
#include <string>

enum class PlayerStatus { Healthy, Hurt, Wounded, Critical, Dead };

struct Enemy;    // forward declaration — avoid circular include

class Player
{
public:
    Player();

    // Getters
    int          getHealth()    const;
    int          getMaxHealth() const;
    int          getGold()      const;
    int          getRow()       const;
    int          getCol()       const;
    int          getRoom()      const;
    char         getSymbol()    const;
    bool         isAlive()      const;
    bool         hasTarget()    const;
    PlayerStatus getStatus()    const;
    Enemy* getTarget()    const;

    // Actions
    void takeDamage(int amount);
    void heal(int amount);
    void addGold(int amount);
    void moveTo(int row, int col);
    void setRoom(int roomNumber);
    void setTarget(Enemy* enemy);
    void clearTarget();

private:
    int    health;
    int    maxHealth;
    int    gold;
    int    row;
    int    col;
    int    room;
    char   symbol;
    bool   alive;
    Enemy* target;
};