#include "Player.h"


/**
 @brief		Constructor - Initializes the color of the player.
 @param		playerColor		The color of the player.
 */
Player::Player(const std::string& playerColor) : _playerColor(playerColor) {}


/**
 @brief		Returns the color of the player.
 @return	The color of the player.
 */
std::string Player::getPlayerColor() const
{
	return this->_playerColor;
}


/**
 @brief		Returns true if the player is empty.
 @return	True if the player is empty, false otherwise.
 */
bool Player::isEmpty() const
{
	return this->_playerColor == EMPTY;
}

void Player::setColor(const std::string& color)
{
	this->_playerColor = color;
}


/**
 @brief		Checks if the calling player is equal to another player (by color).
 @param		other		Another Player object to compare to.
 @return	True if the players are equal, false otherwise.
 */
bool Player::operator==(const Player& other) const
{
	return this->_playerColor == other._playerColor;
}
