#pragma once

#include "Piece.h"
#include "Point.h"
#include "Player.h"

#define ROWS 8
#define COLS 8


enum returnCode
{
	VALID_MOVE = 0,						// Valid move
	CHECK_MOVE = 1,						// Valid move
	MISSING_CURRENT_IN_SRC = 2,			// Invalid move
	DST_OCCUPIED_BY_CURRENT = 3,		// Invalid move
	CAUSES_CHESS_ON_CURRENT = 4,		// Invalid move
	INVALID_INDEXES = 5,				// Invalid move
	ILLEGAL_MOVE_FOR_PIECE = 6,			// Invalid move
	SAME_SRC_DST_POINTS = 7,			// Invalid move
	CHECKMATE_MOVE = 8					// Valid move
};


class Board
{
public:
	static Player getPointPlayer(const Piece* (&board)[ROWS][COLS], const Point& point);

	static bool isPointInBoundaries(const Piece* (&board)[ROWS][COLS], const Point& point);
	static bool isKingInChess(const Piece* (&board)[ROWS][COLS], const Player& player);
	static returnCode isMoveValid(const Piece* (&board)[ROWS][COLS], const Point& src, const Point& dst);

	static bool movePiece(Piece* (&board)[ROWS][COLS], const Point& src, const Point& dst);
};
