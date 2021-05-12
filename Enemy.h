#pragma once
#include "Actor.h"

class Enemy :public Actor
{
public:
	Enemy(class Game* game);
	~Enemy();
	class CircleComponent* GetCircle() const { return mcircle; }
private:
	class CircleComponent* mcircle;
};