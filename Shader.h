#pragma once
#include<string>
#include "Math.h"
#include "GL/glew.h"
class Shader
{
public:
	Shader();
	~Shader() { };
	bool Load(const std::string &vertshader,const std::string & frag);
	void unload();
	void SetActive();
	void SetUniformMatrix(const char* variable, const Matrix4& matrix);
private:
	bool compile(const std::string &filename,GLenum type,GLuint &outPut);
	bool iscompile(GLuint shader);
	bool isvalidProgram();
	GLuint mVertxShader;
	GLuint mFragShader;
	GLuint mSaderProgram;
};