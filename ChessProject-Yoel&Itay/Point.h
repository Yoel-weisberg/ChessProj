#pragma once

#include <string>

class Point
{
public:
	Point(const int& x, const int& y);

	int getX() const;
	int getY() const;

	void setX(const int& x, const int& y);
	void setY(const int& x, const int& y);

	std::string toString() const;

private:
	int _x;
	int _y;
};
