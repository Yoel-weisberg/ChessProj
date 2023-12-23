#pragma once

#include <iostream>
#include "Point.h"
#include "Player.h"
#include <vector>


class Piece
{
public:
	Piece(const std::string type, const Point location, const Player color,std::vector<Piece>& board);
	virtual int move(const Point& dst);
	Point getLocation() const;
	Player getColor() const;
	virtual int checkIfLegallyForPiece(const Point& dst) const = 0;

protected:
	std::string _type;
	Point _location;
	Player _color;
	std::vector<Piece>& _board;
};
