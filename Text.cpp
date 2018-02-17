#include "Text.h"


CText::CText()
{}

CText::~CText()
{}



void CText::SetOrthographicProjection()
{
	int w = 400;
	int h = 400;
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the 
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, 800, 0, 600);
	// invert the y axis, down is positive
	glScalef(1.0f, -1.0f, 1.0f);
	// move the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -600, 0);
	glMatrixMode(GL_MODELVIEW);
}


void CText::ResetPerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void CText::Create(HDC hdc, char *fontName, int size, float r, float g, float b)
{
	// Create a Windows font
	HFONT font = ::CreateFont(-size, 0, 0, 0, size, FALSE, FALSE, FALSE, 
							ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE|DEFAULT_PITCH, fontName);
 
	// Select into device context and call wglUseFontBitmaps
	HFONT fontOld = (HFONT) SelectObject(hdc, font);
	wglUseFontBitmaps (hdc, 0, 255, 1000); 

	m_red = r;
	m_green = g;
	m_blue = b;
}

void CText::RenderBitmapString(float x, float y, char *string)
{
	glRasterPos2f(x, y);
	glListBase (1000); 
	glCallLists (strlen(string), GL_UNSIGNED_BYTE, string);
}

void CText::Render(char *text, float x, float y)
{
	glColor3f(m_red, m_green, m_blue);
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
		SetOrthographicProjection();
		glLoadIdentity();
		RenderBitmapString(x, y, text);
		ResetPerspectiveProjection();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
}

void CText::ChangeTextColour(float r, float g, float b) {
	m_red = r;
	m_green = g;
	m_blue = b;
}