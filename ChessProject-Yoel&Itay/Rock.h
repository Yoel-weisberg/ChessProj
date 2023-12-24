#pragma once
#include "Piece.h"

class Rock : public Piece
{
public:
	virtual bool checkIfTripLegallyForPiece(const Point& dst, const Board& board) const;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const;
};