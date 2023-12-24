#pragma once

#include "Piece.h"

// Possible moves for white pawn
#define REGULAR_MOVE_NORTHWARD	Point(this->_location.getRow() - 1, this->_location.getCol())
#define FIRST_MOVE_NORTHWARD	Point(this->_location.getRow() - 2, this->_location.getCol())

#define WHITE_ATE_LEFT			Point(this->_location.getRow() - 1, this->_location.getCol() - 1)
#define WHITE_ATE_RIGHT			Point(this->_location.getRow() - 1, this->_location.getCol() + 1)

// Possible moves for black pawn
#define REGULAR_MOVE_SOUTHWARD	Point(this->_location.getRow() + 1, this->_location.getCol())
#define FIRST_MOVE_SOUTHWARD	Point(this->_location.getRow() + 2, this->_location.getCol())

#define BLACK_ATE_LEFT			Point(this->_location.getRow() + 1, this->_location.getCol() - 1)
#define BLACK_ATE_RIGHT			Point(this->_location.getRow() + 1, this->_location.getCol() + 1)


class Pawn : public Piece
{
public:
	Pawn(const char& type, const Point& location, const Player& color);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const override;

private:
	bool _isFirstMove;
};
