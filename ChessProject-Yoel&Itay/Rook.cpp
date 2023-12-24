#include "Rook.h"

bool Rook::checkIfTripLegallyForPiece(const Point& dst) const
{
    return Rook::checkIfTripLegallyForPieceRook(this->_location, dst);
}

Rook::Rook(const char& type, const Point& location, const Player& color)
    : Piece(type, location, color)
{
}

bool Rook::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
    return Rook::checkForPiecesOnTripRook(this->_location, dst, board);
}

bool Rook::checkForPiecesOnTripRook(const Point& src, const Point& dst, const Board& board)
{
    int i = 0, distance = 0;

    // if the points are the same colum
    if (src.getCol() == dst.getCol())
    {
        
        // if the destination is fartther then the src
        if (src.getRow() < dst.getRow())
        {
            for (i = src.getRow() + 1; i < dst.getRow(); i++)
            {
                if (board.board[i][dst.getCol()]->getType() != EMPTY)
                {
                    return false;
                }
            }
        }

        // if the src is farther then the dst
        else
        {
            // checking if there is somthing between the points
            for (i = dst.getRow() + 1; i < src.getRow(); i++)
            {
                if (board.board[i][dst.getCol()]->getType() != EMPTY)
                {
                    return false;
                }
            }
        }
    }


    // if the points are the same row
    if (src.getRow() == dst.getRow())
    {

        // if the destination is farther then the src
        if (src.getCol() < dst.getCol())
        {
            for (i = src.getCol() + 1; i < dst.getCol(); i++)
            {
                if (board.board[dst.getRow()][i]->getType() != EMPTY)
                {
                    return false;
                }
            }
        }

        // if the src is farther then the dst
        else
        {
            // checking if there is something between the points
            for (i = dst.getCol() + 1; i < src.getCol(); i++)
            {
                if (board.board[dst.getRow()][i]->getType() != EMPTY)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Rook::checkIfTripLegallyForPieceRook(const Point& src, const Point& dst)
{
    if (dst.getCol() == src.getCol() || dst.getRow() == src.getRow())
    {
        return true;
    }
    return false;
}
