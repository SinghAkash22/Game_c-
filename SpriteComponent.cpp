// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"
#include "Shader.h"
#include "GL/glew.h"
#include "texture.h"
SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	:Component(owner)
	,mTexture(nullptr)
	,mDrawOrder(drawOrder)
	,mTexWidth(0)
	,mTexHeight(0)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(Shader* shader)
{
	if (mTexture)
	{
	Matrix4 matri = Matrix4::CreateScale(static_cast<float>(mTexWidth), static_cast<float>(mTexHeight), 1.0f);
	Matrix4 mat=matri *mOwner->GetWorldMatrix();
	shader->SetUniformMatrix("uWorldTransform", mat);

	mTexture->SetActive();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	}
}

void SpriteComponent::SetTexture(Texture* texture)
{
	mTexture = texture;
	// Set width/height
	mTexWidth = texture->GetWidth();
	mTexHeight = texture->GetHieght();
}
