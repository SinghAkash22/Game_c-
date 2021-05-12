#include "VertexArrey.h"	
#include "GL/glew.h"

VertexArrey::VertexArrey(const float* vert, unsigned int vertNo,  const unsigned int* index, unsigned int IndNo)
{
	mVertexno = vertNo;
	mIndexno = IndNo;
	glGenVertexArrays(1, &mVertexArrID);
	glBindVertexArray(mVertexArrID);
	glGenBuffers(1, &mVertexBuffID);
	glBindBuffer(GL_ARRAY_BUFFER,mVertexArrID);
	glBufferData(GL_ARRAY_BUFFER, 5 * mVertexno * sizeof(float), vert, GL_STATIC_DRAW);
	glGenBuffers(1, &mIndexBuffID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * mIndexno * sizeof(unsigned int), index, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(sizeof(float) * 3));

}

VertexArrey::~VertexArrey()
{
	glDeleteBuffers(1, &mVertexBuffID);
	glDeleteBuffers(1, &mIndexBuffID);
	glDeleteVertexArrays(1, &mVertexArrID);
}
void VertexArrey::SetActive()
{
	glBindVertexArray(mVertexArrID);
}