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
	LOGD("GameManager created");
}

void GameManager::init()
{

}

void GameManager::resize(int width, int height)
{

}

void GameManager::step()
{

}
