#include "Bullet.h"
#include <iostream>

CBullet::CBullet()
{
	// Initialise static physical quantities
	m_mass = 0.0042f; // in kg
	m_contactTime = 0.05f; // in seconds
	m_active = false;
	m_bulletActiveTimer = 0.0f;
	m_bulletDamage = 1;
	m_direction = CVector3f(0, 0, 1);
}

CBullet::~CBullet()
{}

void CBullet::Initialise()
{
	m_mesh.Load("./Resources/Meshes/Bullet.obj");
}


bool CBullet::CollisionDetection(CPlayer& player)
{
	// Check for collision with the player
	CVector3f distance = player.GetPosition() - m_position;
	if (distance.Length() < 0.5) {
		return true;
	}
	else {
		return false;
	}
}

void CBullet::CollisionResponse(CPlayer& player, CCrossFade &crossFade)
{
	// Damage player
	player.SetHealth(player.GetHealth() - m_bulletDamage);
	crossFade.Activate();
	m_active = false;
}


void CBullet::Update(float dt, CPlayer& player, CCrossFade &crossFade, vector<CPillar*> &pillars)
{

	if (m_bulletActiveTimer > 120) {
		m_active = false;
		m_bulletActiveTimer = 0.0f;
	}

	if (m_active == true) {
		m_bulletActiveTimer += dt;
	}

	// Update physical quanitities
	m_lastPosition = m_position;
	m_position += m_velocity * dt;
	
	// need to update position and velocity based on accerleration
	m_velocity += (m_acceleration + m_instantaneousAcceleration) * dt;

	// Turn off instantaneous forces if contact time is surpassed
	if (m_instantaneousAcceleration.Length() > 0 && m_contactTime > 0.05) {
		m_instantaneousAcceleration = CVector3f(0, 0, 0);
		m_contactTime = 0;
	}
	m_contactTime += dt;

	
	// Check for collision detection
	if (CollisionDetection(player) && (m_active == true)) {
		CollisionResponse(player, crossFade);
	}
	
	vector<CPillar*>::iterator iter123 = pillars.begin();
	for (iter123; iter123 != pillars.end(); iter123++) {
		CVector3f dis_to_pillar = CVector3f((*iter123)->GetPosition().x, 1.2f, (*iter123)->GetPosition().z) - m_position;
		if (dis_to_pillar.Length() < 2) {
			m_active = false;
		}
	}
}

void CBullet::Fire(CVector3f player, CVector3f enemyPos)
{
	m_direction = player - enemyPos;
    m_direction.Normalise();	// Normalised direction of bullet.  We'll launch the bullet in this direction


	// Initialise all physical variables
	m_position = CVector3f(0.0f, 0.0f, 0.0f);
	m_velocity = CVector3f(0.0f, 0.0f, 0.0f);
	m_acceleration = CVector3f(0.0f, 0.0f, 0.0f);
	m_instantaneousAcceleration = CVector3f(0.0f, 0.0f, 0.0f);
	m_contactTime = 0.0f;

	// Set the bullet to the current enemy position
	m_position = enemyPos;
	//m_velocity = 25.0f * direction;

	CVector3f force = m_direction * 2;
	m_instantaneousAcceleration = force / m_mass;

	m_active = true;
}

void CBullet::Render()
{
	if (m_active == true) {
		// Work out angle of rotation for how the bullet should be rotated to face the right direction
		float theta = ((float)(atan2(m_direction.z, m_direction.x)) * (180.0f / M_PI)) + 90;

		glPushMatrix();
			glTranslatef(m_position.x, m_position.y + 0.5, m_position.z);
			glRotatef(-theta, 0, 1, 0);
			glScalef(0.2, 0.2, 0.2);
			m_mesh.Render();
		glPopMatrix();
		
		// testing purposes
		/*
		glColor3f(1, 0, 0);
		glPushMatrix();
			glTranslatef(m_position.x, m_position.y, m_position.z);
			glutSolidSphere(1, 10, 10);
		glPopMatrix();
		*/
	}
}

CVector3f CBullet::GetPosition()
{
	return m_position;
}

CVector3f CBullet::GetLastPosition()
{
	return m_lastPosition;
}

int CBullet::GetBulletDamage() {
	return m_bulletDamage;
}

void CBullet::SetBulletDamage(int damage) {
	m_bulletDamage = damage;
}