#include "player.h"
#include "enemy.h"

Player::Player()
    : health(100), maxHealth(100), gold(0),
    row(3), col(2), room(1), symbol('@'),
    alive(true), target(nullptr)
{
}

int    Player::getHealth()    const { return health; }
int    Player::getMaxHealth() const { return maxHealth; }
int    Player::getGold()      const { return gold; }
int    Player::getRow()       const { return row; }
int    Player::getCol()       const { return col; }
int    Player::getRoom()      const { return room; }
char   Player::getSymbol()    const { return symbol; }
bool   Player::isAlive()      const { return alive; }
Enemy* Player::getTarget()    const { return target; }

bool Player::hasTarget() const
{
    return target != nullptr && target->alive;
}

PlayerStatus Player::getStatus() const
{
    if (health <= 0)                     return PlayerStatus::Dead;
    if (health <= maxHealth * 0.25f)     return PlayerStatus::Critical;
    if (health <= maxHealth * 0.50f)     return PlayerStatus::Wounded;
    if (health <= maxHealth * 0.75f)     return PlayerStatus::Hurt;
    return PlayerStatus::Healthy;
}

void Player::takeDamage(int amount)
{
    if (!alive || amount <= 0) return;
    health -= amount;
    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}

void Player::heal(int amount)
{
    if (!alive || amount <= 0) return;
    health += amount;
    if (health > maxHealth)
        health = maxHealth;
}

void Player::addGold(int amount)
{
    if (amount > 0)
        gold += amount;
}

void Player::moveTo(int newRow, int newCol)
{
    row = newRow;
    col = newCol;
}

void Player::setRoom(int roomNumber)
{
    room = roomNumber;
}

void Player::setTarget(Enemy* enemy)
{
    target = enemy;
}

void Player::clearTarget()
{
    target = nullptr;
}