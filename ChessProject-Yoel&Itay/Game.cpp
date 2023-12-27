#include "Game.h"


Game::Game() : _board(Board()), _turn(Player(W)) {}


Board& Game::getBoard()
{
	return this->_board;
}


/**
 @brief		Switches the turn in the game.
 @return	void
 */
void Game::switchTurn()
{
	if (this->_turn.getPlayerColor() == W)
	{
		this->_turn.setColor(B);
	}
	else
	{
		this->_turn.setColor(W);
	}
}


/**
 @brief		Restarts the game by resetting the board and the turn.
 @return	void
 */
void Game::restart()
{
	this->_board = Board();
	this->_turn = Player(W);
}


/**
 @brief		Moves a piece on the game board.
 @return	The returnCode of the move.
 */
returnCode Game::moveOnBoard(const Point& src, const Point& dst)
{
	returnCode res = BoardUtils::movePiece(this->_board, this->_turn, src, dst);
	return res;
}
