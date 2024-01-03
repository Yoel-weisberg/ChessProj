#include "Pawn.h"

bool Pawn::pawnMove2SquaresLastTurn = false;
Point Pawn::toWherePawnMoved2Squares = Point(-1, -1);
bool Pawn::enPassantOccured = false;


/**
 @brief		Constructor - Initializes the type, location color and the board (reference).
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Pawn::Pawn(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board, const bool& isFirstMove ) : Piece(type, location, color, board, isFirstMove) {}


/**
 @brief		Returns all the possible destinations of the King.
 @return	vector of all the possible destination Points of the King.
 */
std::vector<Point> Pawn::returnPossibleDestinations() const
{
	std::vector<Point> possibleDestinations;

	if (this->_color.getPlayerColor() == WHITE_PLAYER)
	{
		if (Point::isPointInBoundaries(REGULAR_MOVE_NORTHWARD) && this->checkIfLegallyForPiece(REGULAR_MOVE_NORTHWARD) == VALID_MOVE)
		{
			possibleDestinations.push_back(REGULAR_MOVE_NORTHWARD);
		}
		if (Point::isPointInBoundaries(FIRST_MOVE_NORTHWARD) && this->checkIfLegallyForPiece(FIRST_MOVE_NORTHWARD) == VALID_MOVE)
		{
			possibleDestinations.push_back(FIRST_MOVE_NORTHWARD);
		}
		if (Point::isPointInBoundaries(WHITE_DIAGONAL_LEFT) && this->checkIfLegallyForPiece(WHITE_DIAGONAL_LEFT) == VALID_MOVE)
		{
			possibleDestinations.push_back(WHITE_DIAGONAL_LEFT);
		}
		if (Point::isPointInBoundaries(WHITE_DIAGONAL_RIGHT) && this->checkIfLegallyForPiece(WHITE_DIAGONAL_RIGHT) == VALID_MOVE)
		{
			possibleDestinations.push_back(WHITE_DIAGONAL_RIGHT);
		}
	}

	else if (this->_color.getPlayerColor() == BLACK_PLAYER)
	{
		if (Point::isPointInBoundaries(REGULAR_MOVE_SOUTHWARD) && this->checkIfLegallyForPiece(REGULAR_MOVE_SOUTHWARD) == VALID_MOVE)
		{
			possibleDestinations.push_back(REGULAR_MOVE_SOUTHWARD);
		}
		if (Point::isPointInBoundaries(FIRST_MOVE_SOUTHWARD) && this->checkIfLegallyForPiece(FIRST_MOVE_SOUTHWARD) == VALID_MOVE)
		{
			possibleDestinations.push_back(FIRST_MOVE_SOUTHWARD);
		}
		if (Point::isPointInBoundaries(BLACK_DIAGONAL_LEFT) && this->checkIfLegallyForPiece(BLACK_DIAGONAL_LEFT) == VALID_MOVE)
		{
			possibleDestinations.push_back(BLACK_DIAGONAL_LEFT);
		}
		if (Point::isPointInBoundaries(BLACK_DIAGONAL_RIGHT) && this->checkIfLegallyForPiece(BLACK_DIAGONAL_RIGHT) == VALID_MOVE)
		{
			possibleDestinations.push_back(BLACK_DIAGONAL_RIGHT);
		}
	}

	return possibleDestinations;
}


/**
 @brief		Checks if the trip is legal for the Pawn.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 */
bool Pawn::checkIfTripLegallyForPiece(const Point& dst) const
{
	// Validating trip for the white player
	if (this->_color.getPlayerColor() == WHITE_PLAYER)
	{
		if (dst == REGULAR_MOVE_NORTHWARD || (dst == FIRST_MOVE_NORTHWARD && this->isFirstMove()) || dst == WHITE_DIAGONAL_LEFT || dst == WHITE_DIAGONAL_RIGHT)
		{
			return true;
		}
		return false;
	}

	// Validating trip for the black player
	if (this->_color.getPlayerColor() == BLACK_PLAYER)
	{
		if (dst == REGULAR_MOVE_SOUTHWARD || (dst == FIRST_MOVE_SOUTHWARD && this->isFirstMove()) || dst == BLACK_DIAGONAL_LEFT || dst == BLACK_DIAGONAL_RIGHT)
		{
			return true;
		}
		return false;
	}

	return false;
}


/**
 @brief		Checks if there are pieces that block the Pawn's trip.
 @param		dst		The destination point of the Pawn.
 @return	false if the trip is blocked, true otherwise.
 */
bool Pawn::checkIfPiecesInTrip(const Point& dst) const
{
	if (this->_color.getPlayerColor() == WHITE_PLAYER)
	{
		if (dst == REGULAR_MOVE_NORTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}

			Pawn::pawnMove2SquaresLastTurn = false;

			return true;
		}

		if (dst == FIRST_MOVE_NORTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER ||
				Piece::getElementAtLoc(this->_board, dst.getRow() + 1, dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}

			Pawn::pawnMove2SquaresLastTurn = true;
			Pawn::toWherePawnMoved2Squares = dst;

			return true;
		}

		// Allowing the white player to move diagonally only if there is a black piece in the destination point or in an en-passant move
		if (dst == WHITE_DIAGONAL_LEFT || dst == WHITE_DIAGONAL_RIGHT)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() == BLACK_PLAYER)
			{
				Pawn::pawnMove2SquaresLastTurn = false;
				return true;
			}

			else if (dst == WHITE_DIAGONAL_LEFT && Pawn::pawnMove2SquaresLastTurn && (Pawn::toWherePawnMoved2Squares == Point(this->_location.getRow(), this->_location.getCol() - 1)))
			{
				Pawn::pawnMove2SquaresLastTurn = false;
				Pawn::enPassantOccured = true;
				return true;
			}

			else if (dst == WHITE_DIAGONAL_RIGHT && Pawn::pawnMove2SquaresLastTurn && (Pawn::toWherePawnMoved2Squares == Point(this->_location.getRow(), this->_location.getCol() + 1)))
			{
				Pawn::pawnMove2SquaresLastTurn = false;
				Pawn::enPassantOccured = true;
				return true;
			}

			return false;
		}
	}

	if (this->_color.getPlayerColor() == BLACK_PLAYER)
	{
		if (dst == REGULAR_MOVE_SOUTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}

			Pawn::pawnMove2SquaresLastTurn = false;

			return true;
		}

		if (dst == FIRST_MOVE_SOUTHWARD)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER ||
				Piece::getElementAtLoc(this->_board, dst.getRow() - 1, dst.getCol())->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				return false;
			}

			Pawn::pawnMove2SquaresLastTurn = true;
			Pawn::toWherePawnMoved2Squares = dst;

			return true;
		}

		// Allowing the black player to move diagonally only if there is a white piece in the destination point or in an en-passant move
		if (dst == BLACK_DIAGONAL_LEFT || dst == BLACK_DIAGONAL_RIGHT)
		{
			if (Piece::getElementAtLoc(this->_board, dst.getRow(), dst.getCol())->getColor().getPlayerColor() == WHITE_PLAYER)
			{
				Pawn::pawnMove2SquaresLastTurn = false;
				return true;
			}

			else if (dst == BLACK_DIAGONAL_LEFT && Pawn::pawnMove2SquaresLastTurn && (Pawn::toWherePawnMoved2Squares == Point(this->_location.getRow(), this->_location.getCol() - 1)))
			{
				Pawn::pawnMove2SquaresLastTurn = false;
				Pawn::enPassantOccured = true;
				return true;
			}

			else if (dst == BLACK_DIAGONAL_RIGHT && Pawn::pawnMove2SquaresLastTurn && (Pawn::toWherePawnMoved2Squares == Point(this->_location.getRow(), this->_location.getCol() + 1)))
			{
				Pawn::pawnMove2SquaresLastTurn = false;
				Pawn::enPassantOccured = true;
				return true;
			}

			return false;
		}
	}

	return false;
}
