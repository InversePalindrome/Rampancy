/*
Copyright (c) 2017 InversePalindrome
Rampancy - Games.hpp
InversePalindrome.com
*/


#pragma once

#include "Game.hpp"

#include <string>
#include <unordered_map>


class Games
{
public:
	explicit Games(const std::string& fileName);
	~Games();

	Game& getCurrentGame();
	void setCurrentGame(const std::string& gameName);

	void addGame(const std::string& gameName);
	void removeGame(const std::string& gameName);

	bool hasGame(const std::string& gameName) const;

	std::unordered_map<std::string, Game>::iterator begin();
	std::unordered_map<std::string, Game>::iterator end();
	std::unordered_map<std::string, Game>::const_iterator cbegin() const;
	std::unordered_map<std::string, Game>::const_iterator cend() const;

private:
	std::string fileName;
	std::string currentGameName;
	std::unordered_map<std::string, Game> games;
};