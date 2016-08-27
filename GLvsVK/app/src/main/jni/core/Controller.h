//
// Created by FKS143 on 2016/8/27.
//

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

class BaseRender;
class Controller
{
public:
	Controller();
	~Controller();
	
	void resize(int width, int height);
	void update();
	
private:
	BaseRender * render;
};

#endif
