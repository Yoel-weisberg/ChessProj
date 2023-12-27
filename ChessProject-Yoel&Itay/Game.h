#pragma once
#include "Board.h"
#include "Player.h"
class Game
{
public:
	Game();

	Board& getBoard();
	void switchTurn();

	void restart();
	returnCode moveOnBoard(const Point& src, const Point& dst);


private:
	Board _board;
	Player _turn;
};
