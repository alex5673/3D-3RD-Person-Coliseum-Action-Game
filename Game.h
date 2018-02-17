#pragma once

#define _USE_MATH_DEFINES								// Will allow certain constants (like M_PI) to be availabe from <math.h>

#include <windows.h>									// Header File For the Windows Library
#include <stdio.h>										// Header File For the Standard Input/Output Functions
#include <stdlib.h>										// Header File For the Standard Library
#include <math.h>										// Header File For the Math header file
#include ".\include\glew.h"								// Header File For the GLEW Library
#include ".\include\gl.h"								// Header File For the OpenGL32 Library
#include ".\include\glu.h"								// Header File For the GLu32 Library

// Includes for game objects
#include "Camera.h"
#include "Gamewindow.h"
#include "HighResolutionTimer.h"
#include "Terrain.h"
#include "SkyBox.h"
#include "OpenAssetImporterMesh.h"
#include "Audio.h"
#include "Text.h"
#include "Lighting.h"
#include "Material.h"
#include "Md2Animation.h"
#include "SpecialFX.h"
#include "Pickup.h"
#include "StrengthPoweUp.h"
#include "Player.h"
#include "FanGrin.h"
#include "CrossFade.h"
#include "IntroScreen.h"
#include "Coliseum.h"
#include "Pillar.h"
#include "FogActivationSphere.h"
#include "AlphaSphere.h"
#include "FakeSphere.h"

class Game {
public:

private:
	void Initialise();		// Initialises the games (load assets, etc.)
	void Update();			// Update the simulation at each time step
	void Render();			// Render the scene
	void GameLoop();		// The game loop

	// Game objects
	Camera m_camera;								// The camera
	CHighResolutionTimer m_highResolutionTimer;		// A timer for measuring the time between frames
	CHighResolutionTimer m_controlScreenTimer;      // A timer for detremining how long to show the controls to the player before starting the game
	CHighResolutionTimer m_timeTakenTimer;          // A timer for telling how long the player has taken to do wave so far
	CTerrain m_terrain;								// The terrain (planar)
	CSkybox m_skybox;								// A skybox surrounding the scene
	CAudio m_audio;									// Audio using FMOD
	CText m_text1;									// Text for the head's up display
	CText m_text2;
	CText m_text3;
	CText m_text4;
	CText m_text5;
	CText m_text6;
	CText m_text7;
	CText m_text8;
	CText m_text9;
	CText m_text10;
	CText m_text11;
	CText m_text12; // wave number
	CText m_text13; // time taken so far for wave
	CText m_text14; // wave completed
	CText m_text15; // game over
	CLighting m_lighting;							// Lighting 
	CMaterial m_material;							// Material
	CColiseum m_coliseum; // A mesh of a colisieum
	CSpecialFX m_fx;                                
	CStrengthPowerUP m_katana;						// A strength boosting pickup
	CStrengthPowerUP m_katana2;
	CStrengthPowerUP m_katana3;
	CPlayer m_player;								// Player class
	CFanGrin m_fanGrin;								// An enemy
	CFanGrin m_fanGrin2;
	CFanGrin m_fanGrin3;
	CFanGrin m_fanGrin4;
	CFanGrin m_fanGrin5;
	CCrossFade m_crossFade;							// Cross fade special effect
	CIntroScreen m_introScreen;						// Intro Screen
	CPillar m_pillar = CVector3f(-60, 10, 0);		    // Pillar to be placed withing colliseum
	CPillar m_pillar2 = CVector3f(0, 10,-60);
	CPillar m_pillar3 = CVector3f(0, 10, 40);
	CPillar m_pillar4 = CVector3f(40, 10, 0);
	CFogActivationSphere m_fogSphere;
	CAlphaSphere m_alphaSphere;
	CFakeSphere m_fakeSphere;

	bool m_introScreenOn;							// A boolean flag indicating if the intro screen is on
	bool m_difficultySelectOn;						// A boolean flag indicating if the difficulty selection is being shown to the player
	bool m_controlScreenOn;							// A boolean flag indicating if the controls are being shown to the player
	bool m_easyMode;								// Easy Mode Selected
	bool m_normalMode;								// Normal Mode Selected
	bool m_hardMode;								// Hard Mode Selected
	double m_dt;									// A variable to measure the amount of time elasped between frames
	int m_animation;								// Current animation of MD2 model
	vector<CFanGrin*> m_enemies;
	vector<CPillar*> m_pillars;
	bool m_mainThemeAudioLoaded;
	int m_enemyCount;
	bool m_gameOver;

public:
	~Game();
	static Game& GetInstance();
	WPARAM Execute();
	void SetHinstance(HINSTANCE hinstance);
	LRESULT ProcessEvents(HWND window,UINT message, WPARAM w_param, LPARAM l_param);
	
	void EnemyActions();

private:
	Game::Game();
	Game::Game(const Game&);
	void Game::operator=(const Game&);

	GameWindow m_GameWindow;
	HINSTANCE m_hinstance;


};