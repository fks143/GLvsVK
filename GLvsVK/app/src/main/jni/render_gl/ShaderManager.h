//
// Created by FKS143 on 2016/8/27.
//

#ifndef _SHADER_MANAGER_H_
#define _SHADER_MANAGER_H_

#include <GLES3/gl3.h>

class ShaderManager
{
public:
	enum ShaderType
	{
		None = 0,
		ColorShader
	};

	ShaderManager();
	~ShaderManager();
	GLuint getShaderProgram(ShaderType shaderType);
	
private:
	GLuint linkShader(ShaderType shaderType);
	GLuint getShader(GLenum type, ShaderType shaderType);
	char * getShaderStr(GLenum type, ShaderType shaderType);

private:
	GLuint shaders[2];
	
};

#endif
