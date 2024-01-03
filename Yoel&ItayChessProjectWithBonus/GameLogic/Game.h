#pragma once

#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Empty.h"

#include "BoardUtils.h"
#include "Constants.h"
#include "Player.h"


class Game
{
public:
	Game();
	Game(const std::vector <Piece*>& board);
	~Game();

	std::vector<Piece*> getBoard() const;
	Player getTurn() const;
	void changeTurn(const Player turn);
	void switchTurn();
	char* returnBoardString() const;

	returnCode moveOnBoard(const Point& src, const Point& dst);

private:
	std::vector <Piece*> _board;
	Player _turn;
};
