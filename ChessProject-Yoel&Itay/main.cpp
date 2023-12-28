#include "Game.h"
#include "BoardUtils.h"
#include "Point.h"


int main(void)
{
	Game game = Game();

	std::string move = "";
	returnCode moveCode = UNDEFINED;

	while (move != EXIT)
	{
		system("cls");		// Clearing the console using Windows.h (might be changed later because it only works for windows)

		BoardUtils::printBoard(game.getBoard(), game.getTurn());
		std::cout << "Return code: " << moveCode << std::endl;

		std::cout << "Enter move: ";
		std::cin >> move;

		if (move == "q")
		{
			break;
		}

		// Translating the move from chess notation to a point
		Point src = Point::chessNotationToPoint(move.substr(0, 2));
		Point dst = Point::chessNotationToPoint(move.substr(2, 2));

		// Performing the move
		moveCode = game.moveOnBoard(src, dst);

		// Checking if the move was valid and if so, switching turns
		if (moveCode == VALID_MOVE || moveCode == CHECK_MOVE)
		{
			game.switchTurn();
		}
	}

	return 0;
}
