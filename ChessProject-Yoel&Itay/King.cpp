#include "King.h"


/**
 @brief		Constructor - Initializes the type, location, color of the King.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 */
King::King(const char& type, const Point& location, const Player& color) : Piece(type, location, color) {}


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
 @param		board	The board of the game.
 @return	false if the trip is blocked, true otherwise.
 */
bool King::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
	if (this->getColor().getPlayerColor() == W)
	{
		// If there is a white piece in the destination point - then the white king cannot move into it
		if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() == W)
		{
			return PIECES_IN_TRIP;
		}

		return NO_PIECES_IN_TRIP;
	}

	if (this->getColor().getPlayerColor() == B)
	{
		// If there is a black piece in the destination point - then the black king cannot move into it
		if (board.board[dst.getRow()][dst.getCol()]->getColor().getPlayerColor() == B)
		{
			return PIECES_IN_TRIP;
		}

		return NO_PIECES_IN_TRIP;
	}
}
