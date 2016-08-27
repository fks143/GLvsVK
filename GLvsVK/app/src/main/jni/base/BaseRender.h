//
// Created by FKS143 on 2016/8/27.
//

#ifndef _BASE_RENDER_H_
#define _BASE_RENDER_H_

#include <GLES3/gl3.h>

class BaseRender
{
public:
	virtual void init(int width, int height) = 0;
	virtual void update() = 0;
	
	virtual void drawArray(GLuint * indices, GLfloat * vertics,
		GLfloat * colors, int length) = 0;
};

#endif
