#pragma once

#define ROWS 8
#define COLS 8

#define EXIT			"quit"


enum returnCode
{
	UNDEFINED = -1,						// Initial value
	VALID_MOVE = 0,						// Valid move
	CHECK_MOVE = 1,						// Valid move
	MISSING_CURRENT_IN_SRC = 2,			// Invalid move
	DST_OCCUPIED_BY_CURRENT = 3,		// Invalid move
	CAUSES_CHECK_ON_CURRENT = 4,		// Invalid move
	INVALID_INDEXES = 5,				// Invalid move
	ILLEGAL_MOVE_FOR_PIECE = 6,			// Invalid move
	SAME_SRC_DST_POINTS = 7,			// Invalid move
	CHECKMATE_MOVE = 8,					// Valid move
	ENPASSANT_MOVE = 9					// Valid move
};


#define BLACK_ROOK		'r'
#define BLACK_KNIGHT	'n'
#define BLACK_BISHOP	'b'
#define BLACK_QUEEN		'q'
#define BLACK_KING		'k'
#define BLACK_PAWN		'p'

#define WHITE_ROOK		'R'
#define WHITE_KNIGHT	'N'
#define WHITE_BISHOP	'B'
#define WHITE_QUEEN		'Q'
#define WHITE_KING		'K'
#define WHITE_PAWN		'P'

#define EMPTY '#'


#define WHITE_PLAYER "white"
#define BLACK_PLAYER "black"
#define EMPTY_PLAYER "empty"


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


// Console Colors
#define GREEN	2
#define WHITE	15
#define CYAN	3
#define GREY	7
