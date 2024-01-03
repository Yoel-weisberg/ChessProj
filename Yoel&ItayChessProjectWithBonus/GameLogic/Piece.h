#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Point.h"
#include "Player.h"
#include "Constants.h"


class Piece
{
public:
	Piece(const char& type, const Point& location, const Player& color, std::vector <Piece*>& board, const bool& isFirstMove = true);

	char getType() const;
	Point getLocation() const;
	Player getColor() const;
	bool isFirstMove() const;
	void falseFirstMove();
	std::vector<Piece*> getBoard() const;

	returnCode checkIfLegallyForPiece(const Point& dst) const;
	virtual bool checkIfTripLegallyForPiece(const Point& dst) const = 0;
	virtual bool checkIfPiecesInTrip(const Point& dst) const = 0;

	virtual std::vector<Point> returnPossibleDestinations() const = 0;

	void operator= (const Piece& other);
	
	static Piece* getElementAtLoc(const std::vector <Piece*>& board, const int& row, const int& col);
	static void setElementAtLoc(std::vector <Piece*>& board, const int& row, const int& col, Piece* newValue);

	virtual bool checkForCastling(const Point& dst) const;

protected:
	char _type;
	Point _location;
	Player _color;
	bool _isFirstMove;
	std::vector <Piece*>& _board;
};
