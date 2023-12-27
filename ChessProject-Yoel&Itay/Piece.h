#pragma once

#include <iostream>
#include "Point.h"
#include "Player.h"
#include <vector>
#include <math.h>
#include <string>

#define ROWS 8
#define COLS 8

enum returnCode
{
	VALID_MOVE = 0,						// Valid move
	CHECK_MOVE = 1,						// Valid move
	MISSING_CURRENT_IN_SRC = 2,			// Invalid move
	DST_OCCUPIED_BY_CURRENT = 3,		// Invalid move
	CAUSES_CHECK_ON_CURRENT = 4,		// Invalid move
	INVALID_INDEXES = 5,				// Invalid move
	ILLEGAL_MOVE_FOR_PIECE = 6,			// Invalid move
	SAME_SRC_DST_POINTS = 7,			// Invalid move
	//	CHECKMATE_MOVE = 8					// Valid move
};




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
	void operator= (const Piece& other);
	void turnIntoEmpty();
	static Piece* getElementAtLoc(const std::vector <Piece*>& board, const int& row, const int& col);
	static void setElementAtLoc(std::vector <Piece*>& board, const int& row, const int& col, Piece* newValue);

protected:
	char _type;
	Point _location;
	Player _color;
	std::vector <Piece*>& _board;
};
