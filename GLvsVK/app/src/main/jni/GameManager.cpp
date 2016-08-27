//
// Created by FKS143 on 2016/8/27.
//

#include "GameManager.h"
#include "tools/Log.h"

#define LOG_TAG "fks_GameManager"

GameManager * GameManager::instance = nullptr;

GameManager * GameManager::getInstance()
{
	if (instance != nullptr)
	{
		return instance;
	}
	instance = new GameManager();
	return instance;
}

GameManager::GameManager()
{
	controller = nullptr;
	LOGD("GameManager created");
}

void GameManager::freeAll()
{
	if (instance == nullptr)
	{
		return;
	}
	
	if (controller != nullptr)
	{
		delete controller;
		controller = nullptr;
	}
	
	LOGD("free all");
}

void GameManager::init()
{
	if (controller != nullptr)
	{
		LOGE("Controller has not been freed");
		return;
	}
	controller = new Controller();
	
	LOGD("init");
}

void GameManager::resize(int width, int height)
{
	controller->resize(width, height);
	LOGD("resize");
}

void GameManager::step()
{
	controller->update();
	//LOGD("step");
}
