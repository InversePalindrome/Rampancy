/*
Copyright (c) 2017 InversePalindrome
Rampancy - EntitySerializer.hpp
InversePalindrome.com
*/


#pragma once

#include <string>

#include <entityx/entityx.h>

#include <tree.hh>


class EntitySerializer
{
public:
	EntitySerializer(entityx::EntityManager& entityManager);

	void serialize(const std::string& fileName);

private:
	entityx::EntityManager& entityManager;
	tree<std::string> entities;

	void saveEntities();
};