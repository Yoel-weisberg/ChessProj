#pragma once

#include <string>

#define WHITE "white"
#define BLACK "black"
#define EMPTY "empty"


class Player
{
public:
	Player(const std::string& playerColor);

	std::string getPlayerColor() const;
	bool isEmpty() const;

	bool operator==(const Player& other) const;

private:
	std::string _playerColor;
};
