#pragma once

#include "Board.h"
#include "Piece.h"
#include "Point.h"
#include "Player.h"

#define ROWS 8
#define COLS 8

#define PIECES_IN_TRIP		false
#define NO_PIECES_IN_TRIP	true

class Piece;


enum returnCode
{
	VALID_MOVE = 0,						// Valid move
	CHECK_MOVE = 1,						// Valid move
	MISSING_CURRENT_IN_SRC = 2,			// Invalid move
	DST_OCCUPIED_BY_CURRENT = 3,		// Invalid move
	CAUSES_CHECK_ON_CURRENT = 4,		// Invalid move
	INVALID_INDEXES = 5,				// Invalid move
	ILLEGAL_MOVE_FOR_PIECE = 6,			// Invalid move
	SAME_SRC_DST_POINTS = 7,			// Invalid move
//	CHECKMATE_MOVE = 8					// Valid move
};


class BoardUtils
{
public:
	static Player getPointPlayer(const Board& board, const Point& point);

	static bool isPointInBoundaries(const Point& point);
	static bool isKingInCheck(const Board& board, const Player& player);
	static returnCode isMoveValid(const Board& board, const Player& turn, const Point& src, const Point& dst);

	static returnCode movePiece(const Board& board, const Player& turn, const Point& src, const Point& dst);

	static void printBoard(const Board& board);
};
