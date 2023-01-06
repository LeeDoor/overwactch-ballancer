#pragma once
#include <nlohmann/json.hpp>
#include "JSON.h"
class JSONParser
{
private:
	std::string readFile(std::string path);

public:
	std::unique_ptr<JSON> deserializePlayer(std::string pathFile);
	//void serializePlayer(Player player, std::string pathFile);
};


//editprofiledialog chan