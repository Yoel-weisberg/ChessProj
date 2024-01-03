#include "King.h"


/**
 @brief		Constructor - Initializes the type, location color and board (reference) of the King.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 @param		board		the board of the game
 */
King::King(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board) : Piece(type, location, color, board) {}


/**
 @brief		Checks if the trip is legal for the King.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool King::checkIfTripLegallyForPiece(const Point& dst) const
{
	if (dst == NORTH || dst == SOUTH || dst == WEST || dst == EAST || dst == NORTH_WEST || dst == NORTH_EAST || dst == SOUTH_WEST || dst == SOUTH_EAST)
	{
		return true;
	}

	return false;
}


/**
 @brief		Checks if there are pieces that block the King's trip.
 @param		dst		The destination point of the King.
 @return	false if the trip is blocked, true otherwise.
 */
bool King::checkIfPiecesInTrip(const Point& dst) const
{
	if (this->getColor().getPlayerColor() == WHITE_PLAYER)
	{
		// If there is a white piece in the destination point - then the white king cannot move into it
		if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() == WHITE_PLAYER)
		{
			return false;
		}

		return true;
	}

	if (this->getColor().getPlayerColor() == BLACK_PLAYER)
	{
		// If there is a black piece in the destination point - then the black king cannot move into it
		if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() == BLACK_PLAYER)
		{
			return false;
		}

		return true;
	}

	return false;
}


/**
 @brief		Checks if the King can perform castling.
 @param		dst		The destination point of the King.
 @return	true if the King can perform castling, false otherwise.
 */
bool King::checkForCastling(const Point& dst) const
{
	// checking if player had been moved
	if (this->_isFirstMove)
	{
		if (this->_color.getPlayerColor() == WHITE_PLAYER)
		{
			if (dst == W_KING_CASTELING_LEFT || dst == W_KING_CASTELING_RIGHT)
			{
				if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->isFirstMove())
				{
					if (Rook::checkForPiecesOnTripRook(dst, this->_location, this->_board))
					{
						return true;
					}
				}
			}
		}

		else if (this->_color.getPlayerColor() == BLACK_PLAYER)
		{
			if (dst == B_KING_CASTELING_LEFT || dst == B_KING_CASTELING_RIGHT)
			{
				if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->isFirstMove())
				{
					if (Rook::checkForPiecesOnTripRook(dst, this->_location, this->_board))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}
