#pragma once
#include <fstream>
#include "Game.h"
class FileManage
{
public:
	static Game* openGameFromFile(const std::string& fileName);
	static bool saveGameIntoFile(const Game& game, const std::string& name);
};
