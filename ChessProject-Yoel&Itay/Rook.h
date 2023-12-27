#pragma once

#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;

	static bool checkForPiecesOnTripRook(const Point& src, const Point& dst, std::vector <Piece*>& board);
	static bool checkIfTripLegallyForPieceRook(const Point& src, const Point& dst);
};
