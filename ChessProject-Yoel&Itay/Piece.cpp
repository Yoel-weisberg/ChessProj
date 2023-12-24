#include "Piece.h"

Piece::Piece(const char& type, const Point& location, const Player& color)
	: _type(type), _location(location), _color(color)
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

returnCode Piece::checkIfLegallyForPiece(const Point& dst, const Board& board) const
{
	if (checkIfPiecesInTrip(dst, board) && checkIfTripLegallyForPiece(dst, board))
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
	this->_color.setColor(EMPTY);
	this->_type = '#';
}
