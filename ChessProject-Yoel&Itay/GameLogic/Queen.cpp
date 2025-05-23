#include "Queen.h"



/**
 @brief		Constructor - Initializes the location, color, type and board (reference) of the Queen.
 @param		type		The type of the piece.
 @param		location	The location of the piece on the board.
 @param		color		The color of the piece.
 @param		board		The board of the game.
 */
Queen::Queen(const char& type, const Point& location, const Player& color, std::vector<Piece*>& board) : Piece(type, location, color, board) {}


/**
 @brief		Checks if the trip is legal for the Queen.
 @param		dst		The destination point of the piece.
 @return	true if the trip is legal, false otherwise.
 @note		The Queen can move like a Bishop or a Rook.
 */
bool Queen::checkIfTripLegallyForPiece(const Point& dst) const
{
	return Bishop::checkIfTripLegallyForPieceBishop(this->_location, dst) || Rook::checkIfTripLegallyForPieceRook(this->_location, dst);
}


/**
 @brief		Checks if there are pieces that block the Queens's trip.
 @param		dst		The destination point of the Queen.
 @return	false if the trip is blocked, true otherwise.
 */
bool Queen::checkIfPiecesInTrip(const Point& dst) const
{
	if (Bishop::checkIfTripLegallyForPieceBishop(this->_location, dst))
	{
		return Bishop::checkForPiecesOnTripBishop(this->_location, dst, this->_board);
	}
	return Rook::checkForPiecesOnTripRook(this->_location, dst, this->_board);
}
