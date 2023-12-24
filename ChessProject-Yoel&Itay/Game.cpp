#include "Game.h"

void Game::restart()
{
	this->_board = &Board();
	this->_turn = Player(W);
}

returnCode Game::moveOnBoard(const Point& src, const Point& dst)
{
	returnCode res = BoardUtils::movePiece(*this->_board, this->_turn, src, dst);
	return res;
}
