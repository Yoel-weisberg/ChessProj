#include "Rook.h"


/**
 @brief		Constructor - Initializes the type, location, color and board (reference) of the Rook.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Rook::Rook(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove) : Piece(type, location, color, board, isFirstMove) {}


/**
 @brief		Returns all the possible destinations of the Rook.
 @return	vector of all the possible destination Points of the Rook.
 */
std::vector<Point> Rook::returnPossibleDestinations() const
{
    return Rook::returnPossibleDestinationsRook(*this);
}


/**
 @brief		Returns all the possible destinations of the Rook.
 @return	vector of all the possible destination Points of the Rook.
 */
std::vector<Point> Rook::returnPossibleDestinationsRook(const Piece& piece)
{
    std::vector<Point> possibleDestinations;

    // North
    for (int row = piece.getLocation().getRow() - 1, col = piece.getLocation().getCol(); row >= 0; row--)
    {
        Point currentDstPoint = Point(row, col);

        if (piece.checkIfPiecesInTrip(currentDstPoint))
        {
            break;
        }
        if (piece.checkIfTripLegallyForPiece(currentDstPoint))
        {
			possibleDestinations.push_back(currentDstPoint);
        }
    }

    // South
    for (int row = piece.getLocation().getRow() + 1, col = piece.getLocation().getCol(); row < ROWS; row++)
    {
        Point currentDstPoint = Point(row, col);

        if (piece.checkIfPiecesInTrip(currentDstPoint))
        {
            break;
        }
        if (piece.checkIfTripLegallyForPiece(currentDstPoint))
        {
            possibleDestinations.push_back(currentDstPoint);
        }
    }

    // West
    for (int row = piece.getLocation().getRow(), col = piece.getLocation().getCol() - 1; col >= 0; col--)
    {
        Point currentDstPoint = Point(row, col);

        if (piece.checkIfPiecesInTrip(currentDstPoint))
        {
            break;
        }
        if (piece.checkIfTripLegallyForPiece(currentDstPoint))
        {
            possibleDestinations.push_back(currentDstPoint);
        }
    }

    // East
    for (int row = piece.getLocation().getRow(), col = piece.getLocation().getCol() + 1; col < COLS; col++)
    {
        Point currentDstPoint = Point(row, col);

        if (piece.checkIfPiecesInTrip(currentDstPoint))
        {
            break;
        }
        if (piece.checkIfTripLegallyForPiece(currentDstPoint))
        {
            possibleDestinations.push_back(currentDstPoint);
        }
    }

    return possibleDestinations;
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

bool Rook::checkForCastling(const Point& dst) const
{
    // checking if player had been moved
    if (this->_isFirstMove)
    {
        if (this->_color.getPlayerColor() == WHITE_PLAYER)
        {
            if (dst == W_ROOK_CASTELING_LEFT || dst == W_ROOK_CASTELING_RIGHT)
            {
                if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->isFirstMove())
                {
                    if (Rook::checkForPiecesOnTripRook(dst, this->_location, this->_board))
                    {
                        return true;
                    }
                }
            }
        }
        else if (this->_color.getPlayerColor() == BLACK_PLAYER)
        {
            if (dst == B_ROOK_CASTELING_LEFT || dst == B_ROOK_CASTELING_RIGHT)
            {
                if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->isFirstMove())
                {
                    if (Rook::checkForPiecesOnTripRook(dst, this->_location, this->_board))
                    {
                        return true;
                    }
                }
            }
        }
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
