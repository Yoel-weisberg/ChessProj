#include "FileManager.h"
#define WHITE_TURN 'w'
#define BLACK_TURN 'b'

Game* FileManage::openGameFromFile(const std::string& fileName)
{
    // Open a file for reading
    std::ifstream file(fileName);
    char type = ' ';
    int i = 0;
    bool isFirstMove = false;
    Point location = Point(0, 0);
    // Check if the file is opened successfully
    if (!file.is_open())
    {
        return nullptr;
    }
    std::vector<Piece*> gameVector;
    for (i = 0; i < ROWS * COLS; i++)
    {
        location.setCol(i % COLS);
        location.setRow(i / ROWS);
        file.get(type);
        isFirstMove = false;
        if (type == BLACK_BISHOP)
        {
            if (location == Point(B_BISHOP1_ROW, B_BISHOP1_COL) || location == Point(B_BISHOP2_ROW, B_BISHOP2_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Bishop(type, location, Player(BLACK_PLAYER), gameVector, isFirstMove));
        }
        else if (type == BLACK_PAWN)
        {
            if (location.getRow() == BLACK_PAWNS_ROW)
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Pawn(type, location, Player(BLACK_PLAYER), gameVector, isFirstMove));
        }
        else if (type == BLACK_ROOK)
        {
            if (location == Point(B_ROOK1_ROW, B_ROOK1_COL) || location == Point(B_ROOK2_ROW, B_ROOK2_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Rook(type, location, Player(BLACK_PLAYER), gameVector, isFirstMove));
        }
        else if (type == BLACK_KING)
        {
            if (location == Point(B_KING_ROW, B_KING_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new King(type, location, Player(BLACK_PLAYER), gameVector, isFirstMove));
        }
        else if (type == BLACK_QUEEN)
        {
            if (location == Point(B_QUEEN_ROW, B_QUEEN_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Queen(type, location, Player(BLACK_PLAYER), gameVector, isFirstMove));
        }
        else if (type == BLACK_KNIGHT)
        {
            if (location == Point(B_KNIGHT1_ROW, B_KNIGHT1_COL) || location == Point(B_KNIGHT2_ROW, B_KNIGHT2_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Knight(type, location, Player(BLACK_PLAYER), gameVector, isFirstMove));
        }


        // cheking white pieces
        else if (type == WHITE_BISHOP)
        {
            if (location == Point(W_BISHOP1_ROW, W_BISHOP1_COL) || location == Point(W_BISHOP2_ROW, W_BISHOP2_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Bishop(type, location, Player(WHITE_PLAYER), gameVector, isFirstMove));
        }
        else if (type == WHITE_PAWN)
        {
            if (location.getRow() == WHITE_PAWNS_ROW)
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Pawn(type, location, Player(WHITE_PLAYER), gameVector, isFirstMove));
        }
        else if (type == WHITE_ROOK)
        {
            if (location == Point(W_ROOK1_ROW, W_ROOK1_COL) || location == Point(W_ROOK2_ROW, W_ROOK2_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Rook(type, location, Player(WHITE_PLAYER), gameVector, isFirstMove));
        }
        else if (type == WHITE_KING)
        {
            if (location == Point(W_KING_ROW, W_KING_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new King(type, location, Player(WHITE_PLAYER), gameVector, isFirstMove));
        }
        else if (type == WHITE_QUEEN)
        {
            if (location == Point(W_QUEEN_ROW, W_QUEEN_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Queen(type, location, Player(WHITE_PLAYER), gameVector, isFirstMove));
        }
        else if (type == WHITE_KNIGHT)
        {
            if (location == Point(W_KNIGHT1_ROW, W_KNIGHT1_COL) || location == Point(W_KNIGHT2_ROW, W_KNIGHT2_COL))
            {
                isFirstMove = true;
            }
            gameVector.push_back(new Knight(type, location, Player(WHITE_PLAYER), gameVector, isFirstMove));
        }
        else if (type == EMPTY)
        {
            gameVector.push_back(new Empty(type, location, Player(EMPTY_PLAYER), gameVector));
        }
    }
    Game* resGame = new Game(gameVector);
    file.get(type);
    if (type == BLACK_TURN)
    {
        resGame->changeTurn(Player(BLACK_PLAYER));
    }
    file.close();
    return resGame;
}

bool FileManage::saveGameIntoFile(const Game& game, const std::string& name)
{
    int i = 0;
    std::ofstream outputFile(name);
    if (outputFile.is_open()) 
    {
        for (i = 0; i < ROWS * COLS; i++)
        {
            outputFile << game.getBoard()[i]->getType();
        }

        if (game.getTurn().getPlayerColor() == BLACK_PLAYER)
        {
            outputFile << BLACK_TURN;
        }
        else
        {
            outputFile << WHITE_TURN;
        }
        outputFile.close();
        return true;
    }
    return false;
}
