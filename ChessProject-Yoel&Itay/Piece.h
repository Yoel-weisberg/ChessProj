#pragma once

#include <iostream>
#include "Point.h"
#include "Player.h"
#include "BoardUtils.h"
#include "Board.h"
#include <math.h>
#include <vector>

class BoardUtils;
class Board;


class Piece
{
public:
	Piece(const char& type, const Point& location, const Player& color);
	Point getLocation() const;
	Player getColor() const;
	char getType() const;
	virtual returnCode checkIfLegallyForPiece(const Point& dst, const Board& board) const;
	virtual bool checkIfTripLegallyForPiece(const Point& dst, const Board& board) const = 0;
	virtual bool checkIfPiecesInTrip(const Point& dst, const Board& board) const = 0;
	void operator= (const Piece& other);
	void turnIntoEmpty();

protected:
	char _type;
	Point _location;
	Player _color;
};
