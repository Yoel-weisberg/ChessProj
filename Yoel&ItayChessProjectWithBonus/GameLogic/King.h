#pragma once

#include "Piece.h"
#include "Rook.h"

// King possible moves
#define NORTH		Point(this->_location.getRow() - 1, this->_location.getCol())
#define SOUTH		Point(this->_location.getRow() + 1, this->_location.getCol())
#define WEST		Point(this->_location.getRow(), this->_location.getCol() - 1)
#define EAST		Point(this->_location.getRow(), this->_location.getCol() + 1)

#define NORTH_WEST	Point(this->_location.getRow() - 1, this->_location.getCol() - 1)
#define NORTH_EAST	Point(this->_location.getRow() - 1, this->_location.getCol() + 1)
#define SOUTH_WEST	Point(this->_location.getRow() + 1, this->_location.getCol() - 1)
#define SOUTH_EAST	Point(this->_location.getRow() + 1, this->_location.getCol() + 1)

#define W_KING_CASTELING_RIGHT Point(7, 1)
#define W_KING_CASTELING_LEFT Point(7, 6)

#define B_KING_CASTELING_RIGHT Point(0, 1)
#define B_KING_CASTELING_LEFT Point(0, 6)


class King : public Piece
{
public:
	King(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board, const bool& isFirstMove = true);

	virtual std::vector<Point> returnPossibleDestinations() const override;

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;
	virtual bool checkForCastling(const Point& dst) const override;
};
