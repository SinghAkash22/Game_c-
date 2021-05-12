#pragma once
#include "Actor.h"
class VertexArrey
{
public:
	VertexArrey(const float *mVex,unsigned int vectNo,const unsigned int  *mIndex,unsigned int indNo);
	~VertexArrey();
	void SetActive();
	unsigned int GetVertexno()const { return mVertexno; }
	unsigned int GetIndexno()const { return mIndexno; }
private:
	unsigned int mVertexno;
	unsigned int mIndexno;
	unsigned int mVertexBuffID;
	unsigned int mVertexArrID;
	unsigned int mIndexBuffID;

};