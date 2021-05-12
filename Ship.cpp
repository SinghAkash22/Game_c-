// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "InputComponent.h"
#include "Laser.h"

Ship::Ship(Game* game)
	:Actor(game)
	
{ 
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this,150);
	std::vector<Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),   
		game->GetTexture("Assets/Ship04.png"),
	};
	Lassercool = 0.0f;
	asc->SetAnimTextures(anims);
	InputComponent* inp = new  InputComponent(this);
	inp->SetForwardKey(SDL_SCANCODE_W);
	inp->SetBackKey(SDL_SCANCODE_S);
	inp->SetClockwiseKey(SDL_SCANCODE_A);
	inp->SetCounterClockwiseKey(SDL_SCANCODE_D);
	inp->SetForwardSpeed(300.0f);
	inp->SetAngularSpeed(Math::TwoPi);
	inp->SetMaxForwardSpeed(300.0f);
	inp->SetMaxAngularSpeed(Math::TwoPi);
}

void Ship::UpdateActor(float deltaTime)
{
	Lassercool -= deltaTime;
	// Update position based on speeds and delta time
	
}

void Ship::ActorInput(const uint8_t* state)
{
	
	if (state[SDL_SCANCODE_SPACE] && Lassercool <= 0.0f)
	{
		class Laser* ls = new Laser(GetGame());
		ls->SetPosition(GetPosition());
		ls->SetRotation(GetRotation());
		Lassercool = 0.5f;
	}
}
