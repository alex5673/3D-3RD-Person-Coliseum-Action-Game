#include "Pillar.h"

CPillar::CPillar() {

}

CPillar::CPillar(CVector3f pos) {
	m_position = pos;
}

CPillar::~CPillar() {

}

void CPillar::Intialise() {
	m_mesh.Load("Resources\\Meshes\\Roman Pillar.3ds");
	m_bbox.SetBottom(CVector3f(m_position.x, 0.0f, m_position.z));
	m_bbox.SetSize(3.0f, 20.0f, 3.0f);
}

void CPillar::Render() {
	glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(-90, 1, 0, 0);
		glScalef(0.03, 0.03, 0.03);
		m_mesh.Render();
	glPopMatrix();

	/*
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	m_bbox.Render(1, 0, 0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	*/
}

CBoundingBox CPillar::GetBBox() const {
	return m_bbox;
}

CVector3f CPillar::GetPosition() const {
	return m_position;
}

void CPillar::SetPosition(CVector3f pos) {
	m_position = pos;
}