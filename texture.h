#pragma once
#include<string>
#include <SOIL2.h>
class Texture
{
public:
	Texture();
	~Texture() {};
	bool Load(const std::string & filename);
	void Unload();
	void SetActive();
	int GetWidth()const { return mWidth; }
	int GetHieght() const { return mHieght; }

private:
	int mWidth;
	int mHieght;
	unsigned int mTextureID;
};
