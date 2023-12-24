#pragma once

#include "Piece.h"


class Empty : public Piece
{
public:
	Empty(const char& type, const Point& location, const Player& color);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const override;
};
