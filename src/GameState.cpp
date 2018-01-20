/*
Copyright (c) 2017 InversePalindrome
Rampancy - GameState.cpp
InversePalindrome.com
*/


#include "GameState.hpp"
#include "MenuState.hpp"
#include "PhysicsSystem.hpp"
#include "ControlSystem.hpp"
#include "GraphicsSystem.hpp"
#include "SceneComponent.hpp"
#include "LightComponent.hpp"
#include "CameraComponent.hpp"
#include "FilePaths.hpp"

#include <entityx/deps/Dependencies.h>

#include <boost/filesystem/convenience.hpp>


GameState::GameState() :
	entityManager(eventManager),
	systemManager(entityManager, eventManager),
	entityParser(entityManager, eventManager),
	entitySerializer(entityManager)
{
	systemManager.add<GraphicsSystem>();
	systemManager.add<PhysicsSystem>();
	systemManager.add<ControlSystem>();

	systemManager.add<entityx::deps::Dependency<MeshComponent, SceneComponent>>();
	systemManager.add<entityx::deps::Dependency<LightComponent, SceneComponent>>();
	systemManager.add<entityx::deps::Dependency<CameraComponent, SceneComponent>>();
	
	systemManager.configure();
}

void GameState::OnEnter()
{
	this->systemManager.system<ControlSystem>()->setInputManager(&this->getInputManager());
	this->systemManager.system<GraphicsSystem>()->setSceneManager(this->getSceneManager());

	this->entityParser.setSceneManager(this->getSceneManager());
	this->entityParser.setCamera(this->getCamera());

	if (!boost::filesystem::exists(FP::savedGames + '/' + this->getGames().getCurrentGame().getName() + "/Entities.xml"))
	{
		this->entityParser.parseEntities(ParsingMode::Individual, "Entities.xml");
	}
	else
	{
		this->entityParser.parseEntities(ParsingMode::Group, '/'+ this->getGames().getCurrentGame().getName() + "/Entities.xml");
	}

	this->terrainBuilder.setSceneManager(this->getSceneManager());
	this->terrainBuilder.loadTerrain("TerrainInfo.xml");

	this->skyBuilder.setSceneManager(this->getSceneManager());
	this->skyBuilder.loadSky("Sky.xml");

	this->pauseDisplay.initialise(this);
	this->pauseDisplay.setVisible(false);
}

void GameState::OnExit()
{
	this->entitySerializer.serialize('/' + this->getGames().getCurrentGame().getName() + "/Entities.xml");
	this->getSceneManager()->clearScene();
}

hsm::Transition GameState::GetTransition()
{
	if (this->getStateTransition() == StateTransition::Menu)
	{
		return hsm::SiblingTransition<MenuState>();
	}

	return hsm::NoTransition();
}

void GameState::Update()
{
	if (this->getInputManager().isActive(Action::Quit))
	{	
		this->pauseDisplay.setVisible(true);
	}

	if (!this->pauseDisplay.isVisible())
	{
		this->systemManager.update_all(0);
	}
}