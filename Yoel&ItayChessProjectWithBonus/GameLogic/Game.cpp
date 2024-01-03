#include "Game.h"


/**
 @brief		Constructor - Initializes the turn and the board of the game object.
 @note		The board is initialized with 64 elements, 32 of them are nullptrs and the other 32 are pieces.
 */
Game::Game() : _turn(Player(WHITE_PLAYER))
{
    // Initializing board vector with 64 nullptrs using push_back
    this->_board.reserve(ROWS * COLS);
    for (int i = 0; i < ROWS * COLS; i++)
    {
        this->_board.push_back(nullptr);
    }

    // Adding black pieces
    Piece::setElementAtLoc(this->_board, B_ROOK1_ROW, B_ROOK1_COL, new Rook(BLACK_ROOK, Point(B_ROOK1_ROW, B_ROOK1_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_KNIGHT1_ROW, B_KNIGHT1_COL, new Knight(BLACK_KNIGHT, Point(B_KNIGHT1_ROW, B_KNIGHT1_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_BISHOP1_ROW, B_BISHOP1_COL, new Bishop(BLACK_BISHOP, Point(B_BISHOP1_ROW, B_BISHOP1_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_QUEEN_ROW, B_QUEEN_COL, new Queen(BLACK_QUEEN, Point(B_QUEEN_ROW, B_QUEEN_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_KING_ROW, B_KING_COL, new King(BLACK_KING, Point(B_KING_ROW, B_KING_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_BISHOP2_ROW, B_BISHOP2_COL, new Bishop(BLACK_BISHOP, Point(B_BISHOP2_ROW, B_BISHOP2_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_KNIGHT2_ROW, B_KNIGHT2_COL, new Knight(BLACK_KNIGHT, Point(B_KNIGHT2_ROW, B_KNIGHT2_COL), Player(BLACK_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, B_ROOK2_ROW, B_ROOK2_COL, new Rook(BLACK_ROOK, Point(B_ROOK2_ROW, B_ROOK2_COL), Player(BLACK_PLAYER), this->_board));

    // Adding black pawns
    for (int i = 0; i < COLS; i++)
    {
        Piece::setElementAtLoc(this->_board, BLACK_PAWNS_ROW, i, new Pawn(BLACK_PAWN, Point(BLACK_PAWNS_ROW, i), Player(BLACK_PLAYER), this->_board));
    }

    // Filling the required points with empty Pieces
    for (int row = EMPTY_POINTS_ROW_START; row < EMPTY_POINTS_ROW_END; row++)
    {
        for (int col = 0; col < COLS; col++) {
            Piece::setElementAtLoc(this->_board, row, col, new Empty('#', Point(row, col), Player(EMPTY_PLAYER), this->_board));
        }
    }

    // Adding white pieces
    Piece::setElementAtLoc(this->_board, W_ROOK1_ROW, W_ROOK1_COL, new Rook(WHITE_ROOK, Point(W_ROOK1_ROW, W_ROOK1_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_KNIGHT1_ROW, W_KNIGHT1_COL, new Knight(WHITE_KNIGHT, Point(W_KNIGHT1_ROW, W_KNIGHT1_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_BISHOP1_ROW, W_BISHOP1_COL, new Bishop(WHITE_BISHOP, Point(W_BISHOP1_ROW, W_BISHOP1_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_QUEEN_ROW, W_QUEEN_COL, new Queen(WHITE_QUEEN, Point(W_QUEEN_ROW, W_QUEEN_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_KING_ROW, W_KING_COL, new King(WHITE_KING, Point(W_KING_ROW, W_KING_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_BISHOP2_ROW, W_BISHOP2_COL, new Bishop(WHITE_BISHOP, Point(W_BISHOP2_ROW, W_BISHOP2_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_KNIGHT2_ROW, W_KNIGHT2_COL, new Knight(WHITE_KNIGHT, Point(W_KNIGHT2_ROW, W_KNIGHT2_COL), Player(WHITE_PLAYER), this->_board));
    Piece::setElementAtLoc(this->_board, W_ROOK2_ROW, W_ROOK2_COL, new Rook(WHITE_ROOK, Point(W_ROOK2_ROW, W_ROOK2_COL), Player(WHITE_PLAYER), this->_board));

    // Adding white pawns
    for (int i = 0; i < COLS; i++)
    {
        Piece::setElementAtLoc(this->_board, WHITE_PAWNS_ROW, i, new Pawn(WHITE_PAWN, Point(WHITE_PAWNS_ROW, i), Player(WHITE_PLAYER), this->_board));
    }
}

Game::Game(const std::vector<Piece*>& board) : _board(board), _turn(WHITE_PLAYER) {}



/**
 @brief     Destructor - Deletes the board of the game object.
 */
Game::~Game()
{
    BoardUtils::deleteBoard(this->_board);
}


/**
 @brief     Returns the board of the game.
 @return	The board of the game.
 */
std::vector<Piece*> Game::getBoard() const
{
    return this->_board;
}


/**
 @brief		Returns the current turn in the game.
 @return	The current turn in the game.
 */
Player Game::getTurn() const
{
    return this->_turn;
}

void Game::changeTurn(const Player turn)
{
    this->_turn = turn;
}


/**
 @brief		Switches the turn in the game.
 @return	void
 */
void Game::switchTurn()
{
    if (this->_turn.getPlayerColor() == WHITE_PLAYER)
    {
        this->_turn.setColor(BLACK_PLAYER);
    }
    else
    {
        this->_turn.setColor(WHITE_PLAYER);
    }
}


/**
 @brief     Returns the board as a string.
 @return    The board as a string.
 */
char* Game::returnBoardString() const
{
    char boardString[ROWS * COLS + 1] = "";

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            boardString[row * ROWS + col] = Piece::getElementAtLoc(this->_board, row, col)->getType();
        }
    }
    boardString[ROWS * COLS] = NULL;
    return boardString;
}


/**
 @brief		Moves a piece on the game board.
 @return	The returnCode of the move.
 */
returnCode Game::moveOnBoard(const Point& src, const Point& dst)
{
    return BoardUtils::movePiece(this->_board, this->_turn, src, dst);
}
