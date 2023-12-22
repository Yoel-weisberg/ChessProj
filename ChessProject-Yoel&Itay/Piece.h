#pragma once
#include <iostream>
#include "Point.h"
#include "Player.h"
#include <vector>
class Piece
{
public:
	Piece(const std::string type, const Point location, const Pleyer color,std::vector<Piece>& board);
	virtual int move(const Point& dst);
	Point getLocation() const;
	Player getColor() const;
	int checkIfLeagel(const Point& dst) const;
	virtual int checkIfLegallyForPiece(const Point& dst) = 0;

protected:
	std::string _type;
	Point _location;
	Player _color;
	std::vector<Piece>& _board;
};
