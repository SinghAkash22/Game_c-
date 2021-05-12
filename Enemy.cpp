#include "Enemy.h"
#include "SpriteComponent.h"
#include "MomentComponent.h"
#include "CircleComponent.h"
#include "Math.h"
#include "Random.h"
#include "Game.h"
Enemy::Enemy(class Game* game)
	:Actor(game)
	, mcircle(nullptr)
{
	SpriteComponent * msprit = new SpriteComponent(this);
	msprit->SetTexture(game->GetTexture("Assets/ship.png"));
	Vector2 pos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
	SetPosition(pos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));
	mcircle=  new CircleComponent(this);
	mcircle->SetRadius(40.0f);
	class MomentComponent* momen = new MomentComponent(this);
	momen->SetForwardSpeed(150.0f);
	game->AddEnemy(this);
}
Enemy::~Enemy()
{
	GetGame()->RemovEnemy(this);
}