#include "Rock.h"

bool Rock::checkIfTripLegallyForPiece(const Point& dst, const Board& board) const
{
    if (dst.getCol() == this->_location.getCol() || dst.getRow() == this->_location.getRow())
    {
        return true;
    }
    return false;
}

bool Rock::checkIfPiecesInTrip(const Point& dst, const Board& board) const
{
    int i = 0, distance = 0;

    // if the points are the same colum
    if (this->_location.getCol() == dst.getCol())
    {
        distance = std::abs(this->_location.getCol() - dst.getCol());

        // if the destination is fartther then the src
        if (this->_location.getCol() < dst.getCol())
        {
            for (i = this->_location.getCol(); i < distance; i++)
            {
                if (board.board[i][dst.getCol()]->getType() != 'e')
                {
                    return false;
                }
            }
        }

        // if the src is farther then the dst
        else
        {
            // checking if there is somthing between the points
            for (i = dst.getCol(); i < distance; i++)
            {
                if (board.board[i][dst.getCol()]->getType() != 'e')
                {
                    return false;
                }
            }
        }
    }


    // if the points are the same row
    if (this->_location.getRow() == dst.getRow())
    {
        distance = std::abs(this->_location.getRow() - dst.getRow());

        // if the destination is farther then the src
        if (this->_location.getRow() < dst.getRow())
        {
            for (i = this->_location.getRow(); i < distance; i++)
            {
                if (board.board[dst.getRow()][i]->getType() != 'e')
                {
                    return false;
                }
            }
        }

        // if the src is farther then the dst
        else
        {
            // checking if there is something between the points
            for (i = dst.getRow(); i < distance; i++)
            {
                if (board.board[dst.getRow()][i]->getType() != 'e')
                {
                    return false;
                }
            }
        }
    }
    return true;
}
