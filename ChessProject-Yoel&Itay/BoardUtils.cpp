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
 @brief		Returns true if the given Point is in the board boundaries.
 @param		point		The Point to check.
 @return	True if the given Point is in the board boundaries, false otherwise.
 */
bool BoardUtils::isPointInBoundaries(const Point& point)
{
	return ((point.getRow() >= 0) && (point.getRow() < ROWS)) &&
		   ((point.getCol() >= 0) && (point.getCol() < COLS));
}


bool BoardUtils::isKingInCheck(const Board& board, const Player& player)
{
	return false;
}


returnCode BoardUtils::isMoveValid(const Board& board, const Player& turn, const Point& src, const Point& dst)
{
	// Invalid moves check
	bool isInBoundaries = isPointInBoundaries(src) && isPointInBoundaries(dst);
	if (!isInBoundaries)
	{
		return INVALID_INDEXES;
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
	
	// Mobility checks
	bool isLegalForPiece = board.board[src.getRow()][src.getCol()]->checkIfLegallyForPiece(dst, board);
	if (!isLegalForPiece)
	{
		return ILLEGAL_MOVE_FOR_PIECE;
	}

	// Implement a function that checks if a Piece is blocking the way

	bool doesCauseSelfCheck = isKingInCheck(board, turn);
	if (doesCauseSelfCheck)
	{
		return CAUSES_CHECK_ON_CURRENT;
	}

	// If the function got here - the move is valid
	// Need to implement a check to differentiate between: REGULAR MOVE, CHECK ON OPPONENT, CHECKMATE ON OPPONENT
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
