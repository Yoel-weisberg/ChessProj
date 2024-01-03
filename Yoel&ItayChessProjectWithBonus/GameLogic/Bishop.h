#pragma once

#include "Piece.h"


class Bishop : public Piece
{
public:
	Bishop(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove = true);

	virtual std::vector<Point> returnPossibleDestinations() const override;
	static std::vector<Point> returnPossibleDestinationsBishop(const Piece& piece);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;

	static bool checkForPiecesOnTripBishop(const Point& src, const Point& dst, const std::vector <Piece*>& board);
	static bool checkIfTripLegallyForPieceBishop(const Point& src, const Point& dst);
};
