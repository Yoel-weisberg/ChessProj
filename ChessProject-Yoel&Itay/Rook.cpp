#include "Rook.h"

bool Rook::checkIfTripLegallyForPiece(const Point& dst) const
{
    if (dst.getCol() == this->_location.getCol() || dst.getRow() == this->_location.getRow())
    {
        return true;
    }
    return false;
}

Rook::Rook(const char& type, const Point& location, const Player& color)
    : Piece(type, location, color)
{
}

bool Rook::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
    int i = 0, distance = 0;

    // if the points are the same colum
    if (this->_location.getCol() == dst.getCol())
    {

        // if the destination is fartther then the src
        if (this->_location.getCol() < dst.getCol())
        {
            for (i = this->_location.getCol(); i < dst.getCol(); i++)
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
            for (i = dst.getCol(); i < this->_location.getCol(); i++)
            {
                if (board.board[i][dst.getCol()]->getType() != EMPTY)
                {
                    return false;
                }
            }
        }
    }


    // if the points are the same row
    if (this->_location.getRow() == dst.getRow())
    {

        // if the destination is farther then the src
        if (this->_location.getRow() < dst.getRow())
        {
            for (i = this->_location.getRow(); i < dst.getRow(); i++)
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
            for (i = dst.getRow(); i < this->_location.getRow(); i++)
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
