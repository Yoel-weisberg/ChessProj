#include "Piece.h"

Piece::Piece(const std::string type, const Point location, const Pleyer color,std::vector<Piece>& board)
	: _type(type), _location(location), _color(color), _board(board)
{
}
