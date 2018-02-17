#include "Player.h"

CPlayer::CPlayer() {
	m_position = CVector3f(-20.0f, 0.0f, 20.0f);
	m_direction = CVector3f(0.0f, 0.0f, -1.0f);
	m_speed = 10.0f;
	m_contactTime = 0.05f;
	m_mass = 83.6f;
	m_velocity = CVector3f(0.0f, 0.0f, 0.0f);
	m_acceleration = CVector3f(0.0f, -9.8f, 0.0f);
	m_instantaneousAcceleration = CVector3f(0.0f, 0.0f, 0.0f);
	m_attackTimer = 0.0f;
	m_attacking = false;
	m_jumping = false;
	m_health = 150;
	m_attackStrength = 50.0;
	m_attacked = false;
	m_pushedBack = false;
	m_pushBackTimer = 0;
}

CPlayer::~CPlayer() {

}

void CPlayer::Initialise()
{
	m_mesh.Load("./Resources/Meshes/Sepiroth/tris.md2", "./Resources/Meshes/Sepiroth/normal.bmp",
		"./Resources/Meshes/Sepiroth/weapon.md2", "./Resources/Meshes/Sepiroth/weapon.bmp");
	m_mesh.SetAnimation(SEPIROTH_STAND);
	m_bbox.SetBottom(m_position);
	m_bbox.SetSize(1.0f, 2.6f, 1.0f);
}

void CPlayer::Update(float dt, bool gameOver)
{

	m_attacked = false;

	//m_position += m_direction * m_speed * dt;
	m_lastPosition = m_position;
	m_position += m_velocity * dt;

	if (m_pushedBack == true && m_pushBackTimer < 1) {
		m_pushBackTimer += dt;
	}
	else if (m_pushedBack == true && m_pushBackTimer >= 1) {
		m_pushBackTimer = 0;
		m_pushedBack = false;
	}
    
	if ((m_position.y == 0) && (m_attacking == false) && (m_jumping == false) && (m_pushedBack == false) && (gameOver == false)) {

		if (GetKeyState('A') & 0x80) {
			Turn(60.0f * dt);
		}
		else if (GetKeyState('D') & 0x80) {
			Turn(-60.0f * dt);
		}
		else if (GetKeyState('W') & 0x80) {
			Run();
		}
		else {
			Stop();
			m_mesh.SetAnimation(SEPIROTH_STAND);
		}

	}
	else if ((m_position.y == 0) && (m_jumping == true)) {
		m_jumping = false;
	}

	if (m_position.y < -0.1) {
		m_position.y = 0;
		m_velocity.y = 0;
		m_acceleration.y = 0;
	}
	
	m_velocity += (m_acceleration + m_instantaneousAcceleration) * dt;
	
	// Turn off instantaneous forces if contact time is surpassed
	if (m_contactTime > 0.05) {
		m_instantaneousAcceleration = CVector3f(0, 0, 0);
		m_contactTime = 0;
	}
	m_contactTime += dt;
	

	
	if (m_mesh.GetAnimation() == SEPIROTH_ATTACK && m_mesh.IsLastFrameRendered()) {
		m_mesh.SetAnimation(SEPIROTH_STAND);
		m_attacking = false;
		m_attacked = true;
	}
	
	/*
	else if (m_mesh.GetAnimation() == SEPIROTH_RUN && m_mesh.IsLastFrameRendered()) {
		m_mesh.SetAnimation(SEPIROTH_STAND);
		m_speed = 0.0f;
	}
	*/
	else if (m_mesh.GetAnimation() == SEPIROTH_JUMP && m_mesh.IsLastFrameRendered()) {
		m_mesh.SetAnimation(SEPIROTH_STAND);
	}
	m_bbox.SetBottom(m_position);

	if (gameOver == true) {
		Stop();
	}
}


void CPlayer::Stop()
{

	m_velocity.x = 0;
	m_velocity.z = 0;
	m_acceleration.x = 0;
	m_acceleration.z = 0;
	m_instantaneousAcceleration.x = 0;
	m_instantaneousAcceleration.z = 0;



}

void CPlayer::Render()
{
	// Work out angle of rotation for how the player should be rotated to face the right direction
	float theta = ((float)(atan2(m_direction.z, m_direction.x)) * (180.0f / M_PI));

	glPushMatrix();
		glTranslatef(m_position.x, m_position.y + 1.2f, m_position.z);
		glRotatef(-theta, 0, 1, 0);
		glScalef(0.05f, 0.05f, 0.05f);
		m_mesh.Render(true);
	glPopMatrix();

	/*
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	m_bbox.Render(1, 0, 0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	*/
}

void CPlayer::Turn(float angle) {
	m_direction = m_direction.RotateAboutAxis(angle, CVector3f(0, 1, 0));
}

void CPlayer::Attack() {
	if (m_mesh.GetAnimation() != SEPIROTH_ATTACK) {
		m_mesh.SetAnimation(SEPIROTH_ATTACK);
	}
	//m_mesh.SetAnimation(SEPIROTH_ATTACK);
	//m_speed = 0.0f;
	m_attacking = true;
}

void CPlayer::Run() {
	if (m_mesh.GetAnimation() != SEPIROTH_RUN) {
		m_mesh.SetAnimation(SEPIROTH_RUN);
	}

	/*
	m_speed = 100.0f;
	CVector3f force = m_direction * m_speed;
	m_instantaneousAcceleration = force / m_mass;
	m_contactTime = 0.0f;
	*/
	m_velocity = m_direction * m_speed;

}

void CPlayer::Jump() {
	m_mesh.SetAnimation(SEPIROTH_JUMP);
	m_acceleration = CVector3f(0.0f, -9.8f, 0.0f);
	CVector3f force = CVector3f(0, 1, 0) * 8000;
	m_instantaneousAcceleration = force / m_mass;
	m_contactTime = 0.0f;
	m_jumping = true;
}

void CPlayer::PushBack() {
	CVector3f force = CVector3f(-m_direction.x, 0.0f, -m_direction.z) * m_speed;
	m_instantaneousAcceleration = force * 10;
	m_contactTime = 0.0f;
	m_pushedBack = true;
}

// Third-person view
void CPlayer::UpdateCamera(Camera &camera) {
	// Vector B
	CVector3f vectorB = CVector3f((m_direction.x * 10.0f), (m_direction.y * 10.0f), ((m_direction.z * 10.0f)));
	// Vector A
	CVector3f vectorA = CVector3f(0.0f, 4.0f, 0.0f);
	// Camera Position
	CVector3f cameraPos = CVector3f((m_position.x- vectorB.x), vectorA.y, (m_position.z -vectorB.z));
	// Vector C
	CVector3f vectorC = cameraPos + (CVector3f((vectorB.x * 2.0f), 0.0f, (vectorB.z * 2.0f)));
	// Set Camera view
	camera.Set(cameraPos, vectorC, CVector3f(0.0f, 1.0f, 0.0f), 5.0f);
}

bool CPlayer::Attacked() const {
	return m_attacked;
}

CBoundingBox CPlayer::GetBBox() const {
	return m_bbox;
}

CVector3f CPlayer::GetPosition() {
	return m_position;
}

CVector3f CPlayer::GetDirection() {
	return m_direction;
}

float CPlayer::GetSpeed() {
	return m_speed;
}

double CPlayer::GetHealth() {
	return m_health;
}

double CPlayer::GetAttackStrength() const {
	return m_attackStrength;
}

bool CPlayer::IsJumping() {
	return m_jumping;
}

void CPlayer::SetAttacked(bool attackd) {
	m_attacked = attackd;
}

void CPlayer::SetAttackStrength(double attack) {
	m_attackStrength = attack;
}

void CPlayer::SetHealth(double hp) {
	m_health = hp;
}

void CPlayer::SetPosition(CVector3f pos) {
	m_position = pos;
}

void CPlayer::SetDirection(CVector3f direct) {
	m_direction = direct;
}

void CPlayer::SetSpeed(float sped) {
	m_speed = sped;
}

void CPlayer::SetJumping(bool jumping) {
	m_jumping = jumping;
}