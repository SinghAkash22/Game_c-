#pragma once
#include "Component.h"
#include "Actor.h"

class MomentComponent :public Component
{
public:
	MomentComponent(class Actor* oWner,int Updateorder=10);
	void Update(float deltime);

	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
private:
	// Controls rotation (radians/second)
	float mAngularSpeed;
	// Controls forward movement (units/second)
	float mForwardSpeed;
};