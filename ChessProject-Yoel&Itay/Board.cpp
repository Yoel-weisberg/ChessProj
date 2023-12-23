#include "Board.h"

#define B_ROOK1_ROW 0
#define B_ROOK1_COL 0

#define B_KNIGHT1_ROW 0
#define B_KNIGHT1_COL 1

#define B_BISHOP1_ROW 0
#define B_BISHOP1_COL 2

#define B_QUEEN_ROW 0
#define B_QUEEN_COL 3

#define B_KING_ROW 0
#define B_KING_COL 4

#define B_BISHOP2_ROW 0
#define B_BISHOP2_COL 5

#define B_KNIGHT2_ROW 0
#define B_KNIGHT2_COL 6

#define B_ROOK2_ROW 0
#define B_ROOK2_COL 7


#define W_ROOK1_ROW 7
#define W_ROOK1_COL 0

#define W_KNIGHT1_ROW 7
#define W_KNIGHT1_COL 1

#define W_BISHOP1_ROW 7
#define W_BISHOP1_COL 2

#define W_QUEEN_ROW 7
#define W_QUEEN_COL 3

#define W_KING_ROW 7
#define W_KING_COL 4

#define W_BISHOP2_ROW 7
#define W_BISHOP2_COL 5

#define W_KNIGHT2_ROW 7
#define W_KNIGHT2_COL 6

#define W_ROOK2_ROW 7
#define W_ROOK2_COL 7


Board::Board() :
	_rows(ROWS), _cols(COLS)
{

}


/**
 @brief		Returns the number of rows in the board.
 @return	The number of rows in the board.
 */
int Board::getRows()
{
	return this->_rows;
}


/**
 @brief		Returns the number of columns in the board.
 @return	The number of columns in the board.
 */
int Board::getCols()
{
	return this->_cols;
}
