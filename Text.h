#pragma once

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include ".\include\glut.h"	
#include <Windows.h>

class CText
{
public:
	CText();
	~CText();
	void Render(char *text, float x, float y);
	void Create(HDC hdc, char *fontName, int size, float r, float g, float b);

	void ChangeTextColour(float r, float g, float b);
private:
	void SetOrthographicProjection();
	void ResetPerspectiveProjection();
	void RenderBitmapString(float x, float y, char *string);

	float m_red;
	float m_green;
	float m_blue;
};

