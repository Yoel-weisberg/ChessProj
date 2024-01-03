#include "Bishop.h"


/**
 @brief		Constructor - Initializes the type, location, color and board (reference) of the Bishop.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Bishop::Bishop(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove) : Piece(type, location, color, board, isFirstMove) {}


/**
 @brief		Returns all the possible destinations of the Bishop.
 @return	vector of all the possible destination Points of the Beshop.
 */
std::vector<Point> Bishop::returnPossibleDestinations() const
{
    return Bishop::returnPossibleDestinationsBishop(*this);
}


/**
 @brief		Returns all the possible destinations of the Bishop.
 @return	vector of all the possible destination Points of the Beshop.
 */
std::vector<Point> Bishop::returnPossibleDestinationsBishop(const Piece& piece)
{
    std::vector<Point> possibleDestinations;
    std::string currentBishopColor = piece.getColor().getPlayerColor();
    std::string opponentColor = (currentBishopColor == WHITE_PLAYER) ? BLACK_PLAYER : WHITE_PLAYER;

    // North-West
    for (int row = piece.getLocation().getRow() - 1, col = piece.getLocation().getCol() - 1; (row >= 0) && (col >= 0); row--, col--)
    {
        Point currentDstPoint = Point(row, col);

        if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == EMPTY_PLAYER)
        {
            possibleDestinations.push_back(currentDstPoint);
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == opponentColor)
		{
			possibleDestinations.push_back(currentDstPoint);
			break;
		}
		else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == currentBishopColor)
		{
			break;
		}
    }

    // North-East
    for (int row = piece.getLocation().getRow() - 1, col = piece.getLocation().getCol() + 1; (row >= 0) && (col < COLS); row--, col++)
    {
        Point currentDstPoint = Point(row, col);

        if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == EMPTY_PLAYER)
        {
            possibleDestinations.push_back(currentDstPoint);
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == opponentColor)
        {
            possibleDestinations.push_back(currentDstPoint);
            break;
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == currentBishopColor)
        {
            break;
        }
    }

    // South-West
    for (int row = piece.getLocation().getRow() + 1, col = piece.getLocation().getCol() - 1; (row < ROWS) && (col >= 0); row++, col--)
    {
        Point currentDstPoint = Point(row, col);

        if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == EMPTY_PLAYER)
        {
            possibleDestinations.push_back(currentDstPoint);
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == opponentColor)
        {
            possibleDestinations.push_back(currentDstPoint);
            break;
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == currentBishopColor)
        {
            break;
        }
    }

    // South-East
    for (int row = piece.getLocation().getRow() + 1, col = piece.getLocation().getCol() + 1; (row < ROWS) && (col < COLS); row++, col++)
    {
        Point currentDstPoint = Point(row, col);

        if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == EMPTY_PLAYER)
        {
            possibleDestinations.push_back(currentDstPoint);
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == opponentColor)
        {
            possibleDestinations.push_back(currentDstPoint);
            break;
        }
        else if (Piece::getElementAtLoc(piece.getBoard(), row, col)->getColor().getPlayerColor() == currentBishopColor)
        {
            break;
        }
    }

    return possibleDestinations;
}


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
