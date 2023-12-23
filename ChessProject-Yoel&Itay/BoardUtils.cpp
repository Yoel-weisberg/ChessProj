#include "BoardUtils.h"


/**
 @brief		Returns the Player that the Piece in the given Point belongs to.
 @param		board		The board to check.
 @param		point		The Point to check.
 @return	The Player that the Piece in the given Point belongs to.
 */
Player BoardUtils::getPointPlayer(const Piece* (&board)[ROWS][COLS], const Point& point)
{
	return board[point.getRow()][point.getCol()]->getColor();
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


bool BoardUtils::isKingInCheck(const Piece* (&board)[ROWS][COLS], const Player& player)
{
	return false;
}


returnCode BoardUtils::isMoveValid(const Piece* (&board)[ROWS][COLS], const Player& turn, const Point& src, const Point& dst)
{
	// Invalid moves check
	bool isInBoundaries = isPointInBoundaries(src) && isPointInBoundaries(dst);
	if (!isInBoundaries)
	{
		return INVALID_INDEXES;
	}

	bool isCurrentInSrc = board[src.getRow()][src.getCol()]->getColor() == turn;
	if (!isCurrentInSrc)
	{
		return MISSING_CURRENT_IN_SRC;
	}

	bool isCurrentNotInDst = !(board[dst.getRow()][dst.getCol()]->getColor() == turn);
	if (!isCurrentNotInDst)
	{
		return DST_OCCUPIED_BY_CURRENT;
	}
	
	// Mobility checks
	bool isLegalForPiece = board[src.getRow()][src.getCol()]->checkIfLegallyForPiece(dst);
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


bool BoardUtils::movePiece(Piece* (&board)[ROWS][COLS], const Player& turn, const Point& src, const Point& dst)
{
	bool isValidMove = isMoveValid(board, turn, src, dst);

	if (isValidMove == VALID_MOVE || isValidMove == CHECK_MOVE)
	{
		// Copy the Piece in src Point to dst Point
		// Empty the src Point from Piece
	}

	return isValidMove;
}


/**
 @brief		Prints the given board.
 @param		board		The board to print.
 @return	void.
 */
void BoardUtils::printBoard(const Piece* (&board)[ROWS][COLS])
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			std::cout << board[row][col]->getType() << " ";
		}
		std::cout << std::endl;
	}
}
