#include "GL/glew.h"
#include "texture.h"
#include "SDl.h"
Texture::Texture()
:mTextureID(0)
,mWidth(0)
,mHieght(0)
{

}

bool Texture::Load(const std::string& file)
{
	int channel=0;
	unsigned char* image = SOIL_load_image(file.c_str(), &mWidth, &mHieght, &channel, SOIL_LOAD_AUTO);
	if (image == nullptr)
	{
		SDL_Log("SOIL failed to load image %s: %s", file.c_str(), SOIL_last_result());
		return false;
	}

	int format = GL_RGB;
	if (channel == 4)
	{
		format = GL_RGBA;
	}
	glGenTextures(1, &mTextureID);
	glBindTexture(GL_TEXTURE_2D, mTextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, format, mWidth, mHieght,0, format,  GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return true;
}
void Texture::Unload()
{
	glDeleteTextures(1,&mTextureID);
}
void Texture::SetActive()
{
	glBindTexture(GL_TEXTURE_2D, mTextureID);
}
