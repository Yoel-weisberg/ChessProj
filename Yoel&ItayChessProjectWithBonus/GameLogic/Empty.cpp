#include "Empty.h"


/**
 @brief		Constructor - Initializes the type, location, color and board (reference) of the Empty object.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 @param		board		the board of the game
 */
Empty::Empty(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board) : Piece(type, location, color, board) {}


/**
 @brief		Returns all the possible destinations of Empty Piece.
 @return	Empty vector
 */
std::vector<Point> Empty::returnPossibleDestinations() const
{
	return std::vector<Point>();
}


/**
 @brief		Empty Piece cannot move
 @param		dst		the destination point
 @return	false
 */
bool Empty::checkIfTripLegallyForPiece(const Point& dst) const
{
	return false;
}


/**
 @brief		Empty Piece cannot move
 @param		dst		the destination point
 @return	false
 */
bool Empty::checkIfPiecesInTrip(const Point& dst) const
{
	return false;
}
