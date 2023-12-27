#include "Game.h"


Game::Game() : _turn(Player(W)) {
    // Add 64 elements to the vector using push_back
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece::setElementAtLoc(this->_board, i, j, nullptr);
        }
    }

    // Adding black pieces
    Piece::setElementAtLoc(this->_board, B_ROOK1_ROW, B_ROOK1_COL, new Rook(BLACK_ROOK, Point(B_ROOK1_ROW, B_ROOK1_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_KNIGHT1_ROW, B_KNIGHT1_COL, new Knight(BLACK_KNIGHT, Point(B_KNIGHT1_ROW, B_KNIGHT1_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_BISHOP1_ROW, B_BISHOP1_COL, new Bishop(BLACK_BISHOP, Point(B_BISHOP1_ROW, B_BISHOP1_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_QUEEN_ROW, B_QUEEN_COL, new Queen(BLACK_QUEEN, Point(B_QUEEN_ROW, B_QUEEN_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_KING_ROW, B_KING_COL, new King(BLACK_KING, Point(B_KING_ROW, B_KING_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_BISHOP2_ROW, B_BISHOP2_COL, new Bishop(BLACK_BISHOP, Point(B_BISHOP2_ROW, B_BISHOP2_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_KNIGHT2_ROW, B_KNIGHT2_COL, new Knight(BLACK_KNIGHT, Point(B_KNIGHT2_ROW, B_KNIGHT2_COL), Player(B), this->_board));
    Piece::setElementAtLoc(this->_board, B_ROOK2_ROW, B_ROOK2_COL, new Rook(BLACK_ROOK, Point(B_ROOK2_ROW, B_ROOK2_COL), Player(B), this->_board));

    // Adding black pawns
    for (int i = 0; i < 8; i++) {
        Piece::setElementAtLoc(this->_board, BLACK_PAWNS_ROW, i, new Pawn(BLACK_PAWN, Point(BLACK_PAWNS_ROW, i), Player(B), this->_board));
    }

    // Filling the required points with empty Pieces
    for (int row = EMPTY_POINTS_ROW_START; row < EMPTY_POINTS_ROW_END; row++) {
        for (int col = 0; col < 8; col++) {
            Piece::setElementAtLoc(this->_board, row, col, new Empty('#', Point(row, col), Player(EMPTY_PLAYER), this->_board));
        }
    }

    // Adding white pieces
    Piece::setElementAtLoc(this->_board, W_ROOK1_ROW, W_ROOK1_COL, new Rook(WHITE_ROOK, Point(W_ROOK1_ROW, W_ROOK1_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_KNIGHT1_ROW, W_KNIGHT1_COL, new Knight(WHITE_KNIGHT, Point(W_KNIGHT1_ROW, W_KNIGHT1_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_BISHOP1_ROW, W_BISHOP1_COL, new Bishop(WHITE_BISHOP, Point(W_BISHOP1_ROW, W_BISHOP1_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_QUEEN_ROW, W_QUEEN_COL, new Queen(WHITE_QUEEN, Point(W_QUEEN_ROW, W_QUEEN_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_KING_ROW, W_KING_COL, new King(WHITE_KING, Point(W_KING_ROW, W_KING_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_BISHOP2_ROW, W_BISHOP2_COL, new Bishop(WHITE_BISHOP, Point(W_BISHOP2_ROW, W_BISHOP2_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_KNIGHT2_ROW, W_KNIGHT2_COL, new Knight(WHITE_KNIGHT, Point(W_KNIGHT2_ROW, W_KNIGHT2_COL), Player(W), this->_board));
    Piece::setElementAtLoc(this->_board, W_ROOK2_ROW, W_ROOK2_COL, new Rook(WHITE_ROOK, Point(W_ROOK2_ROW, W_ROOK2_COL), Player(W), this->_board));

    // Adding white pawns
    for (int i = 0; i < 8; i++) {
        Piece::setElementAtLoc(this->_board, WHITE_PAWNS_ROW, i, new Pawn(WHITE_PAWN, Point(WHITE_PAWNS_ROW, i), Player(W), this->_board));
    }
}


std::vector<Piece*> Game::getBoard() const
{
	return this->_board;
}


std::vector<Piece*> Game::getBoard() const
{
	return std::vector<Piece*>();
}


/**
 @brief		Switches the turn in the game.
 @return	void
 */
void Game::switchTurn()
{
	if (this->_turn.getPlayerColor() == W)
	{
		this->_turn.setColor(B);
	}
	else
	{
		this->_turn.setColor(W);
	}
}


/**
 @brief		Moves a piece on the game board.
 @return	The returnCode of the move.
 */
returnCode Game::moveOnBoard(const Point& src, const Point& dst)
{
	returnCode res = BoardUtils::movePiece(this->_board, this->_turn, src, dst);
	return res;
}
