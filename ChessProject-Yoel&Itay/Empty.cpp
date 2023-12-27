#include "Empty.h"


/**
 @brief		Constructor - Initializes the type, location, color of Empty.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 @param		board		the board of the game
 */
Empty::Empty(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board) : Piece(type, location, color, board) {}


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
bool Empty::checkIfPiecesInTrip(const Point& dst) const
{
	return false;
}
