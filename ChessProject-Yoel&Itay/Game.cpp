#include "Game.h"

Game::Game() : _board(&Board()), _turn(Player(W)) {}

void Game::restart()
{
	this->_board = &Board();
	this->_turn = Player(W);
}

returnCode Game::moveOnBoard(const Point& src, const Point& dst)
{
	// need to add - communication with the frontend
	returnCode res = BoardUtils::movePiece(*this->_board, this->_turn, src, dst);
	return res;
}
