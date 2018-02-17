#pragma once
#include "Vector3f.h"
class CPickup
{
public:
	CPickup();
	~CPickup();
	void Initialise(CVector3f p);
	void Update(CVector3f cameraPos, float dt);
	void virtual Render() = 0;
	bool Active() const;
	CVector3f GetPosition() const;
protected:
	bool m_isActive; // Indicates if pickup is active
	CVector3f m_position; // Pickup position in 3D
	float m_theta; // Rotation angle
};

