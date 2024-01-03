#pragma once

#include "Piece.h"

// Possible moves for white pawn
#define REGULAR_MOVE_NORTHWARD		Point(this->_location.getRow() - 1, this->_location.getCol())
#define FIRST_MOVE_NORTHWARD		Point(this->_location.getRow() - 2, this->_location.getCol())

#define WHITE_DIAGONAL_LEFT			Point(this->_location.getRow() - 1, this->_location.getCol() - 1)
#define WHITE_DIAGONAL_RIGHT		Point(this->_location.getRow() - 1, this->_location.getCol() + 1)

// Possible moves for black pawn
#define REGULAR_MOVE_SOUTHWARD		Point(this->_location.getRow() + 1, this->_location.getCol())
#define FIRST_MOVE_SOUTHWARD		Point(this->_location.getRow() + 2, this->_location.getCol())

#define BLACK_DIAGONAL_LEFT			Point(this->_location.getRow() + 1, this->_location.getCol() - 1)
#define BLACK_DIAGONAL_RIGHT		Point(this->_location.getRow() + 1, this->_location.getCol() + 1)


class Pawn : public Piece
{
public:
	Pawn(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board, const bool& isFirstMove = true);

	virtual std::vector<Point> returnPossibleDestinations() const override;

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;

	// Static variables for en-passant
	static bool pawnMove2SquaresLastTurn;
	static Point toWherePawnMoved2Squares;
	static bool enPassantOccured;
};
