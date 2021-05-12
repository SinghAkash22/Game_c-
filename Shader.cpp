#include "Shader.h"
#include "GL/glew.h"
#include<sstream>
#include<fstream>
#include "SDL.h"
#include "Math.h"

Shader::Shader()
	:mVertxShader(0)
	,mFragShader(0)
	,mSaderProgram(0)
{

}

bool Shader::Load(const std::string& vertshader,const std::string& frag)
{
	if (!compile(vertshader,GL_VERTEX_SHADER,mVertxShader))
	{
		SDL_Log("not worlk vertex shader");
		return false;
	}
	if (!compile(frag, GL_FRAGMENT_SHADER, mFragShader))
	{
		SDL_Log("not work frag shader");
		return false;
	}
	mSaderProgram = glCreateProgram();
	glAttachShader(mSaderProgram, mVertxShader);
	glAttachShader(mSaderProgram, mFragShader);
	glLinkProgram(mSaderProgram);
	if (!isvalidProgram())
	{
		return false;
	}
	return true;
}
void Shader::unload()
{
	glDeleteShader(mVertxShader);
	glDeleteShader(mFragShader);
	glDeleteProgram(mSaderProgram);
}


bool Shader::compile(const std::string& filename, GLenum type, GLuint& outPut)
{
	std::ifstream shaderFile(filename);
	if (shaderFile.is_open())
	{
		std::stringstream strem;
		strem << shaderFile.rdbuf();
		std::string content = strem.str();
		const char* cont = content.c_str();
		outPut=glCreateShader(type);
		glShaderSource(outPut, 1, &(cont),nullptr);
		glCompileShader(outPut);
		if (iscompile(outPut))
		{
			return true;
		}
		else
		{
			SDL_Log("not compile shader");
			return false;
		}
	}
	else
	{
		SDL_Log("file not load");
		return false;
	}

}

bool Shader::iscompile(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buff[512];
		memset(buff,0, 512);
		glGetShaderInfoLog(shader, 510, nullptr, buff);
		SDL_Log("result is %s", buff);
		return false;
	}
	return true; 
}
bool Shader::isvalidProgram()
{
	GLint status;
	// Query the link status
	glGetProgramiv(mSaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);
		glGetProgramInfoLog(mSaderProgram, 511, nullptr, buffer);
		SDL_Log("GLSL Link Status:\n%s", buffer);
		return false;
	}

	return true;
}
void Shader::SetUniformMatrix(const char* variabl, const Matrix4& matrix)
{
	GLuint loc = glGetUniformLocation(mSaderProgram, variabl);
	glUniformMatrix4fv(loc, 1, GL_TRUE, matrix.GetAsFloatPtr());
}
void Shader::SetActive()
{
	glUseProgram(mSaderProgram);
}