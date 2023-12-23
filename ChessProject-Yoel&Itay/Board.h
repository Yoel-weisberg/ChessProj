#pragma once

#include "Piece.h"

#define ROWS 8
#define COLS 8


class Board
{
public:
	Board();

	int getRows();
	int getCols();

	// A board is represented by a 2d array of pointers to Pieces
	Piece* board[ROWS][COLS];

private:
	int _rows;
	int _cols;
};
