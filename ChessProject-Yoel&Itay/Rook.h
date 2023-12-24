#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const char& type, const Point& location, const Player& color);
	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const override;

	static bool checkForPiecesOnTripRook(const Point& src, const Point& dst, const Board& board);
	static bool checkIfTripLegallyForPieceRook(const Point& src, const Point& dst);
};