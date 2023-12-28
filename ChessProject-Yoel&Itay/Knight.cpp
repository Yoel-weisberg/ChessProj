#include "Knight.h"


/**
 @brief		Constructor - Initializes the type, location color and board (reference) of the Knight.
 @param		type		the type of the piece
 @param		location	the location of the piece on the board
 @param		color		the color of the piece
 @param		board		the board of the game
 */
Knight::Knight(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board)
    : Piece(type, location, color, board)
{
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
 @return	false if the trip is blocked, true otherwise.
 */
bool Knight::checkIfPiecesInTrip(const Point& dst) const
{
    // the knight is not bothered if there are pieces in its way
    return true;
}
