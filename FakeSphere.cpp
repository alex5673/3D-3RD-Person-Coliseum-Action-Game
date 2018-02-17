#include "FakeSphere.h"

#include ".\include\glut.h"

CFakeSphere::CFakeSphere() {}

CFakeSphere::~CFakeSphere() {}

void CFakeSphere::Initialise(CVector3f position) {
	CPickup::Initialise(position);
}

void CFakeSphere::Update(CPlayer &player, CAudio &audio, CAlphaSphere &alphaSphere) {
	// Check distance to player
	CVector3f distance = player.GetPosition() - m_position;
	if (distance.Length() < 3.0f) {
		m_isActive = false;
		audio.PlayEventSound();
		alphaSphere.Activate(1.0f, CVector3f(1.0, 0.0, 1.0), CVector3f(0.0, 1.0, 1.0), true, 0.25f);
		player.PushBack();
	}
}

void CFakeSphere::Render() {
	if (m_isActive == true) {
		glColor4f(1, 1, 1, 1);
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glutSolidSphere(0.5, 10, 10);
		glPopMatrix();
	}
}