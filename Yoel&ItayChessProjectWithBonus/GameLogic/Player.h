#pragma once

#include <string>
#include "Constants.h"


class Player
{
public:
	Player(const std::string& playerColor);

	std::string getPlayerColor() const;
	void setColor(const std::string& color);

	bool operator==(const Player& other) const;

private:
	std::string _playerColor;
};
