//
// Created by FKS143 on 2016/8/27.
//

#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "core/Controller.h"

class GameManager
{
public:
	static GameManager * getInstance();
	void freeAll();
	
	void init();
	void step();
	void resize(int width, int height);
	
private:
	GameManager();

private:
	static GameManager * instance;
	Controller * controller;
};

#endif
