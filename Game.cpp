/* 
OpenGL Template for IN3026
City University London, School of Informatics
Source code drawn from a number of sources and examples, including contributions from
 - Ben Humphrey (gametutorials.com), Christy Quinn, Sam Kellett, and others

 For educational use by Deparment of Computer Science, City University London UK.

 This template contains a skybox, simple terrain, camera, lighting, mesh loader, sipmle physics, texturing, audio

 Potential ways to modify the code:  Add new geometry types, change the terrain, load new meshes, set up lighting, 
 add in additional music / sound FX, modify camera control, put in a startup screen, collision detection, etc.
 
 Template version 4.0a 13/09/2017
 Dr Greg Slabaugh (gregory.slabaugh.1@city.ac.uk) 
*/


#include "Game.h"


// Constructor.  
Game::Game()  
{
	m_introScreenOn = true;
	m_difficultySelectOn = false;
	m_controlScreenOn = false;
	m_easyMode = true;
	m_normalMode = false;
	m_hardMode = false;
	m_dt = 0.0f;
	m_animation = 0;
	m_mainThemeAudioLoaded = false;
	m_enemyCount = 5;
	m_gameOver = false;
}

// Destructor.  Technically we could delete all resources, but when the game ends the OS will free memory for us.
Game::~Game() 
{ 
}

// Initialise the game by loading assets and setting up the scene.  Note, it's best to make OpenGL calls here since we know the rendering context is available.
void Game::Initialise() 
{
	// Initialise the camera (position, view point, upvector, and speed)
	m_camera.Set(CVector3f(45, 2, 45), CVector3f(0, 0, 1), CVector3f(0, 1, 0), 5.0f);
	//m_camera.Set(CVector3f(0, 10, -100), CVector3f(0, 10, 0), CVector3f(0, 1, 0), 5.0f);

	// Top down view with x-axis alligned verticallly and z-axis aligned horizontally
	// m_camera.Set(CVector3f(0, 200, 0), CVector3f(0, 0, 1), CVector3f(1, 0, 0), 5.0f);

	// Create the terrain and skybox
	m_terrain.Initialise();
	m_skybox.Create("", 0.0f);

	// Create a class for rendering text
	m_text1.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0 , 0); // "Press ENTER To Start"
	m_text2.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "APOCAYLPTIC ARENA"
	m_text3.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "Select Difficulty"
	m_text4.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "EASY"
	m_text5.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 1, 1); // "NORMAL"
	m_text6.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 1, 1); // "HARD"
	m_text7.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "KeyBoard Settings"
	m_text8.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "Move Forward: W" 
	m_text9.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "Turn Right: D" 
	m_text10.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "Turn Left: A"
	m_text11.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // "Attack: Spacebar" 
	m_text12.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // Wave number
	m_text13.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // Time taken
	m_text14.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // Wave completed
	m_text11.Create(m_GameWindow.GetHdc(), "Arial", 18, 1, 0, 0); // GameOver

	glClearColor(1, 1, 1, 1);

	// Load some meshes
	m_coliseum.Intialise();

	m_pillar.Intialise();
	m_pillar2.Intialise();
	m_pillar3.Intialise();
	m_pillar4.Intialise();

	m_pillars.push_back(&m_pillar);
	m_pillars.push_back(&m_pillar2);
	m_pillars.push_back(&m_pillar3);
	m_pillars.push_back(&m_pillar4);


	// Initialise audio and play background music
	m_audio.Initialise();
	m_audio.LoadEventSound("Resources\\Audio\\power-up.wav");					// Royalty free sound from freesound.org
	m_audio.LoadMusicStream("Resources\\Audio\\intro-screen.wav");	// Royalty free music from http://www.nosoapradio.us/
	m_audio.PlayMusicStream();
	
	//Initialise FanGrins
	m_fanGrin = CFanGrin(CVector3f(20, 0, 5), 0);
	m_fanGrin.Initialise();

	m_fanGrin2 = CFanGrin(CVector3f(-40, 0, -5), 0);
	m_fanGrin2.Initialise();

	m_fanGrin3 = CFanGrin(CVector3f(-20, 0, -20), 0);
	m_fanGrin3.Initialise();

	m_fanGrin4 = CFanGrin(CVector3f(40, 0, -20), 0);
	m_fanGrin4.Initialise();

	m_fanGrin5 = CFanGrin(CVector3f(30, 0, 20), 0);
	m_fanGrin5.Initialise();

	m_enemies.push_back(&m_fanGrin);
	m_enemies.push_back(&m_fanGrin2);
	m_enemies.push_back(&m_fanGrin3);
	m_enemies.push_back(&m_fanGrin4);
	m_enemies.push_back(&m_fanGrin5);

	m_player.Initialise();

	/*
	// If you plan to load a number of enemies and store them on an std::vector, it is best to use pointers, like this:
	for (unsigned int i = 0; i < 5; i++) {
	   m_enemies.push_back(new CMD2Model);
	   m_enemies[i]->Load(...);
	}
	*/

	//-10.0f, -8.5f, -10.0f

	m_katana.Initialise(CVector3f(-10, 2, -10));
	m_katana2.Initialise(CVector3f(20, 2, 10));
	m_katana3.Initialise(CVector3f(-30, 2, 30));

	m_fogSphere.Initialise(CVector3f(0, 2, 20));
	m_fakeSphere.Initialise(CVector3f(20, 2, -20));
}

// Update game objects using a timer
void Game::Update() 
{
	if ((m_controlScreenOn == true) && (m_controlScreenTimer.Elapsed() > 20)) {
		m_controlScreenOn = false;
		m_introScreen.Deactivate();
		m_timeTakenTimer.Start();
	}

	if ((m_introScreenOn == true) || (m_difficultySelectOn == true) || (m_controlScreenOn == true)) {
		return;
	}

	if(m_player.GetHealth() < 0) {
		m_gameOver = true;
	}

	int enemyCount = 0;
	vector<CFanGrin*>::iterator enemies = m_enemies.begin();
	for (enemies; enemies != m_enemies.end(); enemies++) {
		if ((*enemies)->GetHealth() > 0) {
			enemyCount++;
		}
	}
	m_enemyCount = enemyCount;

	CVector3f playerPos = m_player.GetPosition();
	CVector3f enemyPos1 = m_fanGrin.GetPosition();
	CVector3f enemyPos2 = m_fanGrin2.GetPosition();
	CVector3f enemyPos3 = m_fanGrin3.GetPosition();
	CVector3f enemyPos4 = m_fanGrin4.GetPosition();
	CVector3f enemyPos5 = m_fanGrin5.GetPosition();

	// Update the camera
	//m_camera.Update(m_dt);
	//m_camera.UpdateRail(m_dt);
	m_player.UpdateCamera(m_camera);

	// Often it will be useful to perform collision detection and response in Update()

	// Update the physical simulation

	// Periodically update audio being played back by FMOD
	m_audio.Update();

	// Update player
	m_player.Update(m_dt, m_gameOver);

	// Work out enemy actions
	EnemyActions();

	// Update enemies
	m_fanGrin.Update(m_dt, m_player, m_crossFade, m_pillars);
	m_fanGrin2.Update(m_dt, m_player, m_crossFade, m_pillars);
	m_fanGrin3.Update(m_dt, m_player, m_crossFade, m_pillars);
	m_fanGrin4.Update(m_dt, m_player, m_crossFade, m_pillars);
	m_fanGrin5.Update(m_dt, m_player, m_crossFade, m_pillars);

	// Update strength power ups - the swords
	m_katana.Update(m_player, m_audio);
	m_katana2.Update(m_player, m_audio);
	m_katana3.Update(m_player, m_audio);

	// Update fog sphere - the white sphere
	m_fogSphere.Update(m_player, m_audio, m_fx);

	// Update fake sphere and alpha sphere
	m_fakeSphere.Update(m_player, m_audio, m_alphaSphere);
	m_alphaSphere.Update(m_dt);

	// Update cross fade effect
	m_crossFade.Update(m_dt);

	m_GameWindow.UpdateFrameRate(m_dt);

	// collisions between player and enemies
	int index = 0;
	vector<CFanGrin *>::iterator iter = m_enemies.begin();
	for (iter; iter != m_enemies.end(); iter++) {
		if ((*iter)->GetHealth() > 0) {
			if ((*iter)->GetBBox().Collision(m_player.GetBBox())) {
				m_player.SetPosition(playerPos);
				if (index == 0) {
					(*iter)->SetPosition(enemyPos1);
				}
				else if (index == 1) {
					(*iter)->SetPosition(enemyPos2);
				}
				else if (index == 2) {
					(*iter)->SetPosition(enemyPos3);
				}
				else if (index == 3) {
					(*iter)->SetPosition(enemyPos4);
				}
				else {
					(*iter)->SetPosition(enemyPos5);
				}
			}
		}
		index++;
	}

	// collisions between player and pillars
	vector<CPillar*>::iterator iter2 = m_pillars.begin();
	for (iter2; iter2 != m_pillars.end(); iter2++) {
		if ((*iter2)->GetBBox().Collision(m_player.GetBBox())) {
			m_player.SetPosition(playerPos);
		}
	}

	index = 0;
	// collisions between enemies and pillars
	vector<CFanGrin*>::iterator iter3 = m_enemies.begin();
	for (iter3; iter3 != m_enemies.end(); iter3++) {
		vector<CPillar*>::iterator iter4 = m_pillars.begin();
		for (iter4; iter4 != m_pillars.end(); iter4++) {
			if ((*iter4)->GetBBox().Collision((*iter3)->GetBBox())) {
				if (index == 0) {
					(*iter3)->SetPosition(enemyPos1);
				}
				else if (index == 1) {
					(*iter3)->SetPosition(enemyPos2);
				}
				else if (index == 2) {
					(*iter3)->SetPosition(enemyPos3);
				}
				else if (index == 3) {
					(*iter3)->SetPosition(enemyPos4);
				}
				else {
					(*iter3)->SetPosition(enemyPos5);
				}
			}
			index++;
		}
	}

	// Stop player leaving arena
	CVector3f dis_to_arena_middle = CVector3f(-10.0f, 0.0f, -10.0f) - m_player.GetPosition();
	if (dis_to_arena_middle.Length() > 63) {
		m_player.SetPosition(playerPos);
	}

}

// Render the scene
void Game::Render()
{
	// GLuint errCode = glGetError(); // Can check for OpenGL errors with this -- should be zero if no error

	// Clear the buffers and load the identity matrix into the modelview matrix
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Calling look will put the viewing matrix onto the modelview matrix stack
	m_camera.Look();

	// Get the camera position and view vector
	CVector3f vPos = m_camera.GetPosition();
	CVector3f vView = m_camera.GetViewPoint();


	if ((m_introScreenOn == true) || (m_difficultySelectOn == true) || (m_controlScreenOn == true)) {	//If we are on an introscreen, we can render it here, else...
		m_introScreen.Activate();
		m_introScreen.Render(1, 1, 1);
		if ((m_difficultySelectOn == false) && (m_controlScreenOn == false)) {
			m_text1.Render("Press ENTER To Start", 300, 350);
			m_text2.Render("APOCAYLPTIC ARENA", 300, 250);
		}
		else if ((m_difficultySelectOn == true) && (m_controlScreenOn == false)) {
			m_text3.Render("Select Difficulty", 300, 200);
			m_text4.Render("EASY", 300, 300);
			m_text5.Render("NORMAL", 300, 400);
			m_text6.Render("HARD", 300, 500);
		}
		else {
			m_text7.Render("KeyBoard Settings", 300, 250);
			m_text8.Render("Move Forward: W", 300, 350);
			m_text9.Render("Turn Right: D", 300, 400);
			m_text10.Render("Turn Left: A", 300, 450);
			m_text11.Render("Attack: Spacebar", 300, 500);
		}
	}
	else {
		if (m_mainThemeAudioLoaded == false) {
			m_audio.LoadMusicStream("Resources\\Audio\\main-theme.wav");
			m_audio.PlayMusicStream();
			m_mainThemeAudioLoaded = true;
		}

		// Render skybox with no lighting
		glDisable(GL_LIGHTING);
			m_skybox.Render(vPos.x,  vPos.y,  vPos.z, 2500, 5000, 2500);  // Render the skybox with lighting off
			char str[128];
			memset(str, 0, 128);
			char str1[128];
			memset(str1, 0, 128);
			//char str2[128];
			//memset(str2, 0, 128);
			sprintf(str, "Player position = %f, %f, %f", m_player.GetPosition().x, m_player.GetPosition().y, m_player.GetPosition().z);
			sprintf(str, "Enemy Count = %i", m_enemyCount);
			sprintf(str1, "%i:%i", (int)m_timeTakenTimer.Elapsed() / 60, (int)m_timeTakenTimer.Elapsed() % 60);
			//sprintf(str2, "Player Health: %f", m_player.GetHealth());
			m_text1.Render(str , 350, 25);  // Draw some text -- useful for debugging and head's up displays
			m_text12.Render("Wave: 1", 50, 25);
			m_text13.Render(str1, 650, 25);
			//m_text2.Render(str2, 500, 100);
			if (m_enemyCount == 0) {
				m_text14.Render("Wave Completed", 350, 300);
			}
			if (m_gameOver == true) {
				m_text15.Render("GAME OVER", 350, 300);
			}
		glEnable(GL_LIGHTING);

		// Set materials and lighting for the scene
		m_lighting.SetLights(CVector3f(-10.0f, 1.0f, -10.0f), m_fogSphere.GetPosition(), m_fakeSphere.GetPosition());
		m_material.SetDefaultMaterial();

		// Render the terrain
		m_terrain.Render();
		
		// render Fan Grins
		m_fanGrin.Render(m_player.GetPosition());
		m_fanGrin2.Render(m_player.GetPosition());
		m_fanGrin3.Render(m_player.GetPosition());
		m_fanGrin4.Render(m_player.GetPosition());
		m_fanGrin5.Render(m_player.GetPosition());

		// render player
		m_player.Render();
		
		// render coliseum
		m_coliseum.Render();

		// render a pillars
		m_pillar.Render();
		m_pillar2.Render();
		m_pillar3.Render();
		m_pillar4.Render();

		// render strength boosting powerups in the form of a katana
		m_katana.Render();
		m_katana2.Render();
		m_katana3.Render();

		// Objects like ball etc.
		glDisable(GL_TEXTURE_2D);

		// render fog sphere
		m_fogSphere.Render();
		
		// render fake sphere
		m_fakeSphere.Render();


		glEnable(GL_TEXTURE_2D);
		
		glDisable(GL_LIGHTING);
		// Render alpha sphere
		glPushMatrix();
			glTranslatef(m_fakeSphere.GetPosition().x, 0, m_fakeSphere.GetPosition().z);
			m_alphaSphere.Render();
		glPopMatrix();
		// Render cross fade effect
		m_crossFade.Render(1, 0, 0);
		glEnable(GL_LIGHTING);
	}
	SwapBuffers(m_GameWindow.GetHdc());		
}

void Game::GameLoop()
{
	/*
	// This code implements a fixed timer
	m_dt = m_highResolutionTimer.Elapsed();

	if (m_dt > frame_duration) {
		m_highResolutionTimer.Start();

		Update();
		Render();
	}
	*/



	// This code implements a variable timer
	m_highResolutionTimer.Start();
	Update();
	Render();
	m_dt = m_highResolutionTimer.Elapsed();
			

}

WPARAM Game::Execute() 
{
	m_GameWindow.Init(m_hinstance);

	if(!m_GameWindow.GetHdc()) {
		return 1;
	}

	Initialise();

	m_highResolutionTimer.Start();

	double frame_duration = 1.0 / (double) 30.0;  // 30 FPS

	MSG msg;

	while(1) {													
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { 
			if(msg.message == WM_QUIT) {
				break;
			}

			TranslateMessage(&msg);	
			DispatchMessage(&msg);
		}else{
			GameLoop();
		} 
	}

	m_GameWindow.Deinit();

	return(msg.wParam);
}



LRESULT Game::ProcessEvents(HWND window,UINT message, WPARAM w_param, LPARAM l_param) 
{
	LRESULT result = 0;

	switch (message) {
	case WM_SIZE:
		if (!m_GameWindow.GetFullScreen()) {
			m_GameWindow.SizeOpenGLScreen(LOWORD(l_param), HIWORD(l_param));

			RECT dimensions;
			GetClientRect(window, &dimensions);
			m_GameWindow.SetDimensions(dimensions);
		}
		break;
 

	case WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(window, &ps);
		EndPaint(window, &ps);
		break;

	case WM_CHAR:
		switch (w_param) {
			if ((m_introScreenOn == false) && (m_difficultySelectOn == false) && (m_controlScreenOn == false)) {

				case 's': {
					if (m_player.IsJumping() == false) {
						m_player.Jump();
					}
					break;
				}

			}
		}
		break;

	case WM_KEYDOWN:
		switch (w_param) {

			case VK_ESCAPE:
				PostQuitMessage(0);
				break;

			case VK_RETURN:
				if (m_introScreenOn == true) {
					m_introScreenOn = false;
					m_difficultySelectOn = true;
				}
				else if (m_difficultySelectOn == true) {
					m_difficultySelectOn = false;
					// Need to set AI difficulty here - up strength for harder difficulties
					m_controlScreenOn = true;
					m_controlScreenTimer.Start();
				}
				else if (m_controlScreenOn == true) {
					m_controlScreenOn = false;
					m_introScreen.Deactivate();
					m_timeTakenTimer.Start();
				}
				break;

			case VK_SPACE:
				m_player.Attack();
				break;

			case VK_DOWN:
				if ((m_easyMode == true) && (m_normalMode == false)) {
					m_easyMode = false;
					m_normalMode = true;
					m_text4.ChangeTextColour(1, 1, 1);
					m_text5.ChangeTextColour(1, 0, 0);
					vector<CFanGrin*>::iterator iterx = m_enemies.begin();
					for (iterx; iterx != m_enemies.end(); iterx++) {
						(*iterx)->SetAttackStrength(10);
					}
				}
				else if ((m_easyMode == false) && (m_normalMode == true)) {
					m_normalMode = false;
					m_hardMode = true;
					m_text5.ChangeTextColour(1, 1, 1);
					m_text6.ChangeTextColour(1, 0, 0);
					vector<CFanGrin*>::iterator itery = m_enemies.begin();
					for (itery; itery != m_enemies.end(); itery++) {
						(*itery)->SetAttackStrength(15);
					}
				}
				break;

			case VK_UP:
				if ((m_hardMode == true) && (m_normalMode == false)) {
					m_hardMode = false;
					m_normalMode = true;
					m_text6.ChangeTextColour(1, 1, 1);
					m_text5.ChangeTextColour(1, 0, 0);
					vector<CFanGrin*>::iterator iterz = m_enemies.begin();
					for (iterz; iterz != m_enemies.end(); iterz++) {
						(*iterz)->SetAttackStrength(10);
					}
				}
				else if ((m_hardMode == false) && (m_normalMode == true)) {
					m_normalMode = false;
					m_easyMode = true;
					m_text5.ChangeTextColour(1, 1, 1);
					m_text4.ChangeTextColour(1, 0, 0);
					vector<CFanGrin*>::iterator iterxyz = m_enemies.begin();
					for (iterxyz; iterxyz != m_enemies.end(); iterxyz++) {
						(*iterxyz)->SetAttackStrength(5);
					}
				}
				break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		result = DefWindowProc(window, message, w_param, l_param);
		break;
	}

	return result;
}

Game& Game::GetInstance() 
{
	static Game instance;

	return instance;
}

void Game::SetHinstance(HINSTANCE hinstance) 
{
	m_hinstance = hinstance;
}


LRESULT CALLBACK WinProc(HWND window, UINT message, WPARAM w_param, LPARAM l_param)
{
	return Game::GetInstance().ProcessEvents(window, message, w_param, l_param);
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE, PSTR, int) 
{
	Game &game = Game::GetInstance();
	game.SetHinstance(hinstance);

	return game.Execute();
}

void Game::EnemyActions() {
	float nearestEnemy = 9999;
	int enemy = 0, index = 0;
	vector<CFanGrin*>::iterator iter = m_enemies.begin();
	for (iter; iter != m_enemies.end(); iter++) {
		CVector3f distance = m_player.GetPosition() - (*iter)->GetPosition();
		if (distance.Length() < nearestEnemy) {
			nearestEnemy = distance.Length();
			enemy = index;
		}
		index++;
	}
	m_enemies[enemy]->SetEngagePlayer();
	if ((nearestEnemy < 15 && m_fogSphere.Active() == true) || (nearestEnemy < 10 && m_fogSphere.Active() == false)) {
		m_enemies[enemy]->SetInRange();
		if (nearestEnemy < 1.5) {
			m_enemies[enemy]->SetMeleePlayer();
		}
		else {
			m_enemies[enemy]->SetMoveTowardsPlayer();
		}
	}
	else if ((nearestEnemy < 30 && m_fogSphere.Active() == true) || (nearestEnemy < 20 && m_fogSphere.Active() == false)) {
		m_enemies[enemy]->SetShootPlayer();
	}
}