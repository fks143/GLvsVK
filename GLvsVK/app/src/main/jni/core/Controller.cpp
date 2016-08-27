//
// Created by FKS143 on 2016/8/27.
//

#include "tools/Log.h"
#include "core/Controller.h"
#include "render_gl/GLRender.h"

#define LOG_TAG "fks_Controller"

Controller::Controller()
{
	render = new GLRender();
	
	LOGD("Controller created");
}

Controller::~Controller()
{
	if (render != nullptr)
	{
		delete render;
		render = nullptr;
	}
	
	LOGD("Controller freed");
}

void Controller::resize(int width, int height)
{
	render->init(width, height);
}

void Controller::update()
{
	// temp
	GLfloat vertices[] = {
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f};
	GLfloat colors[] = {
		1, 0, 0, 1,
		0, 1, 0, 1,
		0, 0, 1, 1};
	GLuint indices[] = {0, 1, 2};
	render->drawArray(indices, vertices, colors, 3);
	// ===
}
