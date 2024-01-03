#include "Piece.h"


/**
 @brief		Constructor - Inializes the type, location, color and board (reference) of the piece.
 */
Piece::Piece(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove)
	: _type(type), _location(location), _color(color), _board(board), _isFirstMove(isFirstMove) {}


/**
 @brief		Returns the type of the piece.
 @return	The type of the piece.
 */
char Piece::getType() const
{
	return this->_type;
}


/**
 @brief		Returns the location of the piece.
 @return	The location of the piece.
 */
Point Piece::getLocation() const
{
	return this->_location;
}


/**
 @brief		Returns the color of the piece.
 @return	The color of the piece.
 */
Player Piece::getColor() const
{
	return this->_color;
}


/**
 @brief		Returns if the piece is in its first move or not.
 @return	True if the piece is in its first move, false otherwise.
 */
bool Piece::isFirstMove() const
{
	return _isFirstMove;
}


/**
 @brief		Sets the first move attribute of the piece to false.
 @return	void.
 */
void Piece::falseFirstMove()
{
	this->_isFirstMove = false;
}


/**
 @brief		Returns the board-reference of the piece.
 @return	The board-reference of the piece.
 */
std::vector<Piece*> Piece::getBoard() const
{
	return this->_board;
}


/**
 @brief		Checks if the Piece can move to the given destination point.
 @return	The return code of the move (VALID_MOVE, ILLEGAL_MOVE_FOR_PIECE)
 */
returnCode Piece::checkIfLegallyForPiece(const Point& dst) const
{
	if (this->checkIfTripLegallyForPiece(dst) && this->checkIfPiecesInTrip(dst))
	{
		return VALID_MOVE;
	}

	return ILLEGAL_MOVE_FOR_PIECE;
}


/**
 @brief		operator= ---> Copies the member's values of the given piece to the calling piece.
 @param		other	The piece to copy from.
 @return	void.
 */
void Piece::operator=(const Piece& other)
{
	this->_color = other.getColor();
	this->_location = other.getLocation();
	this->_type = other.getType();
}


/**
 @brief		Returns the piece at the given location from the given board.
 @param		board	The board to get the piece from.
 @param		row		The row of the piece.
 @param		col		The column of the piece.
 @return	The piece at the given location from the given board.
 */
Piece* Piece::getElementAtLoc(const std::vector<Piece*>& board, const int& row, const int& col)
{
	return board[ROWS * row + col];
}


/**
 @brief		Sets the piece at the given location in the given board to the given value.
 @param		board		The board to set the new piece in.
 @param		row			The row of the piece.
 @param		col			The column of the piece.
 @param		newValue	The new Piece to set at the given location.
 @return	void.
 */
void Piece::setElementAtLoc(std::vector<Piece*>& board, const int& row, const int& col, Piece* newValue)
{
	board[ROWS * row + col] = newValue;
}


/**
 @brief		Checks if the piece can castle to the given destination point.
 @param		dst		The destination point to castle to.
 @return	True if the piece can castle to the given destination point, false otherwise.
 */
bool Piece::checkForCastling(const Point& dst) const
{
	return false;
}
