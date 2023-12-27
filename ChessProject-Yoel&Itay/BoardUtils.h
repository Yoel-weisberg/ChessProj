#pragma once

#include <vector>
#include "Board.h"
#include "Point.h"
#include "Player.h"

#define ROWS 8
#define COLS 8

#define PIECES_IN_TRIP		false
#define NO_PIECES_IN_TRIP	true


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
	static Player getPointPlayer(const std::vector<Piece*>& board, const Point& point);
	static Point findKingPoint(const std::vector<Piece*>& board, const Player& player);

	static bool isPointInBoundaries(const Point& point);
	static bool isKingInCheck(const std::vector<Piece*>& board, const Player& player);
	static returnCode isMoveValid(const std::vector<Piece*>& board, const Player& turn, const Point& src, const Point& dst);

	static returnCode movePiece(std::vector<Piece*>& board, const Player& turn, const Point& src, const Point& dst);

	static void cloneBoard(const std::vector<Piece*>& srcBoard, std::vector<Piece*>& dstBoard);
	static void deleteBoard(std::vector<Piece*>& boardToDelete);

	static void printBoard(const std::vector<Piece*>& board);
};
