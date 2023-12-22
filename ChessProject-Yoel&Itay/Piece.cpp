#include "Piece.h"

Piece::Piece(const std::string type, const Point location, const Pleyer color,std::vector<Piece>& board)
	: _type(type), _location(location), _color(color), _board(board)
{
}

int Piece::move(const Point& dst)
{
	if (this->checkIfLeagel(dst) != 0)
	{
		return this->checkIfLeagel(dst);
	}
	else if (this->checkIfLegallyForPiece(dst) != 0)
	{
		return this->checkIfLegallyForPiece(dst);
	}
	this->_location = dst;
	return 0;
}

Point Piece::getLocation() const
{
	return this->_location;
}

Pleyer Piece::getColor() const
{
	return this->_color;
}
