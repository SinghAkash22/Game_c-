#include "MomentComponent.h"
#include "Math.h"
#include "Actor.h"

MomentComponent::MomentComponent(class Actor * oWner,int updateOrder)
	:Component(oWner,updateOrder)
{
	mAngularSpeed = 0;
	mForwardSpeed = 0;
}

void MomentComponent::Update(float deltime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltime;
		mOwner->SetRotation(rot);
	}
	if (!Math::NearZero(mForwardSpeed))
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mForwardSpeed * mOwner->GetForword()*deltime;
		if (pos.x < -512.0f) { pos.x = 512.0f; }
		else if (pos.x > 512.0f) { pos.x = -512.0f; }

		if (pos.y < -384.0f) { pos.y = 384.0f; }
		else if (pos.y > 384.0f) { pos.y = -384.0f; }

		mOwner->SetPosition(pos);
	}
}