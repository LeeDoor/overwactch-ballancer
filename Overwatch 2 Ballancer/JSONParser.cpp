#include "JSONParser.h"
#include <fstream>
#include <string>
#include <QMessageBox>

std::string JSONParser::readFile(std::string path) {
	std::ifstream reader;
	std::string line;
	reader.open(path);
	getline(reader, line);
	return line;
}

void from_json(const nlohmann::json& j, JSON& p);
void from_json(const nlohmann::json& j, Player& p);
void from_json(const nlohmann::json& j, Identity& i);
void from_json(const nlohmann::json& j, Classes& c);
void from_json(const nlohmann::json& j, Stats& s);
void from_json(const nlohmann::json& j, Role& p);
//mcvs doesnt see the headers above it can be the cause of an error

void from_json(const nlohmann::json& j, JSON& p) {
	j.at("format").get_to(p.format);
	p.players = j.at("players").get<std::map<std::string, Player>>();
}
void from_json(const nlohmann::json& j, Player& p) {
	j.at("identity").get_to(p.identity);
	j.at("stats").get_to(p.stats);
	j.at("createdAt").get_to(p.createdAt);
}
void from_json(const nlohmann::json& j, Identity& i) {
	j.at("name").get_to(i.name);
	j.at("uuid").get_to(i.uuid);
	j.at("isCaptain").get_to(i.isCaptain);
	j.at("isSquire").get_to(i.isSquire);
	j.at("isFullFlex").get_to(i.isFullFlex);
}
void from_json(const nlohmann::json& j, Stats& c) {
	j.at("classes").get_to(c.classes);
}
void from_json(const nlohmann::json& j, Classes& s) {
	j.at("tank").get_to(s.tank);
	j.at("dps").get_to(s.dps);
	j.at("support").get_to(s.support);
}
void from_json(const nlohmann::json& j, Role& r) {
	j.at("rank").get_to(r.rank);
	j.at("playHours").get_to(r.playHours);
	j.at("priority").get_to(r.priority);
	j.at("primary").get_to(r.primary);
	j.at("isActive").get_to(r.isActive);
	j.at("secondary").get_to(r.secondary);
}

std::unique_ptr<JSON> JSONParser::deserializePlayer(std::string pathFile) {
	try{
		nlohmann::json json = nlohmann::json::parse(readFile(pathFile));
		std::unique_ptr<JSON> j = std::make_unique<JSON>(json.get<JSON>());
		return j;
	}
	catch (...) {
		QMessageBox b;
		b.critical(0, "ERROR", "error occured while parsing file. maybe it is not a json file or it's structure is wrong?");
		b.show();
	}
}

