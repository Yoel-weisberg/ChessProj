#include "BoardUtils.h"


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
	return Point(-1, -1);		// Should never get here
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
	returnCode isTripLegal = UNDEFINED;

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			Piece* currentPiece = Piece::getElementAtLoc(board, row, col);

			// searching for opponent's Pieces
			if ((currentPiece->getColor().getPlayerColor() != player.getPlayerColor()) && (currentPiece->getColor().getPlayerColor() != EMPTY_PLAYER))
			{
				// Checking if the opponent's Pieces threaten the current player's King
				isTripLegal = currentPiece->checkIfLegallyForPiece(currentPlayerKing);
				if (isTripLegal == VALID_MOVE)		// All types of valid moves (Regular move, Check move, En-Passant move)
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

	bool isCurrentNotInDst = !(Piece::getElementAtLoc(board, dst.getRow(), dst.getCol())->getColor() == turn);
	if (!isCurrentNotInDst)
	{
		return DST_OCCUPIED_BY_CURRENT;
	}

	returnCode isTripLegal = Piece::getElementAtLoc(board, src.getRow(), src.getCol())->checkIfLegallyForPiece(dst);
	if ((isTripLegal != VALID_MOVE) && (isTripLegal != CHECK_MOVE))
	{
		return ILLEGAL_MOVE_FOR_PIECE;
	}

	// --- CHECKING IF THE MOVE CAUSES CHECK ON THE CURRENT PLAYER ---
	// Creating a copy of the board
	std::vector<Piece*> boardCopy;
	BoardUtils::cloneBoard(board, boardCopy);

	// Performing the move on the copied board
	duplicatePieceOnBoard(boardCopy, src, dst);		// Deep copying the Piece in src Point to dst Point (duplicating the Piece)
	removePieceFromBoard(boardCopy, src);			// Deleting the Piece in src Point from the copied board

	// Checking if the move causes Check on the current player
	bool CausesSelfCheck = isKingInCheck(boardCopy, turn);
	if (CausesSelfCheck)
	{
		return CAUSES_CHECK_ON_CURRENT;
	}
	

	// If the function got here - the move is guaranteed to be valid
	// Checking if the move caused Check on the opponent's King
	if (isKingInCheck(boardCopy, Player(turn.getPlayerColor() == WHITE_PLAYER ? BLACK_PLAYER : WHITE_PLAYER)))
	{
		return CHECK_MOVE;
	}
	BoardUtils::deleteBoard(boardCopy);		// Deleting the copied board

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
		duplicatePieceOnBoard(board, src, dst);		// Deep copying the Piece in src Point to dst Point (duplicating the Piece)
		removePieceFromBoard(board, src);			// Deleting the Piece in src Point from the board

		if (Pawn::enPassantOccured)
		{
			removePieceFromBoard(board, Pawn::toWherePawnMoved2Squares);
			Pawn::enPassantOccured = false;

			return ENPASSANT_MOVE;
		}

		Piece::getElementAtLoc(board, dst.getRow(), dst.getCol())->falseFirstMove();
	}
	return isValidMove;
}


/**
 @brief		Duplicates the Piece in the given src Point to the given dst Point.
 @param		board		The board to duplicate the Piece on.
 @param		src			The Point to duplicate the Piece from.
 @param		dst			The Point to duplicate the Piece to.
 @return	void.
 */
void BoardUtils::duplicatePieceOnBoard(std::vector<Piece*>& board, const Point& src, const Point& dst)
{
	deletePiece(Piece::getElementAtLoc(board, dst.getRow(), dst.getCol()));		// Deleting the Piece in dst Point from the board
	Piece::setElementAtLoc(board, dst.getRow(), dst.getCol(), clonePiece(Piece::getElementAtLoc(board, src.getRow(), src.getCol()), Point(dst.getRow(), dst.getCol()), board));		// Deep copying the Piece in src Point to dst Point (duplicating the Piece)
}


/**
 @brief		Removes the Piece in the given Point from the given board.
 @param		board		The board to remove the Piece from.
 @param		point		The Point to remove the Piece from.
 @return	void.
 */
void BoardUtils::removePieceFromBoard(std::vector<Piece*>& board, const Point& point)
{
	deletePiece(Piece::getElementAtLoc(board, point.getRow(), point.getCol()));		// Deleting the Piece in the given Point from the board
	Piece::setElementAtLoc(board, point.getRow(), point.getCol(), new Empty('#', Point(point.getRow(), point.getCol()), Player(EMPTY_PLAYER), board));
}


/**
 @brief		Clones the given Piece into a new Piece with the given Point and board
 @param		pieceToClone		The Piece to clone.
 @param		pointToSet			The Point to set to the cloned Piece.
 @param		boardToSet			The board to set to the cloned Piece.
 @return	The new cloned Piece.
 */
Piece* BoardUtils::clonePiece(const Piece* pieceToClone, const Point& pointToSet, std::vector<Piece*>& boardToSet)
{
	const char pieceType = pieceToClone->getType();
	const Player pieceColor = pieceToClone->getColor();

	if (pieceType == WHITE_ROOK || pieceType == BLACK_ROOK)
	{
		return new Rook(pieceType, pointToSet, pieceColor, boardToSet);
	}
	else if (pieceType == WHITE_KNIGHT || pieceType == BLACK_KNIGHT)
	{
		return new Knight(pieceType, pointToSet, pieceColor, boardToSet);
	}
	else if (pieceType == WHITE_BISHOP || pieceType == BLACK_BISHOP)
	{
		return new Bishop(pieceType, pointToSet, pieceColor, boardToSet);
	}
	else if (pieceType == WHITE_QUEEN || pieceType == BLACK_QUEEN)
	{
		return new Queen(pieceType, pointToSet, pieceColor, boardToSet);
	}
	else if (pieceType == WHITE_KING || pieceType == BLACK_KING)
	{
		return new King(pieceType, pointToSet, pieceColor, boardToSet);
	}
	else if (pieceType == WHITE_PAWN || pieceType == BLACK_PAWN)
	{
		return new Pawn(pieceType, pointToSet, pieceColor, boardToSet);
	}
	else
	{
		return new Empty(pieceType, pointToSet, pieceColor, boardToSet);
	}
}


/**
 @brief		Deletes the given Piece.
 @param		pieceToDelete		The Piece to delete.
 @return	void.
 */
void BoardUtils::deletePiece(const Piece* pieceToDelete)
{
	delete pieceToDelete;
}


/**
 @brief		Clone the given src board into the given dst board (Deep Copy).
 @param		srcBoard		The board to clone.
 @param		dstBoard		The board to clone into.
 @return	void.
 */
void BoardUtils::cloneBoard(const std::vector<Piece*>& srcBoard, std::vector<Piece*>& dstBoard)
{
	dstBoard.reserve(ROWS * COLS);
	for (int i = 0; i < ROWS * COLS; i++)
	{
		dstBoard.push_back(nullptr);
	}

	for (int i = 0; i < ROWS * COLS; i++)
	{
		if (srcBoard[i]->getType() == EMPTY)
		{
			dstBoard[i] = new Empty(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		else if (srcBoard[i]->getType() == 'R' || srcBoard[i]->getType() == 'r')
		{
			dstBoard[i] = new Rook(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		else if (srcBoard[i]->getType() == 'N' || srcBoard[i]->getType() == 'n')
		{
			dstBoard[i] = new Knight(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		else if (srcBoard[i]->getType() == 'B' || srcBoard[i]->getType() == 'b')
		{
			dstBoard[i] = new Bishop(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		else if (srcBoard[i]->getType() == 'Q' || srcBoard[i]->getType() == 'q')
		{
			dstBoard[i] = new Queen(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		else if (srcBoard[i]->getType() == 'K' || srcBoard[i]->getType() == 'k')
		{
			dstBoard[i] = new King(srcBoard[i]->getType(), srcBoard[i]->getLocation(), srcBoard[i]->getColor(), dstBoard);
		}
		else if (srcBoard[i]->getType() == 'P' || srcBoard[i]->getType() == 'p')
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
			Piece* currentPiece = Piece::getElementAtLoc(boardToDelete, row, col);
			if (currentPiece != nullptr)
			{
				delete currentPiece;
			}
		}
	}
}


/**
 @brief		Sets a color for the console
 @param		color		The color to set
 @return	void
 */
void BoardUtils::setConsoleColor(unsigned int color)
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}


/**
 @brief		Prints the given board.
 @param		board		The board to print.
 @param		turn		The Player that is playing now (used to highlight the current player's Pieces).
 @return	void.
 */
void BoardUtils::printBoard(const std::vector<Piece*>& board, const Player& turn)
{
	setConsoleColor(CYAN);
	std::cout << "  a b c d e f g h" << std::endl;
	setConsoleColor(WHITE);

	for (int row = 0; row < ROWS; row++)
	{
		setConsoleColor(CYAN);
		std::cout << ROWS - row << " ";
		setConsoleColor(WHITE);

		for (int col = 0; col < COLS; col++)
		{
			if (Piece::getElementAtLoc(board, row, col)->getColor() == turn)
			{
				setConsoleColor(GREEN);
			}
			else if (Piece::getElementAtLoc(board, row, col)->getColor().getPlayerColor() != EMPTY_PLAYER)
			{
				setConsoleColor(GREY);
			}

			std::cout << Piece::getElementAtLoc(board, row, col)->getType() << " ";
			setConsoleColor(WHITE);
		}
		setConsoleColor(CYAN);
		std::cout << ROWS - row << " " << std::endl;
		setConsoleColor(WHITE);
	}

	setConsoleColor(CYAN);
	std::cout << "  a b c d e f g h" << std::endl;
	setConsoleColor(WHITE);
}
