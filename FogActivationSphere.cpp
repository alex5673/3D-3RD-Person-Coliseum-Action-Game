#include "FogActivationSphere.h"

#include ".\include\glut.h"

CFogActivationSphere::CFogActivationSphere() {}

CFogActivationSphere::~CFogActivationSphere() {}

void CFogActivationSphere::Initialise(CVector3f position) {
	CPickup::Initialise(position);
}

void CFogActivationSphere::Update(CPlayer &player, CAudio &audio, CSpecialFX &fog) {
	// Check distance to player
	CVector3f distance = player.GetPosition() - m_position;
	if (distance.Length() < 3.0f) {
		m_isActive = false;
		audio.PlayEventSound();
		fog.ActivateFog(0.01, 0.6, 0.6, 0.6);
	}
}

void CFogActivationSphere::Render() {
	if (m_isActive == true) {
		glColor4f(1, 1, 1, 1);
		glPushMatrix();
			glTranslatef(m_position.x, m_position.y, m_position.z);
			glutSolidSphere(0.5, 10, 10);
		glPopMatrix();
	}
}