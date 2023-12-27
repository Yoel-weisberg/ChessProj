#pragma once

#include <iostream>
#include "Point.h"
#include "Player.h"
#include "Constants.h"
#include <vector>
#include <math.h>
#include <string>

#define ROWS 8
#define COLS 8

#define EMPTY '#'


class Piece
{
public:
	Piece(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board);

	Point getLocation() const;
	Player getColor() const;
	char getType() const;
	std::vector<Piece*> getBoard() const;

	returnCode checkIfLegallyForPiece(const Point& dst) const;
	virtual bool checkIfTripLegallyForPiece(const Point& dst) const = 0;
	virtual bool checkIfPiecesInTrip(const Point& dst) const = 0;

	void turnIntoEmpty();
	void operator= (const Piece& other);

	static Piece* getElementAtLoc(const std::vector <Piece*>& board, const int& row, const int& col);
	static void setElementAtLoc(std::vector <Piece*>& board, const int& row, const int& col, Piece* newValue);

protected:
	char _type;
	Point _location;
	Player _color;
	std::vector <Piece*>& _board;
};
