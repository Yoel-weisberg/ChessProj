#include "Bishop.h"

Bishop::Bishop(const char& type, const Point& location, const Player& color)
	: Piece(type, location, color)
{
}

bool Bishop::checkIfTripLegallyForPiece(const Point& dst) const
{
	int distanceCol = std::abs(this->_location.getCol() - dst.getCol());
	int distanceRow = std::abs(this->_location.getRow() - dst.getRow());

	if (distanceCol == distanceRow)
	{
		return true;
	}
	return false;
}

bool Bishop::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
	int distance = std::abs(this->_location.getCol() - dst.getCol());
	int i = 0;

	// if the dst is above the src
	if (dst.getRow() > this->_location.getRow())
	{
		// if the dst is above ant to the right of the src
		if (dst.getCol() > this->_location.getCol())
		{
			for (i = 0; i < distance; i++)
			{
				if (board.board[this->_location.getRow() + i][this->_location.getCol() + i]->getType() != EMPTY);
			}
		}

		// if the dst is above and to the left of the src
		if (dst.getCol() < this->_location.getCol())
		{
			for (i = 0; i < distance; i++)
			{
				if (board.board[this->_location.getRow() + i][this->_location.getCol() - i]->getType() != EMPTY);
			}
		}
	}

	// if the dst is underneath the src
	if (dst.getRow() < this->_location.getRow())
	{
		// if the dst is underneath ant to the right of the src
		if (dst.getCol() > this->_location.getCol())
		{
			for (i = 0; i < distance; i++)
			{
				if (board.board[this->_location.getRow() - i][this->_location.getCol() + i]->getType() != EMPTY);
			}
		}

		// if the dst is underneath and to the left of the src
		if (dst.getCol() < this->_location.getCol())
		{
			for (i = 0; i < distance; i++)
			{
				if (board.board[this->_location.getRow() - i][this->_location.getCol() - i]->getType() != EMPTY);
			}
		}
	}
}
