#include "Knight.h"

Knight::Knight(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board)
    : Piece(type, location, color, board)
{
}

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

bool Knight::checkIfPiecesInTrip(const Point& dst) const
{
    // the knight is not bothered if there are pieces in its way
    return true;
}
