#pragma once

#include "Piece.h"


class Empty : public Piece
{
public:
	Empty(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board);

	virtual std::vector<Point> returnPossibleDestinations() const override;

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;
};
