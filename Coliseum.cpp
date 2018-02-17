#include "Coliseum.h"

CColiseum::CColiseum() {

}

CColiseum::~CColiseum() {

}

void CColiseum::Intialise() {
	m_mesh.Load("Resources\\Meshes\\free_arena.obj");
}

void CColiseum::Render() {
	glPushMatrix();
		glTranslatef(-10.0f, -8.5f, -10.0f);
		glScalef(6, 6, 6); 
		m_mesh.Render();
	glPopMatrix();

}