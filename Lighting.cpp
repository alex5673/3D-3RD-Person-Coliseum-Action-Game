#include "Lighting.h"



void CLighting::SetDefaultLighting()
{
	glEnable(GL_LIGHTING);

	GLfloat ambientLight0[] = {0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat diffuseLight0[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat specularLight0[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat positionLight0[] = {0.0f, 1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glLightfv(GL_LIGHT0, GL_POSITION, positionLight0);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);

}

void CLighting::SetLights(CVector3f p0, CVector3f p1, CVector3f p2) {
	
	glEnable(GL_LIGHTING);

	
    GLfloat ambientLight0[] = {0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat diffuseLight0[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat specularLight0[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat positionLight0[] = {0.0f, 1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glLightfv(GL_LIGHT0, GL_POSITION, positionLight0);

	
	// Main point light
	GLfloat ambientLight3[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight3[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat specularLight3[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat positionLight3[] = { p0.x, p0.y, p0.z, 1.0f };
	glLightfv(GL_LIGHT3, GL_AMBIENT, ambientLight3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specularLight3);
	glLightfv(GL_LIGHT3, GL_POSITION, positionLight3);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.01);

	// light above sphere one
	GLfloat ambientLight1[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularLight1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat positionLight1[] = { p1.x, p1.y + 2, p1.z, 1.0f };
	GLfloat spotDirection[] = { 0.0f, -1.0, 0.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	glLightfv(GL_LIGHT1, GL_POSITION, positionLight1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0f);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.8f);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01);


	// light above sphere two
	GLfloat ambientLight2[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularLight2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat positionLight2[] = { p2.x, p2.y + 2, p2.z, 1.0f };
	GLfloat spotDirection1[] = { 0.0f, -1.0, 0.0f };
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight2);
	glLightfv(GL_LIGHT2, GL_POSITION, positionLight2);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDirection1);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 60.0f);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0.8f);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);


	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_NORMALIZE);
}