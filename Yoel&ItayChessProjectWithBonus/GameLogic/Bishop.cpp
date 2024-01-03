#include "Bishop.h"


/**
 @brief		Constructor - Initializes the type, location, color and board (reference) of the Bishop.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Bishop::Bishop(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board) : Piece(type, location, color, board) {}


/**
 @brief		Checks if the trip is legal for the Bishop.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Bishop::checkIfTripLegallyForPiece(const Point& dst) const
{
	return Bishop::checkIfTripLegallyForPieceBishop(this->_location, dst);
}


/**
 @brief		Checks if there are pieces that block the Bishop's trip.
 @param		dst		The destination point of the Bishop.
 @return	false if the trip is blocked, true otherwise.
 */
bool Bishop::checkIfPiecesInTrip(const Point& dst) const
{
	return Bishop::checkForPiecesOnTripBishop(this->_location, dst, this->_board);
}


/**
 @brief		Checks if the trip is legal for the Bishop.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Bishop::checkIfTripLegallyForPieceBishop(const Point& src, const Point& dst)
{
    int distanceCol = std::abs(src.getCol() - dst.getCol());
    int distanceRow = std::abs(src.getRow() - dst.getRow());

    if (distanceCol == distanceRow)
    {
        return true;
    }
    return false;
}


/**
 @brief		Checks if there are pieces that block the Bishop's trip.
 @param		dst		The destination point of the Bishop.
 @return	false if the trip is blocked, true otherwise.
 */
bool Bishop::checkForPiecesOnTripBishop(const Point& src, const Point& dst, const std::vector <Piece*>& board)
{
    int distance = std::abs(src.getCol() - dst.getCol());
    int i = 0;

    // if the dst is above the src
    if (dst.getRow() > src.getRow())
    {
        // if the dst is above and to the right of the src
        if (dst.getCol() > src.getCol())
        {
            for (i = 1; i < distance; i++)
            {
                if (Piece::getElementAtLoc(board, src.getRow() + i, src.getCol() + i)->getType() != EMPTY)
                {
                    return false;
                }
            }
        }

        // if the dst is above and to the left of the src
        if (dst.getCol() < src.getCol())
        {
            for (i = 1; i < distance; i++)
            {
                if (Piece::getElementAtLoc(board, src.getRow() + i, src.getCol() - i)->getType() != EMPTY)
                {
                    return false;
                }
            }
        }

        return true;
    }

    // if the dst is underneath the src
    if (dst.getRow() < src.getRow())
    {
        // if the dst is underneath and to the right of the src
        if (dst.getCol() > src.getCol())
        {
            for (i = 1; i < distance; i++)
            {
                if (Piece::getElementAtLoc(board, src.getRow() - i, src.getCol() + i)->getType() != EMPTY)
                {
                    return false;
                }
            }
        }

        // if the dst is underneath and to the left of the src
        if (dst.getCol() < src.getCol())
        {
            for (i = 1; i < distance; i++)
            {
                if (Piece::getElementAtLoc(board, src.getRow() - i, src.getCol() - i)->getType() != EMPTY)
                {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}
