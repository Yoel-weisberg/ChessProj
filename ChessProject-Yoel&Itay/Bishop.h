#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const char& type, const Point& location, const Player& color);
	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const override;


	static bool checkForPiecesOnTripBishop(const Point& src, const Point& dst, const Board& board);
	static bool checkIfTripLegallyForPieceBishop(const Point& src, const Point& dst);
};
