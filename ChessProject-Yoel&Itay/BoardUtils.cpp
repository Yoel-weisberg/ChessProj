#include "BoardUtils.h"


/**
 @brief		Returns the Player that the Piece in the given Point belongs to.
 @param		board		The board to check.
 @param		point		The Point to check.
 @return	The Player that the Piece in the given Point belongs to.
 */
Player BoardUtils::getPointPlayer(const Board& board, const Point& point)
{
	return board.board[point.getRow()][point.getCol()]->getColor();
}


/**
 @brief		Returns the Point of the King of the given Player.
 @param		board		The board to check.
 @param		player		The Player to find its King.
 @return	The Point of the King of the given Player.
 @note		In chess, there are always 2 kings on the board, the function will always get to the return statement.
 */
Point BoardUtils::findKingPoint(const Board& board, const Player& player)
{
	for (int row = 0; row < board.getRows(); row++)
	{
		for (int col = 0; col < board.getCols(); col++)
		{
			Piece* currentPiece = board.board[row][col];

			if ((currentPiece->getColor() == player) && ((currentPiece->getType() == WHITE_KING) || (currentPiece->getType() == BLACK_KING)))
			{
				return currentPiece->getLocation();
			}
		}
	}
}


/**
 @brief		Returns true if the given Point is in the board boundaries.
 @param		point		The Point to check.
 @return	True if the given Point is in the board boundaries, false otherwise.
 */
bool BoardUtils::isPointInBoundaries(const Point& point)
{
	return ((point.getRow() >= 0) && (point.getRow() < ROWS)) &&
		((point.getCol() >= 0) && (point.getCol() < COLS));
}


/**
 @brief		Returns true if the given Player's King is in check.
 @param		board		The board to check.
 @param		player		The Player to check if its King is in check.
 @return	True if the given Player's King is in check, false otherwise.
 */
bool BoardUtils::isKingInCheck(const Board& board, const Player& player)
{
	Point currentPlayerKing = findKingPoint(board, player);

	for (int row = 0; row < board.getRows(); row++)
	{
		for (int col = 0; col < board.getCols(); col++)
		{
			Piece* currentPiece = board.board[row][col];

			// searching for opponent's Pieces
			if (!(currentPiece->getColor() == player) && ((currentPiece->getColor().getPlayerColor() != EMPTY_PLAYER)))
			{
				// Checking if the opponent's Pieces threaten the current player's King
				if (currentPiece->checkIfLegallyForPiece(currentPlayerKing, board) && currentPiece->checkIfPiecesInTrip(currentPlayerKing, board))
				{
					return true;
				}
			}
		}
	}

	return false;
}


/**
 @brief		Returns the return code of the given move.
 @param		board		The board to check.
 @param		turn		The Player that is playing now.
 @param		src			The Point to move the Piece from.
 @param		dst			The Point to move the Piece to.
 @return	The return code of the given move.
 */
returnCode BoardUtils::isMoveValid(const Board& board, const Player& turn, const Point& src, const Point& dst)
{
	// Invalid moves check
	bool isInBoundaries = isPointInBoundaries(src) && isPointInBoundaries(dst);
	if (!isInBoundaries)
	{
		return INVALID_INDEXES;
	}

	bool areSrcAndDstDifferent = !(dst == src);
	if (!areSrcAndDstDifferent)
	{
		return SAME_SRC_DST_POINTS;
	}

	bool isCurrentInSrc = board.board[src.getRow()][src.getCol()]->getColor() == turn;
	if (!isCurrentInSrc)
	{
		return MISSING_CURRENT_IN_SRC;
	}

	bool isCurrentNotInDst = !(board.board[dst.getRow()][dst.getCol()]->getColor() == turn);
	if (!isCurrentNotInDst)
	{
		return DST_OCCUPIED_BY_CURRENT;
	}
	
	bool isTripLegal = board.board[src.getRow()][src.getCol()]->checkIfLegallyForPiece(dst, board) && board.board[src.getRow()][src.getCol()]->checkIfPiecesInTrip(dst, board);
	if (!isTripLegal)
	{
		return ILLEGAL_MOVE_FOR_PIECE;
	}

	// --- CHECKING IF THE MOVE CAUSES CHECK ON THE CURRENT PLAYER ---
	// Creating a copy of the board
	Board newBoard = Board();
	newBoard = board;

	// Performing the move on the copied board
	*newBoard.board[dst.getRow()][dst.getCol()] = *newBoard.board[src.getRow()][src.getCol()];	// Copying the Piece in src Point to dst Point (moving the Piece)
	newBoard.board[src.getRow()][src.getCol()]->turnIntoEmpty();								// Emptying the src Point from Piece (Removing the Piece from the src Point)

	// Checking if the move causes Check on the current player
	bool CausesSelfCheck = isKingInCheck(newBoard, turn);
	if (CausesSelfCheck)
	{
		return CAUSES_CHECK_ON_CURRENT;
	}
	newBoard.~Board();		// Deleting the copied board


	// If the function got here - the move is guaranteed to be valid
	// Checking if the move caused Check on the opponent's King
	if (isKingInCheck(board, Player(turn.getPlayerColor() == W ? B : W)))
	{
		return CHECK_MOVE;
	}

	return VALID_MOVE;
}


/**
 @brief		Moves the Piece in the given src Point to the given dst Point.
 @param		board		The board to move the Piece in.
 @param		turn		The Player that is playing now.
 @param		src			The Point to move the Piece from.
 @param		dst			The Point to move the Piece to.
 @return	The return code of the move.
 */
returnCode BoardUtils::movePiece(const Board& board, const Player& turn, const Point& src, const Point& dst)
{
	returnCode isValidMove = isMoveValid(board, turn, src, dst);

	if (isValidMove == VALID_MOVE || isValidMove == CHECK_MOVE)
	{
		*board.board[dst.getRow()][dst.getCol()] = *board.board[src.getRow()][src.getCol()];	// Copying the Piece in src Point to dst Point
		board.board[src.getRow()][src.getCol()]->turnIntoEmpty();		// Emptying the src Point from Piece
	}

	return isValidMove;
}


/**
 @brief		Prints the given board.
 @param		board		The board to print.
 @return	void.
 */
void BoardUtils::printBoard(const Board& board)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			std::cout << board.board[row][col]->getType() << " ";
		}
		std::cout << std::endl;
	}
}
