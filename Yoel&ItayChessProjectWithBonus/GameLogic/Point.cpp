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
 @brief		Returns true if the given Point is in the board boundaries.
 @param		point		The Point to check.
 @return	True if the given Point is in the board boundaries, false otherwise.
 */
bool Point::isPointInBoundaries(const Point& point)
{
	return ((point.getRow() >= 0) && (point.getRow() < ROWS)) &&
		   ((point.getCol() >= 0) && (point.getCol() < COLS));
}


/**
 @brief		Converts a string chess-cell representation into a point.
 @param		chessNotation		The string chess-cell representation to convert to a point.
 @return	The Point representation of the chess-cell.
 */
Point Point::chessNotationToPoint(std::string chessNotation)
{
	int col = chessNotation[0] - 'a';
	int row = '8' - chessNotation[1];

	return Point(row, col);
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
