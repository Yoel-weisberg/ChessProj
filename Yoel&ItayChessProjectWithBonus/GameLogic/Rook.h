#pragma once

#include "Piece.h"

#define W_ROOK_CASTELING_RIGHT Point(7, 5)
#define W_ROOK_CASTELING_LEFT Point(7, 2)

#define B_ROOK_CASTELING_RIGHT Point(0, 5)
#define B_ROOK_CASTELING_LEFT Point(0, 2)


class Rook : public Piece
{
public:
	Rook(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove = true);

	virtual std::vector<Point> returnPossibleDestinations() const override;
	static std::vector<Point> returnPossibleDestinationsRook(const Piece& piece);

	virtual bool checkIfTripLegallyForPiece(const Point& dst) const override;
	virtual bool checkIfPiecesInTrip(const Point& dst) const override;

	static bool checkForPiecesOnTripRook(const Point& src, const Point& dst, const std::vector <Piece*>& board);
	static bool checkIfTripLegallyForPieceRook(const Point& src, const Point& dst);

	virtual bool checkForCastling(const Point& dst) const override;
};
