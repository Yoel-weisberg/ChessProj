#include "Point.h"


/**
 @brief		Constructor - Initializes the row and column of the point.
 @param		row		The row of the point.
 @param		col		The column of the point.
 */
Point::Point(const int& row, const int& col) : _row(row), _col(col) {}


/**
 @brief		Returns the row of the point.
 @return	The row of the point.
 */
int Point::getRow() const
{
	return this->_row;
}


/**
 @brief		Returns the column of the point.
 @return	The column of the point.
 */
int Point::getCol() const
{
	return this->_col;
}


/**
 @brief		Sets the row of the point.
 @param		row		The row to set to the point.
 @return	void
 */
void Point::setRow(const int& row)
{
	this->_row = row;
}


/**
 @brief		Sets the column of the point.
 @param		col		The column to set to the point.
 @return	void
 */
void Point::setCol(const int& col)
{
	this->_col = col;
}


/**
 @brief		Converts the point into a string chess representation.
 @return	The string chess representation of the point.
 */
std::string Point::toString() const
{
	return std::string(1, 'a' + this->_col) + std::string(1, '8' - this->_row);
}


/**
 @brief		Checks if the calling point is equal to another point.
 @param		other		The other point to compare to.
 @return	True if the points are equal, false otherwise.
 */
bool Point::operator==(const Point& other) const
{
	return (this->_row == other._row) && (this->_col == other._col);
}
