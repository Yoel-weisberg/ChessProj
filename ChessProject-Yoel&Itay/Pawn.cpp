#include "Pawn.h"


/**
 @brief		Constructor - Initializes the type, location color, board (reference) and the "first move flag" of the Pawn.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Pawn::Pawn(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board) : Piece(type, location, color, board), _isFirstMove(true) {}


/**
 @brief		Checks if the trip is legal for the Pawn.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Pawn::checkIfTripLegallyForPiece(const Point& dst) const
{
	// Validating trip for the white player
	if (this->_color.getPlayerColor() == WHITE_PLAYER)
	{
		if (dst == REGULAR_MOVE_NORTHWARD || (dst == FIRST_MOVE_NORTHWARD && this->_isFirstMove) ||
			dst == WHITE_ATE_LEFT || dst == WHITE_ATE_RIGHT)
		{
			return true;
		}
		return false;
	}

	// Validating trip for the black player
	if (this->_color.getPlayerColor() == BLACK_PLAYER)
	{
		if (dst == REGULAR_MOVE_SOUTHWARD || (dst == FIRST_MOVE_SOUTHWARD && this->_isFirstMove) ||
			dst == BLACK_ATE_LEFT || dst == BLACK_ATE_RIGHT)
		{
			return true;
		}
		return false;
	}

	return false;
}


/**
 @brief		Checks if there are pieces that block the Pawn's trip.
 @param		dst		The destination point of the Pawn.
 @return	false if the trip is blocked, true otherwise.
 */
bool Pawn::checkIfPiecesInTrip(const Point& dst) const
{
	if (this->_color.getPlayerColor() == WHITE_PLAYER)
	{
		if (dst == REGULAR_MOVE_NORTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}
			return true;
		}

		if (dst == FIRST_MOVE_NORTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER ||
				Piece::getElementAtLoc(this->_board, dst.getRow() + 1, dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}
			return true;
		}

		if (dst == WHITE_ATE_LEFT || dst == WHITE_ATE_RIGHT)
		{
			// Allowing the white player to move diagonally only if there is a black piece in the destination point
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() == BLACK_PLAYER)
			{
				return true;
			}
			return false;
		}
	}

	if (this->_color.getPlayerColor() == BLACK_PLAYER)
	{
		if (dst == REGULAR_MOVE_SOUTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}
			return true;
		}

		if (dst == FIRST_MOVE_SOUTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER ||
				Piece::getElementAtLoc(this->_board, dst.getRow() - 1, dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}
			return true;
		}

		if (dst == BLACK_ATE_LEFT || dst == BLACK_ATE_RIGHT)
		{
			// Allowing the black player to move diagonally only if there is a white piece in the destination point
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() == WHITE_PLAYER)
			{
				return true;
			}
			return false;
		}
	}

	return false;
}
