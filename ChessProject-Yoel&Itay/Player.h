#pragma once

#include <string>

#define WHITE_PLAYER "white"
#define BLACK_PLAYER "black"
#define EMPTY_PLAYER "empty"


class Player
{
public:
	Player(const std::string& playerColor);

	std::string getPlayerColor() const;
	bool isEmpty() const;
	void setColor(const std::string& color);

	bool operator==(const Player& other) const;

private:
	std::string _playerColor;
};
