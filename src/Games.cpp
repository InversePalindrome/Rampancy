/*
Copyright (c) 2017 InversePalindrome
Rampancy - Games.cpp
InversePalindrome.com
*/


#include "Games.hpp"
#include "FilePaths.hpp"

#include <RapidXML/rapidxml.hpp>
#include <RapidXML/rapidxml_print.hpp>

#include <fstream>
#include <sstream>
#include <algorithm>


Games::Games(const std::string& fileName) :
	fileName(fileName)
{
	rapidxml::xml_document<> doc;
	std::ifstream inFile(FP::savedGames + fileName);
	std::ostringstream buffer;

	buffer << inFile.rdbuf();
	inFile.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	auto* rootNode = doc.first_node("Games");

	if (rootNode)
	{
		for (const auto* node = rootNode->first_node("Game"); node; node = node->next_sibling())
		{
			this->addGame(node->first_attribute("name")->value());
		}
	}
}

Games::~Games()
{
	rapidxml::xml_document<> doc;

	auto* decl = doc.allocate_node(rapidxml::node_declaration);
	decl->append_attribute(doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
	doc.append_node(decl);

	auto* gamesNode = doc.allocate_node(rapidxml::node_element, "Games");

	for (const auto& game : this->games)
	{
		auto* gameNode = doc.allocate_node(rapidxml::node_element, "Game");

		gameNode->append_attribute(doc.allocate_attribute("name", doc.allocate_string(game.second.getName().c_str())));

		gamesNode->append_node(gameNode);
	}

	doc.append_node(gamesNode);

	std::ofstream outFile(FP::savedGames + this->fileName);

	outFile << doc;
}

Game& Games::getCurrentGame()
{
	return this->games[this->currentGameName];
}

void Games::setCurrentGame(const std::string& gameName)
{
	this->currentGameName = gameName;
}

void Games::addGame(const std::string& gameName)
{
	this->games.emplace(gameName, Game(gameName));
}

void Games::removeGame(const std::string& gameName)
{
	this->games.erase(gameName);
}

bool Games::hasGame(const std::string& gameName) const
{
	return this->games.count(gameName);
}

std::unordered_map<std::string, Game>::iterator Games::begin()
{
	return std::begin(this->games);
}

std::unordered_map<std::string, Game>::iterator Games::end()
{
	return std::end(this->games);
}

std::unordered_map<std::string, Game>::const_iterator Games::cbegin() const
{
	return std::cbegin(this->games);
}

std::unordered_map<std::string, Game>::const_iterator Games::cend() const
{
	return std::cend(this->games);
}