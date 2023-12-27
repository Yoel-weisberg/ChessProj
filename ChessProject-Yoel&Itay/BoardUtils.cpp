#include "BoardUtils.h"


/**
 @brief		Returns the Player that the Piece in the given Point belongs to.
 @param		board		The board to check.
 @param		point		The Point to check.
 @return	The Player that the Piece in the given Point belongs to.
 */
Player BoardUtils::getPointPlayer(const std::vector<Piece*>& board, const Point& point)
{
	return Piece::getElementAtLoc(board, point.getRow(), point.getCol())->getColor();
}


/**
 @brief		Returns the Point of the King of the given Player.
 @param		board		The board to check.
 @param		player		The Player to find its King.
 @return	The Point of the King of the given Player.
 @note		In chess, there are always 2 kings on the board, the function will always get to the return statement.
 */
Point BoardUtils::findKingPoint(const std::vector<Piece*>& board, const Player& player)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			Piece* currentPiece = Piece::getElementAtLoc(board, row, col);

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
bool BoardUtils::isKingInCheck(const std::vector<Piece*>& board, const Player& player)
{
	Point currentPlayerKing = findKingPoint(board, player);

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			Piece* currentPiece = Piece::getElementAtLoc(board, row, col);

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
returnCode BoardUtils::isMoveValid(const std::vector<Piece*>& board, const Player& turn, const Point& src, const Point& dst)
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

	bool isCurrentInSrc = Piece::getElementAtLoc(board, src.getRow(), src.getCol())->getColor() == turn;
	if (!isCurrentInSrc)
	{
		return MISSING_CURRENT_IN_SRC;
	}

	bool isCurrentNotInDst = !(Piece::getElementAtLoc(board, src.getRow(), src.getCol())->getColor() == turn);
	if (!isCurrentNotInDst)
	{
		return DST_OCCUPIED_BY_CURRENT;
	}
	
	bool isTripLegal = Piece::getElementAtLoc(board, src.getRow(), src.getCol())->checkIfLegallyForPiece(dst, board) &&
					   Piece::getElementAtLoc(board, src.getRow(), src.getCol())->checkIfPiecesInTrip(dst, board);
	if (!isTripLegal)
	{
		return ILLEGAL_MOVE_FOR_PIECE;
	}

	// --- CHECKING IF THE MOVE CAUSES CHECK ON THE CURRENT PLAYER ---
	// Creating a copy of the board
	std::vector<Piece*> boardCopy;
	BoardUtils::cloneBoard(board, boardCopy);

	// Performing the move on the copied board
	Piece::setElementAtLoc(boardCopy, dst.getRow(), dst.getCol(), Piece::getElementAtLoc(board, src.getRow(), src.getCol()));		// Copying the Piece in src Point to dst Point (moving the Piece)
	Piece::getElementAtLoc(boardCopy, src.getRow(), src.getCol())->turnIntoEmpty();		// Emptying the src Point from Piece (Removing the Piece from the src Point)

	// Checking if the move causes Check on the current player
	bool CausesSelfCheck = isKingInCheck(boardCopy, turn);
	if (CausesSelfCheck)
	{
		return CAUSES_CHECK_ON_CURRENT;
	}
	BoardUtils::deleteBoard(boardCopy);		// Deleting the copied board


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
returnCode BoardUtils::movePiece(std::vector<Piece*>& board, const Player& turn, const Point& src, const Point& dst)
{
	returnCode isValidMove = isMoveValid(board, turn, src, dst);

	if (isValidMove == VALID_MOVE || isValidMove == CHECK_MOVE)
	{
		Piece::setElementAtLoc(board, dst.getRow(), dst.getCol(), Piece::getElementAtLoc(board, src.getRow(), src.getCol()));		// Copying the Piece in src Point to dst Point
		Piece::getElementAtLoc(board, src.getRow(), src.getCol())->turnIntoEmpty();			// Emptying the src Point from Piece
	}

	return isValidMove;
}


/**
 @brief		Clone the given src board into the given dst board.
 @param		srcBoard		The board to clone.
 @param		dstBoard		The board to clone into.
 @return	void.
 */
void BoardUtils::cloneBoard(const std::vector<Piece*>& srcBoard, std::vector<Piece*>& dstBoard)
{
	for (int i = 0; i < ROWS * COLS; i++)
	{
		if (srcBoard[i]->getType() == EMPTY)
		{
			dstBoard[i] = new Empty(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		if (srcBoard[i]->getType() == 'R' || srcBoard[i]->getType() == 'r')
		{
			dstBoard[i] = new Rook(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		if (srcBoard[i]->getType() == 'N' || srcBoard[i]->getType() == 'n')
		{
			dstBoard[i] = new Knight(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		if (srcBoard[i]->getType() == 'B' || srcBoard[i]->getType() == 'b')
		{
			dstBoard[i] = new Bishop(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		if (srcBoard[i]->getType() == 'Q' || srcBoard[i]->getType() == 'q')
		{
			dstBoard[i] = new Queen(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		if (srcBoard[i]->getType() == 'K' || srcBoard[i]->getType() == 'k')
		{
			dstBoard[i] = new King(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		if (srcBoard[i]->getType() == 'P' || srcBoard[i]->getType() == 'p')
		{
			dstBoard[i] = new Pawn(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
	}
}


/**
 @brief		Frees the memory of the given board.
 @param		boardToDelete		The board to free its memory.
 @return	void.
 */
void BoardUtils::deleteBoard(std::vector<Piece*>& boardToDelete)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; ++col)
		{
			if (Piece::getElementAtLoc(boardToDelete, row, col) != nullptr)
			{
				delete Piece::getElementAtLoc(boardToDelete, row, col);
			}
		}
	}
}


/**
 @brief		Prints the given board.
 @param		board		The board to print.
 @return	void.
 */
void BoardUtils::printBoard(const std::vector<Piece*>& board)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			std::cout << Piece::getElementAtLoc(board, row, col)->getType() << " ";
		}
		std::cout << std::endl;
	}
}
