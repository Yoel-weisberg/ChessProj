#pragma once

#include <string>
#include "Constants.h"


class Point
{
public:
	Point(const int& row, const int& col);

	int getRow() const;
	int getCol() const;

	void setRow(const int& row);
	void setCol(const int& col);

	static bool isPointInBoundaries(const Point& point);
	static Point chessNotationToPoint(std::string chessNotation);

	bool operator==(const Point& other) const;

private:
	int _row;
	int _col;
};
