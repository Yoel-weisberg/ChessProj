#include "Knight.h"


/**
 @brief		Constructor - Initializes the type, location color and board (reference) of the Knight.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 @param		board		the board of the game
 */
Knight::Knight(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove) : Piece(type, location, color, board, isFirstMove) {}


/**
 @brief		Returns all the possible destinations of the Knight.
 @return	vector of all the possible destination Points of the Knight.
 */
std::vector<Point> Knight::returnPossibleDestinations() const
{
	std::vector<Point> possibleDestinations;
	std::string currentKnightColor = this->_color.getPlayerColor();


	if (Point::isPointInBoundaries(TWO_NORTH_ONE_WEST) && Piece::getElementAtLoc(this->_board, TWO_NORTH_ONE_WEST.getRow(), TWO_NORTH_ONE_WEST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(TWO_NORTH_ONE_WEST);
	}
	if (Point::isPointInBoundaries(TWO_NORTH_ONE_EAST) && Piece::getElementAtLoc(this->_board, TWO_NORTH_ONE_EAST.getRow(), TWO_NORTH_ONE_EAST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(TWO_NORTH_ONE_EAST);
	}
	if (Point::isPointInBoundaries(TWO_SOUTH_ONE_WEST) && Piece::getElementAtLoc(this->_board, TWO_SOUTH_ONE_WEST.getRow(), TWO_SOUTH_ONE_WEST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(TWO_SOUTH_ONE_WEST);
	}
	if (Point::isPointInBoundaries(TWO_SOUTH_ONE_EAST) && Piece::getElementAtLoc(this->_board, TWO_SOUTH_ONE_EAST.getRow(), TWO_SOUTH_ONE_EAST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(TWO_SOUTH_ONE_EAST);
	}
	if (Point::isPointInBoundaries(ONE_NORTH_TWO_WEST) && Piece::getElementAtLoc(this->_board, ONE_NORTH_TWO_WEST.getRow(), ONE_NORTH_TWO_WEST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(ONE_NORTH_TWO_WEST);
	}
	if (Point::isPointInBoundaries(ONE_NORTH_TWO_EAST) && Piece::getElementAtLoc(this->_board, ONE_NORTH_TWO_EAST.getRow(), ONE_NORTH_TWO_EAST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(ONE_NORTH_TWO_EAST);
	}
	if (Point::isPointInBoundaries(ONE_SOUTH_TWO_WEST) && Piece::getElementAtLoc(this->_board, ONE_SOUTH_TWO_WEST.getRow(), ONE_SOUTH_TWO_WEST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(ONE_SOUTH_TWO_WEST);
	}
	if (Point::isPointInBoundaries(ONE_SOUTH_TWO_EAST) && Piece::getElementAtLoc(this->_board, ONE_SOUTH_TWO_EAST.getRow(), ONE_SOUTH_TWO_EAST.getCol())->getColor().getPlayerColor() != currentKnightColor)
	{
		possibleDestinations.push_back(ONE_SOUTH_TWO_EAST);
	}

	return possibleDestinations;
}


/**
 @brief		Checks if the trip is legal for the Knight.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Knight::checkIfTripLegallyForPiece(const Point& dst) const
{
    int distBetweenCol = std::abs(dst.getCol() - this->_location.getCol());
    int distanceBetweenRow = std::abs(dst.getRow() - this->_location.getRow());

    if ((distBetweenCol == ALOOWED_MOVE_ONE && distanceBetweenRow == ALLOWED_MOVE_TWO) || (distBetweenCol == ALLOWED_MOVE_TWO && distanceBetweenRow == ALOOWED_MOVE_ONE))
    {
        return true;
    }

    return false;
}


/**
 @brief		Checks if there are pieces that block the Knight's trip.
 @param		dst		The destination point of the Knight.
 @return	true
 @note		The Knight can jump over other pieces - so this function always returns true.
 */
bool Knight::checkIfPiecesInTrip(const Point& dst) const
{
    return true;
}
