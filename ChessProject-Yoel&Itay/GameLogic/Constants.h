#pragma once


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
	//	CHECKMATE_MOVE = 8					// Valid move
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


#define EXIT			"quit"


// Console Colors
#define GREEN	2
#define WHITE	15
#define CYAN	3
#define GREY	7
