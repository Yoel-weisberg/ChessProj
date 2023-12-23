#include "Piece.h"

Piece::Piece(const char& type, const Point& location, const Player& color, std::vector<Piece>& board)
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

void Piece::operator=(const Piece& other)
{
	this->_color = other.getColor();
	this->_location = other.getLocation();
	this->_type = other.getType();
}

void Piece::turnIntoEmpty()
{
	this->_color.setColor(EMPTY);
	this->_type = 'e';
}
