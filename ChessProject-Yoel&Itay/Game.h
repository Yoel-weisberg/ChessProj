#pragma once

// Those classes already include Piece.h...
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Empty.h"
#include "BoardUtils.h"
#include "Player.h"


#define B_ROOK1_ROW		0
#define B_ROOK1_COL		0

#define B_KNIGHT1_ROW	0
#define B_KNIGHT1_COL	1

#define B_BISHOP1_ROW	0
#define B_BISHOP1_COL	2

#define B_QUEEN_ROW		0
#define B_QUEEN_COL		3

#define B_KING_ROW		0
#define B_KING_COL		4

#define B_BISHOP2_ROW	0
#define B_BISHOP2_COL	5

#define B_KNIGHT2_ROW	0
#define B_KNIGHT2_COL	6

#define B_ROOK2_ROW		0
#define B_ROOK2_COL		7

#define BLACK_PAWNS_ROW 1


#define W_ROOK1_ROW		7
#define W_ROOK1_COL		0

#define W_KNIGHT1_ROW	7
#define W_KNIGHT1_COL	1

#define W_BISHOP1_ROW	7
#define W_BISHOP1_COL	2

#define W_QUEEN_ROW		7
#define W_QUEEN_COL		3

#define W_KING_ROW		7
#define W_KING_COL		4

#define W_BISHOP2_ROW	7
#define W_BISHOP2_COL	5

#define W_KNIGHT2_ROW	7
#define W_KNIGHT2_COL	6

#define W_ROOK2_ROW		7
#define W_ROOK2_COL		7

#define WHITE_PAWNS_ROW 6

#define EMPTY_POINTS_ROW_START	2
#define EMPTY_POINTS_ROW_END	6


class Game
{
public:
	Game();
	~Game();

	std::vector<Piece*> getBoard() const;
	void switchTurn();

	Player getTurn() const;

	returnCode moveOnBoard(const Point& src, const Point& dst);


private:
	std::vector <Piece*> _board;
	Player _turn;
};
