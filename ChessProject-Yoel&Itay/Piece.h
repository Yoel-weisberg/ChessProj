#pragma once
#include <iostream>
#include "Point.h"
#include "Pleyer.h"
class Piece
{
public:
	virtual int move(const Point& dst);
	int getLocation() const;
	Pleyer getColor() const;
	int checkIfLeagel() const;
	virtual int checkIfLegallyForPiece() = 0;

protected:
	std::string type;
	Point location;
	Pleyer color;
};
