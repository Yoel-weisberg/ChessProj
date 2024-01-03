#pragma once

#include <vector>
#include <Windows.h>
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


class BoardUtils
{
public:
	static Point findKingPoint(const std::vector<Piece*>& board, const Player& player);

	static bool isKingInCheck(const std::vector<Piece*>& board, const Player& player);
	static bool isKingInCheckMate(const std::vector<Piece*>& board, const Player& player);

	static returnCode isMoveValid(const std::vector<Piece*>& board, const Player& turn, const Point& src, const Point& dst);
	static returnCode movePiece(std::vector<Piece*>& board, const Player& turn, const Point& src, const Point& dst);

	static void duplicatePieceOnBoard(std::vector<Piece*>& board, const Point& src, const Point& dst);
	static void removePieceFromBoard(std::vector<Piece*>& board, const Point& point);

	static Piece* clonePiece(const Piece* pieceToClone, const Point& pointToSet, std::vector<Piece*>& boardToSet);
	static void deletePiece(const Piece* pieceToDelete);

	static void cloneBoard(const std::vector<Piece*>& srcBoard, std::vector<Piece*>& dstBoard);
	static void deleteBoard(std::vector<Piece*>& boardToDelete);

	static void setConsoleColor(unsigned int color);
	static void printBoard(const std::vector<Piece*>& board, const Player& turn);

	static void actualMoveOfPiece(std::vector<Piece*>& board, const Point& src, const Point& dst);
};
