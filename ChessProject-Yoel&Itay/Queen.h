#pragma once

#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"


class Queen : public Piece
{
public:
	Queen(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;
};
