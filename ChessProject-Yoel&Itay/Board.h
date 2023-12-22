#pragma once

#include "Piece.h"
#include "Point.h"
#include "Player.h"


class Board
{
public:
	static bool isPointTaken(const Point& point, const std::vector<Piece>& board);
	static bool isPointInBoundaries(const Point& point, const std::vector<Piece>& board);
	static bool isKingInChess(const Player&, const std::vector<Piece>& board);
	static bool isPointEmpty(const Point& point, const std::vector<Piece>& board);
	
	static bool movePiece(const Point& src, const Point& dst, std::vector<Piece>& board);
};
