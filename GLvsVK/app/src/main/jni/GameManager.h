//
// Created by FKS143 on 2016/8/27.
//

#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

class GameManager
{
public:
	static GameManager * getInstance();
	
	void init();
	void step();
	void resize(int width, int height);
	
private:
	GameManager();

private:
	static GameManager * instance;
};

#endif
