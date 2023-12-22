#include "Point.h"


Point::Point(const int& x, const int& y) : _x(x), _y(y) {}


int Point::getX() const
{
	return this->_x;
}


int Point::getY() const
{
	return this->_y;
}


void Point::setX(const int& x, const int& y)
{
	this->_x = this->_y;
}


void Point::setY(const int& x, const int& y)
{
	this->_y = y;
}


std::string Point::toString() const
{
	
}
