#include "Board.h"


/**
 @brief		Constructor - Initializes the board, rows and columns of the board.
 @note		The board is dynamically initialized with the following pieces:
			- Black pieces: 2 rooks, 2 knights, 2 bishops, 1 queen, 1 king and 8 pawns.
			- Empty pieces: 32 empty pieces.
			- White pieces: 2 rooks, 2 knights, 2 bishops, 1 queen, 1 king and 8 pawns.
 */
Board::Board() :
	_rows(ROWS), _cols(COLS)
{
	// Adding black pieces
	this->board[B_ROOK1_ROW][B_ROOK1_COL] = new Rook(BLACK_ROOK, Point(B_ROOK1_ROW, B_ROOK1_COL), Player(B));
	this->board[B_KNIGHT1_ROW][B_KNIGHT1_COL] = new Knight(BLACK_KNIGHT, Point(B_KNIGHT1_ROW, B_KNIGHT1_COL), Player(B));
	this->board[B_BISHOP1_ROW][B_BISHOP1_COL] = new Bishop(BLACK_BISHOP, Point(B_BISHOP1_ROW, B_BISHOP1_COL), Player(B));
	this->board[B_QUEEN_ROW][B_QUEEN_COL] = new Queen(BLACK_QUEEN, Point(B_QUEEN_ROW, B_QUEEN_COL), Player(B));
	this->board[B_KING_ROW][B_KING_COL] = new King(BLACK_KING, Point(B_KING_ROW, B_KING_COL), Player(B));
	this->board[B_BISHOP2_ROW][B_BISHOP2_COL] = new Bishop(BLACK_BISHOP, Point(B_BISHOP2_ROW, B_BISHOP2_COL), Player(B));
	this->board[B_KNIGHT2_ROW][B_KNIGHT2_COL] = new Knight(BLACK_KNIGHT, Point(B_KNIGHT2_ROW, B_KNIGHT2_COL), Player(B));
	this->board[B_ROOK2_ROW][B_ROOK2_COL] = new Rook(BLACK_ROOK, Point(B_ROOK2_ROW, B_ROOK2_COL), Player(B));

	// Adding black pawns
	for (int i = 0; i < COLS; i++)
	{
		this->board[BLACK_PAWNS_ROW][i] = new Pawn(BLACK_PAWN, Point(BLACK_PAWNS_ROW, i), Player(B));
	}

	// Filling the required points with empty Pieces
	for (int row = EMPTY_POINTS_ROW_START; row < EMPTY_POINTS_ROW_END; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			this->board[row][col] = new Empty('#', Point(row, col), Player(EMPTY_PLAYER));
		}
	}

	// Adding white pieces
	this->board[W_ROOK1_ROW][W_ROOK1_COL] = new Rook(WHITE_ROOK, Point(W_ROOK1_ROW, W_ROOK1_COL), Player(W));
	this->board[W_KNIGHT1_ROW][W_KNIGHT1_COL] = new Knight(WHITE_KNIGHT, Point(W_KNIGHT1_ROW, W_KNIGHT1_COL), Player(W));
	this->board[W_BISHOP1_ROW][W_BISHOP1_COL] = new Bishop(WHITE_BISHOP, Point(W_BISHOP1_ROW, W_BISHOP1_COL), Player(W));
	this->board[W_QUEEN_ROW][W_QUEEN_COL] = new Queen(WHITE_QUEEN, Point(W_QUEEN_ROW, W_QUEEN_COL), Player(W));
	this->board[W_KING_ROW][W_KING_COL] = new King(WHITE_KING, Point(W_KING_ROW, W_KING_COL), Player(W));
	this->board[W_BISHOP2_ROW][W_BISHOP2_COL] = new Bishop(WHITE_BISHOP, Point(W_BISHOP2_ROW, W_BISHOP2_COL), Player(W));
	this->board[W_KNIGHT2_ROW][W_KNIGHT2_COL] = new Knight(WHITE_KNIGHT, Point(W_KNIGHT2_ROW, W_KNIGHT2_COL), Player(W));
	this->board[W_ROOK2_ROW][W_ROOK2_COL] = new Rook(WHITE_ROOK, Point(W_ROOK2_ROW, W_ROOK2_COL), Player(W));

	// Adding white pawns
	for (int i = 0; i < COLS; i++)
	{
		this->board[WHITE_PAWNS_ROW][i] = new Pawn(WHITE_PAWN, Point(WHITE_PAWNS_ROW, i), Player(W));
	}
}


/**
 @brief		Destructor - Deletes all the dynamically allocated pieces on the board.
 */
Board::~Board()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; ++col)
		{
			if (this->board[row][col] != nullptr)
			{
				delete this->board[row][col];
			}
		}
	}
}


/**
 @brief		Returns the number of rows in the board.
 @return	The number of rows in the board.
 */
int Board::getRows() const
{
	return this->_rows;
}


/**
 @brief		Returns the number of columns in the board.
 @return	The number of columns in the board.
 */
int Board::getCols() const
{
	return this->_cols;
}


/**
 @brief		Deep copy assignment operator of the Board class.
 @param		other		The other Board to copy.
 @return	void.
 */
void Board::operator=(const Board& other)
{
	this->_rows = other._rows;
	this->_cols = other._cols;

	// Copying the other board
	for (int row = 0; row < this->_rows; row++)
	{
		for (int col = 0; col < this->_cols; ++col)
		{
			*this->board[row][col] = *other.board[row][col];
		}
	}
}
