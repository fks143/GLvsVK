//
// Created by FKS143 on 2016/8/27.
//

#ifndef _GL_RENDER_H_
#define _GL_RENDER_H_

#include "base/BaseRender.h"

class ShaderManager;
class GLRender : public BaseRender
{
public:
	GLRender();
	~GLRender();
	
	void init(int width, int height) override;
	void update() override;
	
	void drawArray(GLuint * indices, GLfloat * vertics, GLfloat * colors,
		int length) override;
private:
	ShaderManager * shaderManager;
	int _screenWidth, _screenHeight;

};

#endif
