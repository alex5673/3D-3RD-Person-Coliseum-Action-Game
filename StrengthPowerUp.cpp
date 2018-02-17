#include "StrengthPoweUp.h"
#include ".\include\glut.h"

CStrengthPowerUP::CStrengthPowerUP() {}

CStrengthPowerUP::~CStrengthPowerUP() {}

void CStrengthPowerUP::Initialise(CVector3f position) {
	CPickup::Initialise(position);

	CTexture bladeMetalTexture, goldTexture, blackMetalTexture, katanaHandleTexture;
	bladeMetalTexture.Load("Resources\\Textures\\bladeMetal.jpg", false);
	goldTexture.Load("Resources\\Textures\\gold.jpg", false);
	blackMetalTexture.Load("Resources\\Textures\\blackMetal.jpg", false);
	katanaHandleTexture.Load("Resources\\Textures\\katanaHandle.jpg", false);
	m_bladeMetalTextureID = bladeMetalTexture.m_textureID;
	m_goldTextureID = goldTexture.m_textureID;
	m_blackMetalTextureID = blackMetalTexture.m_textureID;
	m_katanaHandleTextureID = katanaHandleTexture.m_textureID;
}

void CStrengthPowerUP::Update(CPlayer &player, CAudio &audio) {
	// Check distance to player
	CVector3f distance = player.GetPosition() - m_position;
	if (distance.Length() < 3.0f) {
		m_isActive = false;
		audio.PlayEventSound();
		player.SetAttackStrength(player.GetAttackStrength() * 2);
	}
}

void CStrengthPowerUP::Render()
{


	if (m_isActive == true) {

		glColor4f(1, 1, 1, 1);

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glEnable(GL_TEXTURE_2D);
		
	    // Katana shape

		// Front of blade 

		glBindTexture(GL_TEXTURE_2D, m_bladeMetalTextureID);

		// Blade
		glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + 0.54, m_position.z + 0.13);
			glTexCoord2f(0.73, 0.94);
			glVertex3f(m_position.x, m_position.y + 0.39, m_position.z + 0.21); // 0.39, 0.21
			glTexCoord2f(0.51, 0.85);
			glVertex3f(m_position.x, m_position.y + 0.27, m_position.z + 0.33); // 0.27, 0.33
			glTexCoord2f(0.24, 0.69);
			glVertex3f(m_position.x, m_position.y + 0.12, m_position.z + 0.54); // 0.12, 0.54
			glTexCoord2f(0.18, 0.6);
			glVertex3f(m_position.x, m_position.y + 0.09, m_position.z + 0.66); // 0.09, 0.66
			glTexCoord2f(0.07, 0.42);
			glVertex3f(m_position.x, m_position.y + 0.03, m_position.z + 0.9); // 0.03, 0.9
			glTexCoord2f(0, 0.17);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.23); // -0.03, 1.23
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.44); // -0.03, 1.44
			glTexCoord2f(0.39, 0);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.44); // 0.18, 1.44
			glTexCoord2f(0.46, 0.16);
			glVertex3f(m_position.x, m_position.y + 0.22, m_position.z + 1.23); // 0.24, 1.23
			glTexCoord2f(0.52, 0.38);
			glVertex3f(m_position.x, m_position.y + 0.28, m_position.z + 0.93); // 0.36, 0.93
			glTexCoord2f(0.63, 0.63);
			glVertex3f(m_position.x, m_position.y + 0.34, m_position.z + 0.6); // 0.39, 0.6
			glTexCoord2f(0.74, 0.74);
			glVertex3f(m_position.x, m_position.y + 0.40, m_position.z + 0.45); // 0.42, 0.45
			glTexCoord2f(0.88, 0.77);
			glVertex3f(m_position.x, m_position.y + 0.48, m_position.z + 0.3); // 0.48, 0.3
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_goldTextureID);
		// Blade holder
		glBegin(GL_QUADS);
			CVector3f normal1 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.44f);
			glNormal3f(normal1.x, normal1.y, normal1.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.44); // -0.03, 1.44
			CVector3f normal2 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal2.x, normal2.y, normal2.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.65); // -0.03, 1.65
			CVector3f normal3 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.44f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.65f);
			glNormal3f(normal3.x, normal3.y, normal3.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.65); // 0.18, 1.65
			CVector3f normal4 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal4.x, normal4.y, normal4.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.44); // 0.18, 1.44 
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Cross section
		glBegin(GL_QUADS);
			CVector3f normal5 = CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.65f);
			glNormal3f(normal5.x, normal5.y, normal5.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + -0.25, m_position.z + 1.65); // -0.25, 1.65
			CVector3f normal6 = CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal6.x, normal6.y, normal6.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.25, m_position.z + 1.71); // -0.25, 1.71
			CVector3f normal7 = CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.65f);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + 0.4, m_position.z + 1.71); // 0.25, 1,71
			CVector3f normal8 = CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal8.x, normal8.y, normal8.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.4, m_position.z + 1.65); // 0.25, 1.65
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_katanaHandleTextureID);
		// Handle
		glBegin(GL_QUADS);
			CVector3f normal9 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.71f);
			glNormal3f(normal9.x, normal9.y, normal9.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.71); // -0.03, 1.71
			CVector3f normal10 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 2.31f);
			glNormal3f(normal10.x, normal10.y, normal10.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 2.31); // -0.03, 2.31
			CVector3f normal11 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 2.31f);
			glNormal3f(normal11.x, normal11.y, normal11.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 2.31); // 0.18, 2.31
			CVector3f normal12 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal12.x, normal12.y, normal12.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.71); // 0.18, 1.71
		glEnd();

		
		// Back of blade

		glBindTexture(GL_TEXTURE_2D, m_bladeMetalTextureID);
		// Blade
		glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0.39, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.44); // -0.03, 1.44
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.44); // -0.03, 1.23
			glTexCoord2f(0, 0.16);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.23); // 0.03, 0.9
			glTexCoord2f(0.11, 0.41);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.03, m_position.z + 0.9); // 0.09, 0.66
			glTexCoord2f(0.22, 0.59);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.09, m_position.z + 0.66); // 0.12, 0.54
			glTexCoord2f(0.27, 0.65);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.12, m_position.z + 0.54); // 0.27, 0.33
			glTexCoord2f(0.64, 0.81);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.27, m_position.z + 0.33); // 0.39, 0.21
			glTexCoord2f(0.86, 0.9);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.39, m_position.z + 0.21);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.54, m_position.z + 0.13); // 0.48, 0.3
			glTexCoord2f(0.89, 0.87);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.48, m_position.z + 0.3); // 0.42, 0.45
			glTexCoord2f(0.74, 0.76);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.40, m_position.z + 0.45); // 0.39, 0.6
			glTexCoord2f(0.63, 0.65);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.34, m_position.z + 0.6); // 0.36, 0.93
			glTexCoord2f(0.52, 0.4);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.28, m_position.z + 0.93); // 0.24, 1.23
			glTexCoord2f(0.41, 0.17);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.22, m_position.z + 1.23); // 0.18, 1.44
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_goldTextureID);
		// Blade holder
		glBegin(GL_QUADS);
			CVector3f normal13 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.44f);
			glNormal3f(normal13.x, normal13.y, normal13.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.65); // -0.03, 1.65
			CVector3f normal14 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal14.x, normal14.y, normal14.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.65); // -0.03, 1.44
			CVector3f normal15 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.44f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.65f);
			glNormal3f(normal15.x, normal15.y, normal15.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.44); // 0.18, 1.44
			CVector3f normal16 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.44f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.65f);
			glNormal3f(normal16.x, normal16.y, normal16.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.44); // 0.18, 1.65
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Cross section
		glBegin(GL_QUADS);
			CVector3f normal17 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.65f);
			glNormal3f(normal17.x, normal17.y, normal17.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 1.71); // -0.25, 1.71
			CVector3f normal18 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal18.x, normal18.y, normal18.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.25, m_position.z + 1.71); // -0.25, 1.65
			CVector3f normal19 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.71f);
			glNormal3f(normal19.x, normal19.y, normal19.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.25, m_position.z + 1.65); // 0.25, 1.65
			CVector3f normal20 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.71f);
			glNormal3f(normal20.x, normal20.y, normal20.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 1.65); // 0.25, 1,71 
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_katanaHandleTextureID);
		// Handle
		glBegin(GL_QUADS);
			CVector3f normal21 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.71f);
			glNormal3f(normal21.x, normal21.y, normal21.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 2.31); // -0.03, 2.31
			CVector3f normal22 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal22.x, normal22.y, normal22.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 2.31); // -0.03, 1.71
			CVector3f normal23 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 2.31f);
			glNormal3f(normal23.x, normal23.y, normal23.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.71); // 0.18, 1.71
			CVector3f normal24 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f);
			glNormal3f(normal24.x, normal24.y, normal24.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.71); // 0.18, 2.31
		glEnd();


		// Polygons inbetween

		glBindTexture(GL_TEXTURE_2D, m_bladeMetalTextureID);
		// Top of blade
		glBegin(GL_POLYGON);
			CVector3f normal25 = CVector3f(m_position.x, m_position.y + 0.48f, m_position.z + 0.3f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.54f, m_position.z + 0.13f);
			glNormal3f(normal25.x, normal25.y, normal25.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.54, m_position.z + 0.13);
			CVector3f normal26 = CVector3f(m_position.x, m_position.y + 0.40f, m_position.z + 0.45f) % CVector3f(m_position.x, m_position.y + 0.54f, m_position.z + 0.13f);
			glNormal3f(normal26.x, normal26.y, normal26.z);
			glTexCoord2f(0, 0.87);
			glVertex3f(m_position.x, m_position.y + 0.48, m_position.z + 0.3);
			CVector3f normal27 = CVector3f(m_position.x, m_position.y + 0.34f, m_position.z + 0.6f) % CVector3f(m_position.x, m_position.y + 0.48f, m_position.z + 0.3f);
			glNormal3f(normal27.x, normal27.y, normal27.z);
			glTexCoord2f(0, 0.76);
			glVertex3f(m_position.x, m_position.y + 0.40, m_position.z + 0.45);
			CVector3f normal28 = CVector3f(m_position.x, m_position.y + 0.28f, m_position.z + 0.93f) % CVector3f(m_position.x, m_position.y + 0.40f, m_position.z + 0.45f);
			glNormal3f(normal28.x, normal28.y, normal28.z);
			glTexCoord2f(0, 0.65);
			glVertex3f(m_position.x, m_position.y + 0.34, m_position.z + 0.6);
			CVector3f normal29 = CVector3f(m_position.x, m_position.y + 0.22f, m_position.z + 1.23f) % CVector3f(m_position.x, m_position.y + 0.34f, m_position.z + 0.6f);
			glNormal3f(normal29.x, normal29.y, normal29.z);
			glTexCoord2f(0, 0.4);
			glVertex3f(m_position.x, m_position.y + 0.28, m_position.z + 0.93);
			CVector3f normal30 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.44f) % CVector3f(m_position.x, m_position.y + 0.28f, m_position.z + 0.93f);
			glNormal3f(normal30.x, normal30.y, normal30.z);
			glTexCoord2f(0, 0.17);
			glVertex3f(m_position.x, m_position.y + 0.22, m_position.z + 1.23);
			CVector3f normal31 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.44f) % CVector3f(m_position.x, m_position.y + 0.22f, m_position.z + 1.23f);
			glNormal3f(normal31.x, normal31.y, normal31.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.44);
			CVector3f normal32 = CVector3f(m_position.x + 0.05f, m_position.y + 0.22f, m_position.z + 1.23f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.44f);
			glNormal3f(normal32.x, normal32.y, normal32.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.44);
			CVector3f normal33 = CVector3f(m_position.x + 0.05f, m_position.y + 0.28f, m_position.z + 0.93f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.44f);
			glNormal3f(normal33.x, normal33.y, normal33.z);
			glTexCoord2f(1, 0.17);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.22, m_position.z + 1.23);
			CVector3f normal34 = CVector3f(m_position.x + 0.05f, m_position.y + 0.34f, m_position.z + 0.6f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.22f, m_position.z + 1.23f);
			glNormal3f(normal34.x, normal34.y, normal34.z);
			glTexCoord2f(1, 0.4);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.28, m_position.z + 0.93);
			CVector3f normal35 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 0.45f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.28f, m_position.z + 0.93f);
			glNormal3f(normal35.x, normal35.y, normal35.z);
			glTexCoord2f(1, 0.65);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.34, m_position.z + 0.6);
			CVector3f normal36 = CVector3f(m_position.x + 0.05f, m_position.y + 0.48f, m_position.z + 0.3f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.34f, m_position.z + 0.6f);
			glNormal3f(normal36.x, normal36.y, normal36.z);
			glTexCoord2f(1, 0.76);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 0.45);
			CVector3f normal37 = CVector3f(m_position.x + 0.05f, m_position.y + 0.54f, m_position.z + 0.13f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 0.45f);
			glNormal3f(normal37.x, normal37.y, normal37.z);
			glTexCoord2f(1, 0.87);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.48, m_position.z + 0.3);
			CVector3f normal38 = CVector3f(m_position.x, m_position.y + 0.54f, m_position.z + 0.13f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.48f, m_position.z + 0.3f);
			glNormal3f(normal38.x, normal38.y, normal38.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.54, m_position.z + 0.13);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_bladeMetalTextureID);
		// Underside of blade
		glBegin(GL_POLYGON);
			CVector3f normal39 = CVector3f(m_position.x + 0.05f, m_position.y + 0.39f, m_position.z + 0.21f) % CVector3f(m_position.x, m_position.y + 0.54f, m_position.z + 0.13f);
			glNormal3f(normal39.x, normal39.y, normal39.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.54, m_position.z + 0.13);
			CVector3f normal40 = CVector3f(m_position.x + 0.05f, m_position.y + 0.27f, m_position.z + 0.33f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.54f, m_position.z + 0.13f);
			glNormal3f(normal40.x, normal40.y, normal40.z);
			glTexCoord2f(0, 0.94);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.39, m_position.z + 0.21);
			CVector3f normal41 = CVector3f(m_position.x + 0.05f, m_position.y + 0.03f, m_position.z + 0.9f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.39f, m_position.z + 0.21f);
			glNormal3f(normal40.x, normal40.y, normal40.z);
			glTexCoord2f(0, 0.85);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.27, m_position.z + 0.33);
			CVector3f normal42 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.23f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.27f, m_position.z + 0.33f);
			glNormal3f(normal42.x, normal42.y, normal42.z);
			glTexCoord2f(0, 0.41);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.03, m_position.z + 0.9);
			CVector3f normal43 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.44f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.03f, m_position.z + 0.9f);
			glNormal3f(normal43.x, normal43.y, normal43.z);
			glTexCoord2f(0, 0.16);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.23);
			CVector3f normal44 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.44f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.23f);
			glNormal3f(normal44.x, normal44.y, normal44.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.44);
			CVector3f normal45 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.23f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal45.x, normal45.y, normal45.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.44);
			CVector3f normal46 = CVector3f(m_position.x, m_position.y + 0.03f, m_position.z + 0.9f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal46.x, normal46.y, normal46.z);
			glTexCoord2f(1, 0.16);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.23);
			CVector3f normal47 = CVector3f(m_position.x, m_position.y + 0.27f, m_position.z + 0.33f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.23f);
			glNormal3f(normal47.x, normal47.y, normal47.z);
			glTexCoord2f(1, 0.41);
			glVertex3f(m_position.x, m_position.y + 0.03, m_position.z + 0.9);
			CVector3f normal48 = CVector3f(m_position.x, m_position.y + 0.39f, m_position.z + 0.21f) % CVector3f(m_position.x, m_position.y + 0.03f, m_position.z + 0.9f);
			glNormal3f(normal48.x, normal48.y, normal48.z);
			glTexCoord2f(1, 0.85);
			glVertex3f(m_position.x, m_position.y + 0.27, m_position.z + 0.33);
			CVector3f normal49 = CVector3f(m_position.x, m_position.y + 0.54f, m_position.z + 0.13f) % CVector3f(m_position.x, m_position.y + 0.27f, m_position.z + 0.33f);
			glNormal3f(normal49.x, normal49.y, normal49.z);
			glTexCoord2f(1, 0.94);
			glVertex3f(m_position.x, m_position.y + 0.39, m_position.z + 0.21);
			CVector3f normal50 = CVector3f(m_position.x + 0.05f, m_position.y + 0.54f, m_position.z + 0.13f) % CVector3f(m_position.x, m_position.y + 0.39f, m_position.z + 0.21f);
			glNormal3f(normal50.x, normal50.y, normal50.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + 0.54, m_position.z + 0.13);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_goldTextureID);
		// Top of blade holder
		glBegin(GL_QUADS);
			CVector3f normal51 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.44f);
			glNormal3f(normal51.x, normal51.y, normal51.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.65);
			CVector3f normal52 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.44f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.65f);
			glNormal3f(normal52.x, normal52.y, normal52.z);
			glTexCoord2f(1, 0);			
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.65);
			CVector3f normal53 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.44f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.65f);
			glNormal3f(normal53.x, normal53.y, normal53.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.44);
			CVector3f normal54 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.44f);
			glNormal3f(normal54.x, normal54.y, normal54.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.44);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_goldTextureID);
		// Bottom of blade holder
		glBegin(GL_QUADS);
			CVector3f normal55 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal55.x, normal55.y, normal55.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.44);
			CVector3f normal56 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.44f);
			glNormal3f(normal56.x, normal56.y, normal56.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.65);
			CVector3f normal57 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.44f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.65f);
			glNormal3f(normal57.x, normal57.y, normal57.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.65);
			CVector3f normal58 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.44f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.65f);
			glNormal3f(normal58.x, normal58.y, normal58.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.44);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Onward facing top half of cross section
		glBegin(GL_QUADS);
			CVector3f normal59 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.65f);
			glNormal3f(normal59.x, normal59.y, normal59.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.65);
			CVector3f normal60 = CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.65f);
			glNormal3f(normal60.x, normal60.y, normal60.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.65);
			CVector3f normal61 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.65f);
			glNormal3f(normal61.x, normal61.y, normal61.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + 0.4, m_position.z + 1.65);
			CVector3f normal62 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.65f);
			glNormal3f(normal62.x, normal62.y, normal62.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 1.65);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Omward facing bottom half of cross section
		glBegin(GL_QUADS);
			CVector3f normal63 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.65f);
			glNormal3f(normal63.x, normal63.y, normal63.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.65);
			CVector3f normal64 = CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.65f);
			glNormal3f(normal64.x, normal64.y, normal64.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.25, m_position.z + 1.65);
			CVector3f normal65 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal65.x, normal65.y, normal65.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.25, m_position.z + 1.65);
			CVector3f normal66 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal66.x, normal66.y, normal66.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.65);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Top of cross section
		glBegin(GL_QUADS);
			CVector3f normal67 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.65f);
			glNormal3f(normal67.x, normal67.y, normal67.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + 0.4, m_position.z + 1.71);
			CVector3f normal68 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.71f);
			glNormal3f(normal68.x, normal68.y, normal68.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 1.71);
			CVector3f normal69 = CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.71f);
			glNormal3f(normal69.x, normal69.y, normal69.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 1.65);
			CVector3f normal70 = CVector3f(m_position.x, m_position.y + 0.4f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.65f);
			glNormal3f(normal70.x, normal70.y, normal70.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.4, m_position.z + 1.65);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Bottom of cross section
		glBegin(GL_QUADS);
			CVector3f normal71 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal71.x, normal71.y, normal71.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.25, m_position.z + 1.65);
			CVector3f normal72 = CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.65f);
			glNormal3f(normal72.x, normal72.y, normal72.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.25, m_position.z + 1.71);
			CVector3f normal73 = CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.65f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.71f);
			glNormal3f(normal73.x, normal73.y, normal73.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.25, m_position.z + 1.71);
			CVector3f normal74 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.65f) % CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.71f);
			glNormal3f(normal74.x, normal74.y, normal74.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + -0.25, m_position.z + 1.65);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Backwards facing top half of cross section
		glBegin(GL_QUADS);
			CVector3f normal75 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.71f);
			glNormal3f(normal75.x, normal75.y, normal75.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.40, m_position.z + 1.71);
			CVector3f normal76 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.40f, m_position.z + 1.71f);
			glNormal3f(normal76.x, normal76.y, normal76.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.71);
			CVector3f normal77 = CVector3f(m_position.x + 0.05f, m_position.y + 0.4f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.71f);
			glNormal3f(normal77.x, normal77.y, normal77.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.71);
			CVector3f normal78 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + 0.40f, m_position.z + 1.71f);
			glNormal3f(normal78.x, normal78.y, normal78.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.4, m_position.z + 1.71);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Backwards facing bottom half of cross section
		glBegin(GL_QUADS);
			CVector3f normal79 = CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal79.x, normal79.y, normal79.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.71);
			CVector3f normal80 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal80.x, normal80.y, normal80.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + -0.25, m_position.z + 1.71);
			CVector3f normal81 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.25f, m_position.z + 1.71f);
			glNormal3f(normal81.x, normal81.y, normal81.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.25, m_position.z + 1.71);
			CVector3f normal82 = CVector3f(m_position.x + 0.05f, m_position.y + -0.25f, m_position.z + 1.71f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal82.x, normal82.y, normal82.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.71);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Top of blade handle
		glBegin(GL_QUADS);
			CVector3f normal83 = CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 1.71f);
			glNormal3f(normal83.x, normal83.y, normal83.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 1.71);
			CVector3f normal84 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.71f);
			glNormal3f(normal84.x, normal84.y, normal84.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 2.31);
			CVector3f normal85 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 2.31f);
			glNormal3f(normal85.x, normal85.y, normal85.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 2.31);
			CVector3f normal86 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 1.71f);
			glNormal3f(normal86.x, normal86.y, normal86.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 1.71);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Bottom of blade handle
		glBegin(GL_QUADS);
			CVector3f normal87 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal87.x, normal87.y, normal87.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 1.71);
			CVector3f normal88 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal88.x, normal88.y, normal88.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 2.31);
			CVector3f normal89 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 1.71f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 2.31f);
			glNormal3f(normal89.x, normal89.y, normal89.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 2.31);
			CVector3f normal90 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 1.71f);
			glNormal3f(normal90.x, normal90.y, normal90.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 1.71);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, m_blackMetalTextureID);
		// Bottom of Katana
		glBegin(GL_QUADS);
			CVector3f normal91 = CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f);
			glNormal3f(normal91.x, normal91.y, normal91.z);
			glTexCoord2f(0, 1);
			glVertex3f(m_position.x, m_position.y + 0.18, m_position.z + 2.31);
			CVector3f normal92 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 2.31f);
			glNormal3f(normal92.x, normal92.y, normal92.z);
			glTexCoord2f(0, 0);
			glVertex3f(m_position.x, m_position.y + -0.03, m_position.z + 2.31);
			CVector3f normal93 = CVector3f(m_position.x + 0.05f, m_position.y + 0.18f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + -0.03f, m_position.z + 2.31f);
			glNormal3f(normal93.x, normal93.y, normal93.z);
			glTexCoord2f(1, 0);
			glVertex3f(m_position.x + 0.05, m_position.y + -0.03, m_position.z + 2.31);
			CVector3f normal94 = CVector3f(m_position.x + 0.05f, m_position.y + -0.03f, m_position.z + 2.31f) % CVector3f(m_position.x, m_position.y + 0.18f, m_position.z + 2.31f);
			glNormal3f(normal94.x, normal94.y, normal94.z);
			glTexCoord2f(1, 1);
			glVertex3f(m_position.x + 0.05, m_position.y + 0.18, m_position.z + 2.31);
		glEnd();
		

		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);

	}
}