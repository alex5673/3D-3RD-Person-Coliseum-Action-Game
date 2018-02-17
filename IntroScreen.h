#pragma once
#include <windows.h>		// Header File For The Windows Library

#include ".\include\gl.h"	// Header File For The OpenGL32 Library
#include "Texture.h"
#include "Vector3f.h"
#include <vector>


class CIntroScreen
{
public:
	CIntroScreen();
	~CIntroScreen();
	void Activate();
	void Deactivate();
	void Render(float red, float green, float blue);
private:

	void SetOrthographicProjection();
	void RestorePerspectiveProjection();
	GLint m_viewport[4];

	bool m_isActive;
	float m_alpha;

	UINT m_textureID;
};
