#include "Bishop.h"

Bishop::Bishop(const char& type, const Point& location, const Player& color)
	: Piece(type, location, color)
{
}

bool Bishop::checkIfTripLegallyForPiece(const Point& dst) const
{
	return Bishop::checkIfTripLegallyForPieceBishop(this->_location, dst);
}

bool Bishop::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
	return Bishop::checkForPiecesOnTripBishop(this->_location, dst, board);
}

bool Bishop::checkForPiecesOnTripBishop(const Point& src, const Point& dst, const Board& board)
{
	int distance = std::abs(src.getCol() - dst.getCol());
	int i = 0;

	// if the dst is above the src
	if (dst.getRow() > src.getRow())
	{
		// if the dst is above ant to the right of the src
		if (dst.getCol() > src.getCol())
		{
			for (i = 1; i < distance; i++)
			{
				if (board.board[src.getRow() + i][src.getCol() + i]->getType() != EMPTY)
				{
					return false;
				}
			}
		}

		// if the dst is above and to the left of the src
		if (dst.getCol() < src.getCol())
		{
			for (i = 1; i < distance; i++)
			{
				if (board.board[src.getRow() + i][src.getCol() - i]->getType() != EMPTY)
				{
					return false;
				}
			}
		}
	}

	// if the dst is underneath the src
	if (dst.getRow() < src.getRow())
	{
		// if the dst is underneath ant to the right of the src
		if (dst.getCol() > src.getCol())
		{
			for (i = 1; i < distance; i++)
			{
				if (board.board[src.getRow() - i][src.getCol() + i]->getType() != EMPTY)
				{
					return false;
				}
			}
		}

		// if the dst is underneath and to the left of the src
		if (dst.getCol() < src.getCol())
		{
			for (i = 1; i < distance; i++)
			{
				if (board.board[src.getRow() - i][src.getCol() - i]->getType() != EMPTY)
				{
					return false;
				}
			}
		}

		return true;
	}
}

bool Bishop::checkIfTripLegallyForPieceBishop(const Point& src ,const Point& dst)
{
	int distanceCol = std::abs(src.getCol() - dst.getCol());
	int distanceRow = std::abs(src.getRow() - dst.getRow());

	if (distanceCol == distanceRow)
	{
		return true;
	}
	return false;
}
