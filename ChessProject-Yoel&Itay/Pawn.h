#pragma once

#include "Piece.h"


class Pawn : public Piece
{
	Pawn(const std::string& type, const Point& location, const Player& color);

	virtual int move(const Point& dst) override;

	bool isFirstMove() const;
};
