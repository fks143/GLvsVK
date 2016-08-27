//
// Created by FKS143 on 2016/8/27.
//

#include "render_gl/GLRender.h"
#include "tools/Log.h"
#include "render_gl/ShaderManager.h"

#define LOG_TAG "fks_GLRender"

GLRender::GLRender()
{
	shaderManager = new ShaderManager();
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
}

GLRender::~GLRender()
{
	if (shaderManager != nullptr)
	{
		delete shaderManager;
		shaderManager = nullptr;
	}
	
	LOGE("not doing");
}

void GLRender::init(int width, int height)
{
	_screenWidth = width;
	_screenHeight = height;
}

void GLRender::update()
{
	
}

void GLRender::drawArray(GLuint * indices, GLfloat * vertices, GLfloat * colors,
	int length)
{
	//LOGD("drawArray");
	glViewport(0, 0, _screenWidth, _screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shaderManager->getShaderProgram(ShaderManager::ColorShader));
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, colors);
	
	glDrawElements(GL_TRIANGLES, length, GL_UNSIGNED_INT, indices);
}
