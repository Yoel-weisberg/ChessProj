#include <iostream>
#include <string> 
#include <thread>
#include "Game.h"
#include "BoardUtils.h"
#include "Point.h"
#include "../GameGraphics/Pipe.h"


#define BUFFER_SIZE 1024
#define SLEEP_TIME 5000
#define COORDINATES_SIZE 2
#define ASCII_ZERO 48


void connectToGraphics(Pipe& p);
void sendBoardToGraphics(Pipe& p, const Game& game);
void runGameGraphics(Pipe& p, Game& game);

void runGameConsole(Game& game);


int main()
{
	Pipe p;
	Game game = Game();

	bool runFrontend = true;

	if (runFrontend)
	{
		connectToGraphics(p);

		sendBoardToGraphics(p, game);

		runGameGraphics(p, game);

		p.close();
	}
	else
	{
		runGameConsole(game);
	}

	return 0;
}


/**
 @brief		Connects to the graphics (or exits if the user wants).
 @param		p		The pipe to connect to the graphics.
 @return	void.
 */
void connectToGraphics(Pipe& p)
{
	bool isConnect = p.connect();

	std::string ans = "";
	while (!isConnect)
	{
		std::cout << "Cannot connect to the graphics" << std::endl;
		std::cout << "Do you want to try to connect again or exit? (0: try again, 1: exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "Trying to connect again.." << std::endl;
			Sleep(SLEEP_TIME);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			exit(0);
		}
	}
}


/**
 @brief		Sends the board as a string to the graphics using the pipe.
 @param		p		The pipe to the graphics.
 @param		game	The game object to use to get the board.
 @return	void.
 */
void sendBoardToGraphics(Pipe& p, const Game& game)
{
	char msgToGraphics[BUFFER_SIZE] = { NULL };
	char* boardString = game.returnBoardString();

	// Copying the board string into 'msgToGraphics'
	for (int i = 0; i < ROWS * COLS; i++)
	{
		msgToGraphics[i] = boardString[i];
	}

	msgToGraphics[ROWS * COLS] = 1;		// Adding another character after the board

	p.sendMessageToGraphics(msgToGraphics);		// Sending the board to the graphics
}


/**
 @brief		Runs the game in the graphics.
 @param		p		The pipe to the graphics.
 @param		game	The game object to use to run the game.
 @return	void.
 */
void runGameGraphics(Pipe& p, Game& game)
{
	std::string move = "";
	returnCode moveCode = UNDEFINED;
	char msgToGraphics[BUFFER_SIZE] = { NULL };

	while (move != EXIT)
	{
		system("cls");		// Clearing the console using Windows.h (only works for windows)

		// Printing the board and the returnCode of the last move
		BoardUtils::printBoard(game.getBoard(), game.getTurn());
		std::cout << "Return code: " << moveCode << std::endl;

		move = p.getMessageFromGraphics();		// Getting the move string from the graphics

		// Translating the move from chess notation to a point
		Point src = Point::chessNotationToPoint(move.substr(0, COORDINATES_SIZE));
		Point dst = Point::chessNotationToPoint(move.substr(COORDINATES_SIZE, COORDINATES_SIZE));

		moveCode = game.moveOnBoard(src, dst);		// Performing the move on the board

		// Checking if the move was valid and if so, switching turns
		if (moveCode == VALID_MOVE || moveCode == CHECK_MOVE)
		{
			game.switchTurn();
		}

		// Building the move code message to send to the graphics
		msgToGraphics[0] = char(ASCII_ZERO + moveCode);
		msgToGraphics[1] = NULL;

		// Sending the move code to the graphics
		p.sendMessageToGraphics(msgToGraphics);
	}
}


/**
 @brief		Runs the game in the console.
 @param		game	The game object to use to run the game.
 @return	void.
 */
void runGameConsole(Game& game)
{

	returnCode moveCode = UNDEFINED;
	std::string move = "";

	while (move != "q")
	{
		system("cls");		// Clearing the console using Windows.h (might be changed later because it only works for windows)

		BoardUtils::printBoard(game.getBoard(), game.getTurn());
		std::cout << "Return code: " << moveCode << std::endl;

		std::cout << "enter move: ";
		std::cin >> move;

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
}
