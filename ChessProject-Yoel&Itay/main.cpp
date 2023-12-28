/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/
#include "Game.h"
#include "BoardUtils.h"
#include "Point.h"
#include "Pipe.h"
#include <iostream>
#include <string> 
#include <thread>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol

	// YOUR CODE
	Game game = Game();

	returnCode moveCode = UNDEFINED;
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string move = p.getMessageFromGraphics();

	while (move != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		system("cls");		// Clearing the console using Windows.h (might be changed later because it only works for windows)

		BoardUtils::printBoard(game.getBoard(), game.getTurn());
		std::cout << "Return code: " << moveCode << std::endl;


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
		int code = moveCode;
		char res = char(48 + code);

		msgToGraphics[0] = res; // msgToGraphics should contain the result of the operation
		msgToGraphics[1] = NULL;

		/******* JUST FOR EREZ DEBUGGING ******/
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		move = p.getMessageFromGraphics();
	}

	p.close();
}