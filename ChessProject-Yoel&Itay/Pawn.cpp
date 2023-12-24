#include "Pawn.h"


/**
 @brief		Constructor - Initializes the type, location, color and the first move flag of the Pawn.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 */
Pawn::Pawn(const char& type, const Point& location, const Player& color) : Piece(type, location, color), _isFirstMove(true) {}


/**
 @brief		Checks if the trip is legal for the Pawn.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Pawn::checkIfTripLegallyForPiece(const Point& dst) const
{
	// Validating trip for the white player
	if (this->_color.getPlayerColor() == W)
	{
		if (dst == REGULAR_MOVE_NORTHWARD || (dst == FIRST_MOVE_NORTHWARD && this->_isFirstMove) ||
			dst == WHITE_ATE_LEFT || dst == WHITE_ATE_RIGHT)
		{
			return true;
		}
		return false;
	}

	// Validating trip for the black player
	if (this->_color.getPlayerColor() == B)
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
 @param		board	The board of the game.
 @return	false if the trip is blocked, true otherwise.
 */
bool Pawn::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
	if (this->_color.getPlayerColor() == W)
	{
		if (dst == REGULAR_MOVE_NORTHWARD)
		{
			if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return PIECES_IN_TRIP;
			}
			return NO_PIECES_IN_TRIP;
		}

		if (dst == FIRST_MOVE_NORTHWARD)
		{
			if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() != EMPTY_PLAYER ||
				board.board[dst.getRow() + 1][dst.getCol()]->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return PIECES_IN_TRIP;
			}
			return NO_PIECES_IN_TRIP;
		}

		if (dst == WHITE_ATE_LEFT || dst == WHITE_ATE_RIGHT)
		{
			// Allowing the white player to move diagonally only if there is a black piece in the destination point
			if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() == B)
			{
				return true;
			}
			return false;
		}
	}

	if (this->_color.getPlayerColor() == B)
	{
		if (dst == REGULAR_MOVE_SOUTHWARD)
		{
			if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return PIECES_IN_TRIP;
			}
			return NO_PIECES_IN_TRIP;
		}

		if (dst == FIRST_MOVE_SOUTHWARD)
		{
			if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() != EMPTY_PLAYER ||
				board.board[dst.getRow() - 1][dst.getCol()]->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return PIECES_IN_TRIP;
			}
			return NO_PIECES_IN_TRIP;
		}

		if (dst == BLACK_ATE_LEFT || dst == BLACK_ATE_RIGHT)
		{
			// Allowing the black player to move diagonally only if there is a white piece in the destination point
			if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() == W)
			{
				return true;
			}
			return false;
		}
	}
}
