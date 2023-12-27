#include "Piece.h"

Piece::Piece(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board)
	: _type(type), _location(location), _color(color), _board(board)
{
}


Point Piece::getLocation() const
{
	return this->_location;
}

Player Piece::getColor() const
{
	return this->_color;
}

char Piece::getType() const
{
	return this->_type;
}

std::vector<Piece*> Piece::getBoard() const
{
	return this->_board;
}

returnCode Piece::checkIfLegallyForPiece(const Point& dst) const
{
	if (checkIfTripLegallyForPiece(dst) && checkIfPiecesInTrip(dst))
	{
		return VALID_MOVE;
	}
	else
	{
		return ILLEGAL_MOVE_FOR_PIECE;
	}
}

void Piece::operator=(const Piece& other)
{
	this->_color = other.getColor();
	this->_location = other.getLocation();
	this->_type = other.getType();
}

void Piece::turnIntoEmpty()
{
	this->_color.setColor(EMPTY_PLAYER);
	this->_type = EMPTY;
}

Piece* Piece::getElementAtLoc(const std::vector<Piece*>& board, const int& row, const int& col)
{
	return board[ROWS * row + col];
}

void Piece::setElementAtLoc(std::vector<Piece*>& board, const int& row, const int& col, Piece* newValue)
{
	board[ROWS * row + col] = newValue;
}
