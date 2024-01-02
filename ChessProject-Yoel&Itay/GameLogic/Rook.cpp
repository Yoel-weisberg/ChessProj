#include "Rook.h"


/**
 @brief		Constructor - Initializes the type, location, color and board (reference) of the Rook.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Rook::Rook(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board)
    : Piece(type, location, color, board)
{
}


/**
 @brief		Checks if the trip is legal for the Rook.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Rook::checkIfTripLegallyForPiece(const Point& dst) const
{
    return Rook::checkIfTripLegallyForPieceRook(this->_location, dst);
}


/**
 @brief		Checks if there are pieces that block the Rook's trip.
 @param		dst		The destination point of the Rook.
 @return	false if the trip is blocked, true otherwise.
 */
bool Rook::checkIfPiecesInTrip(const Point& dst) const
{
    return Rook::checkForPiecesOnTripRook(this->_location, dst, this->_board);
}


/**
 @brief		Checks if the trip is legal for the Rook.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Rook::checkIfTripLegallyForPieceRook(const Point& src, const Point& dst)
{
    if (dst.getCol() == src.getCol() || dst.getRow() == src.getRow())
    {
        return true;
    }
    return false;
}


/**
 @brief		Checks if there are pieces that block the Rook's trip.
 @param		dst		The destination point of the Rook.
 @return	false if the trip is blocked, true otherwise.
 */
bool Rook::checkForPiecesOnTripRook(const Point& src, const Point& dst, const std::vector <Piece*>& board)
{
    int i = 0, distance = 0;

    // if the points are in the same column
    if (src.getCol() == dst.getCol())
    {
        // if the destination is farther than the src
        if (src.getRow() < dst.getRow())
        {
            for (i = src.getRow() + 1; i < dst.getRow(); i++)
            {
                if (Piece::getElementAtLoc(board, i, dst.getCol())->getType() != EMPTY)
                {
                    return false;
                }
            }
            return true;
        }
        // if the src is farther than the dst
        else
        {
            // checking if there is something between the points
            for (i = dst.getRow() + 1; i < src.getRow(); i++)
            {
                if (Piece::getElementAtLoc(board, i, dst.getCol())->getType() != EMPTY)
                {
                    return false;
                }
            }
            return true;
        }
    }

    // if the points are in the same row
    if (src.getRow() == dst.getRow())
    {
        // if the destination is farther than the src
        if (src.getCol() < dst.getCol())
        {
            for (i = src.getCol() + 1; i < dst.getCol(); i++)
            {
                if (Piece::getElementAtLoc(board, dst.getRow(), i)->getType() != EMPTY)
                {
                    return false;
                }
            }
            return true;
        }
        // if the src is farther than the dst
        else
        {
            // checking if there is something between the points
            for (i = dst.getCol() + 1; i < src.getCol(); i++)
            {
                if (Piece::getElementAtLoc(board, dst.getRow(), i)->getType() != EMPTY)
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
