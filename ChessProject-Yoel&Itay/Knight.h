#pragma once
#include "Piece.h"

#define ALOOWED_MOVE_ONE 1
#define ALLOWED_MOVE_TWO 2

class Knight : public Piece
{
	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const override;
};
