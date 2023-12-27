#include "Game.h"
#include "BoardUtils.h"
#include "Point.h"


int main(void)
{
	Game game = Game();

	std::string move = "";

	while (move != "q")
	{
		std::cin >> move;

		Point src = Point::chessNotationToPoint(move.substr(0, 2));
		Point dst = Point::chessNotationToPoint(move.substr(2, 2));

		returnCode moveCode = game.moveOnBoard(src, dst);
		std::cout << "Return code: " << moveCode << std::endl;

		if (moveCode == VALID_MOVE || moveCode == CHECK_MOVE)
		{
			BoardUtils::printBoard(game.getBoard());
			game.switchTurn();
		}
	}

	return 0;
}