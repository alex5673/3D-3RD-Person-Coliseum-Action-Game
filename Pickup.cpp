#include "Pickup.h"
#include ".\include\glut.h"

CPickup::CPickup()
{}

CPickup::~CPickup()
{}

void CPickup::Initialise(CVector3f p)
{
	m_isActive = true;
	m_theta = 0.0f;
	m_position = p;
}

void CPickup::Update(CVector3f cameraPos, float dt)
{
	// Check distance to camera
	CVector3f distance = cameraPos - m_position;
	if (distance.Length() < 2.0f) {
		m_isActive = false;
	}

	m_theta += dt * 50.f;
}

bool CPickup::Active() const {
	return m_isActive;
}

CVector3f CPickup::GetPosition() const {
	return m_position;
}