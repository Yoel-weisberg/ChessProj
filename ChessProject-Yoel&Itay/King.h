#pragma once

#include "Piece.h"

// King possible moves
#define NORTH		Point(this->_location.getRow() - 1, this->_location.getCol())
#define SOUTH		Point(this->_location.getRow() + 1, this->_location.getCol())
#define WEST		Point(this->_location.getRow(), this->_location.getCol() - 1)
#define EAST		Point(this->_location.getRow(), this->_location.getCol() + 1)

#define NORTH_WEST	Point(this->_location.getRow() - 1, this->_location.getCol() - 1)
#define NORTH_EAST	Point(this->_location.getRow() - 1, this->_location.getCol() + 1)
#define SOUTH_WEST	Point(this->_location.getRow() + 1, this->_location.getCol() - 1)
#define SOUTH_EAST	Point(this->_location.getRow() + 1, this->_location.getCol() + 1)


class King : public Piece
{
public:
	King(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;
};
