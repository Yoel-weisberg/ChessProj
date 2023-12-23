#pragma once

#include <iostream>
#include "Point.h"
#include "Player.h"
#include "BoardUtils.h"
#include <vector>


class Piece
{
public:
	Piece(const char& type, const Point& location, const Player& color,std::vector<Piece>& board);
	virtual int move(const Point& dst);
	Point getLocation() const;
	Player getColor() const;
	char getType() const;
	virtual returnCode checkIfLegallyForPiece(const Point& dst) const = 0;
	void operator= (const Piece& other);
	void turnIntoEmpty();

protected:
	char _type;
	Point _location;
	Player _color;
	std::vector<Piece>& _board;
};
