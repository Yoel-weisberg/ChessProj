#pragma once

#include "Piece.h"

#define ROWS 8
#define COLS 8


class Board
{
public:
	Board();

	Piece* board[ROWS][COLS];
};
