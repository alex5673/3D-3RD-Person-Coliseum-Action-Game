#include "IntroScreen.h"

CIntroScreen::CIntroScreen()
{
}


CIntroScreen::~CIntroScreen()
{
}

void CIntroScreen::Activate()
{
	m_isActive = true;
	m_alpha = 1.0f;

	CTexture thunderStormTexture;
	thunderStormTexture.Load("Resources\\Textures\\thunder.jpg", false);
	m_textureID = thunderStormTexture.m_textureID;
}

void CIntroScreen::Deactivate()
{
	m_isActive = false;
	m_alpha = 0;
}

void CIntroScreen::SetOrthographicProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glGetIntegerv(GL_VIEWPORT, m_viewport);
	int w = m_viewport[2];
	int h = m_viewport[3];

	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}

void CIntroScreen::RestorePerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

// Render a full-screen quad with varying transparency
void CIntroScreen::Render(float red, float green, float blue)
{

	if (m_isActive == false)
		return;

	// Set the OpenGL state and go to 2D mode
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	SetOrthographicProjection();
	glLoadIdentity();

	
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	

	// Render full screen quad
	float w = (float)m_viewport[2];
	float h = (float)m_viewport[3];
	glColor4f(red, green, blue, m_alpha);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(w, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(w, h, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, h, 0);
	glEnd();
	
	
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	

	// Go back to 3D mode (perspective projection)
	RestorePerspectiveProjection();
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

}