//
// Created by FKS143 on 2016/8/27.
//

#include "render_gl/ShaderManager.h"
#include "tools/Log.h"
#include <stdlib.h>

#define LOG_TAG "fks_ShaderManager"

char colorShader_v[] =
		"attribute vec4 a_position;"
		"attribute vec4 a_color;"
		"varying vec4 v_fragmentColor;"
		"void main()"
		"{"
		"	gl_Position = CC_MVPMatrix * a_position;"
		"	v_fragmentColor = a_color;"
		"}";
char colorShader_f[] =
		"varying vec4 v_fragmentColor;"
		"void main()"
		"{"
		"	gl_FragColor = v_fragmentColor;"
		"}";

ShaderManager::ShaderManager()
{
	shaders[1] = linkShader(ColorShader);
}

ShaderManager::~ShaderManager()
{
	LOGE("not doing");
}

GLuint ShaderManager::getShaderProgram(ShaderType shaderType)
{
	return shaders[(int)(shaderType)];
}

GLuint ShaderManager::linkShader(ShaderType shaderType)
{
	GLuint programObject;
	GLint linked;
	int idx = (int)(shaderType);
	
	programObject = glCreateProgram();
	if (programObject == 0)
	{
		return 0;
	}
	
	glAttachShader(programObject, getShader(GL_VERTEX_SHADER, shaderType));
	glAttachShader(programObject, getShader(GL_FRAGMENT_SHADER, shaderType));
	glLinkProgram(programObject);
	
	glGetProgramiv(programObject, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		GLint infoLen = 0;
		glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen > 1)
		{
			char *infoLog = (char *)malloc(sizeof(char) * infoLen);
			glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
			LOGE("Error linking program:[%s]", infoLog);
			free(infoLog);
		}
		glDeleteProgram(programObject);
		return 0;
	}
	
	return programObject;
}

GLuint ShaderManager::getShader(GLenum type, ShaderType shaderType)
{
	char * shaderStr = getShaderStr(type, shaderType);
	
	GLuint shader;
	GLint compiled;
	
	shader = glCreateShader(type);
	if (shader == 0)
	{
		return 0;
	}
	
	glShaderSource(shader, 1, &shaderStr, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	
	if (!compiled)
	{
		GLint infoLen = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
		if (infoLen > 1)
		{
			char *infoLog = (char *)malloc(sizeof(char) * infoLen);
			glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
			LOGE("Error compiling shader:[%s]", infoLog);
			free(infoLog);
		}
		glDeleteShader(shader);
		return 0;
	}
	
	return shader;
}

char * ShaderManager::getShaderStr(GLenum type, ShaderType shaderType)
{
	if (shaderType == ColorShader)
	{
		if (type == GL_VERTEX_SHADER)
		{
			return colorShader_v;
		}
		else if (type == GL_FRAGMENT_SHADER)
		{
			return colorShader_f;
		}
		else
		{
			LOGE("type error");
			return nullptr;
		}
	}
	
	LOGE("shader type error");
	return nullptr;
}
