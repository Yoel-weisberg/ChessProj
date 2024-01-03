#pragma once

#include "Piece.h"

#define ALOOWED_MOVE_ONE 1
#define ALLOWED_MOVE_TWO 2

// Knight possible moves
#define TWO_NORTH_ONE_WEST	Point(this->_location.getRow() - 2, this->_location.getCol() - 1)
#define TWO_NORTH_ONE_EAST	Point(this->_location.getRow() - 2, this->_location.getCol() + 1)
#define TWO_SOUTH_ONE_WEST	Point(this->_location.getRow() + 2, this->_location.getCol() - 1)
#define TWO_SOUTH_ONE_EAST	Point(this->_location.getRow() + 2, this->_location.getCol() + 1)
#define ONE_NORTH_TWO_WEST	Point(this->_location.getRow() - 1, this->_location.getCol() - 2)
#define ONE_NORTH_TWO_EAST	Point(this->_location.getRow() - 1, this->_location.getCol() + 2)
#define ONE_SOUTH_TWO_WEST	Point(this->_location.getRow() + 1, this->_location.getCol() - 2)
#define ONE_SOUTH_TWO_EAST	Point(this->_location.getRow() + 1, this->_location.getCol() + 2)


class Knight : public Piece
{
public:
	Knight(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove = true);

	virtual std::vector<Point> returnPossibleDestinations() const override;

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;
};
