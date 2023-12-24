#pragma once

#include <string>


class Point
{
public:
	Point(const int& row, const int& col);

	int getRow() const;
	int getCol() const;

	void setRow(const int& row);
	void setCol(const int& col);

	std::string toString() const;

	bool operator==(const Point& other) const;

private:
	int _row;
	int _col;
};
