#include "Empty.h"


/**
 @brief		Constructor - Initializes the type, location, color of Empty.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 */
Empty::Empty(const char& type, const Point& location, const Player& color) : Piece(type, location, color) {}


/**
 @brief		Empty Piece cannot move
 @return	false
 */
bool Empty::checkIfTripLegallyForPiece(const Point& dst) const
{
	return false;
}


/**
 @brief		Empty Piece cannot move
 @return	false
 */
bool Empty::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
	return false;
}
