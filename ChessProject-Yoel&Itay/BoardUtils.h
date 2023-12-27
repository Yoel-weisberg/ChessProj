#pragma once

#include <vector>
#include "Empty.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

#include "Piece.h"
#include "Point.h"
#include "Player.h"
#include "Constants.h"

#define ROWS 8
#define COLS 8


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
