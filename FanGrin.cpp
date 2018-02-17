#include "FanGrin.h"

CFanGrin::CFanGrin() : CEnemy(CVector3f(0,0,0), 0) {}

CFanGrin::CFanGrin(CVector3f position, float speed, const Camera &camera) : CEnemy(position, speed), m_camera(camera) {}

CFanGrin::CFanGrin(CVector3f position, float speed) : CEnemy(position, speed) {}

void CFanGrin::Initialise() {
	m_mesh.Load("./Resources/Meshes/FanGrin/TRIS.md2", "./Resources/Meshes/FanGrin/FANGRIN.bmp",
		"./Resources/Meshes/FanGrin/WEAPON.md2", "./Resources/Meshes/FanGrin/WEAPON.bmp");
	m_mesh.SetAnimation(FANGRIN_STAND);
	m_bullet.Initialise();
	state = IDLE;
	m_shootTimer = 0;
	m_isFiring = false;
	m_direction = CVector3f(0, 0, 1);
	m_bbox.SetBottom(m_position);
	m_bbox.SetSize(1.0f, 3.2f, 1.0f);
	m_attackStrength = 1;
}

void CFanGrin::Update(float dt, CPlayer &player, CCrossFade &crossFade, vector<CPillar*> &pillars) {

	if ((player.Attacked() == true) && (CVector3f((player.GetPosition() - GetPosition())).Length() < 2.0f)) {
 		SetHealth(GetHealth() - player.GetAttackStrength());
		player.SetAttacked(false);
	}

	m_bullet.Update(dt, player, crossFade, pillars);

	m_direction = player.GetPosition() - m_position;
	m_direction.Normalise();

	if (m_isFiring == true && m_shootTimer < 5) {
		state = IDLE;
		m_shootTimer += dt;
	}
	else
	{
		m_shootTimer = 0;
		m_isFiring = false;
	}

	switch (state) {
		case ENGAGE_PLAYER:
			switch (innerState) {
				case IN_RANGE:
					switch (innerState2) {
						case MOVE_TOWARDS_PLAYER:
							MoveTowardsPlayer(player.GetPosition(), dt);
							break;
						case MELEE_PLAYER:
							MeleeAttack(player, dt, crossFade);
							break;
					}
					break;
				case SHOOT_PLAYER:
					LongRangeAttack(player.GetPosition());
					break;
			}
		break;
	}
	state = IDLE;
	m_bbox.SetBottom(m_position);
}

void CFanGrin::Render(CVector3f playerPos) {
	if (m_health > 0) {
		// Work out angle of rotation for how the enemy should be rotated to face the right direction
		float theta = ((float)(atan2(m_direction.z, m_direction.x)) * (180.0f / M_PI));

		glPushMatrix();
		glTranslatef(m_position.x, 1.2f, m_position.z);
		glRotatef(-theta, 0, 1, 0);
		glScalef(0.05f, 0.05f, 0.05f);
		m_mesh.Render(true);
		glPopMatrix();

		// Render bullet if bullet has been fired
		m_bullet.Render();
		
		/*
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		m_bbox.Render(1, 0, 0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		*/
	}
}

void CFanGrin::LongRangeAttack(CVector3f direction) {
	if (m_health > 0) {
		m_bullet.Fire(direction, m_position);
		m_isFiring = true;
	}
}

void CFanGrin::MoveTowardsPlayer(CVector3f player, float dt) {
	CVector3f direction = player - m_position;
	m_position += (direction / 2) *(dt / 4);
}

void CFanGrin::MeleeAttack(CPlayer &player, float dt, CCrossFade &crossFade) {
	if (m_health > 0) {
		player.SetHealth(player.GetHealth() - (m_attackStrength * dt));
		crossFade.Activate();
	}
}

CVector3f CFanGrin::GetPosition() {
	return m_position;
}

CBoundingBox CFanGrin::GetBBox() const {
	return m_bbox;
}

void CFanGrin::SetIdle() {
	state = IDLE;
}

void CFanGrin::SetEngagePlayer() {
	state = ENGAGE_PLAYER;
}

void CFanGrin::SetInRange() {
	innerState = IN_RANGE;
}

void CFanGrin::SetShootPlayer() {
	innerState = SHOOT_PLAYER;
}

void CFanGrin::SetMoveTowardsPlayer() {
	innerState2 = MOVE_TOWARDS_PLAYER;
}

void CFanGrin::SetMeleePlayer() {
	 innerState2 = MELEE_PLAYER;
}

void CFanGrin::SetPosition(CVector3f pos) {
	m_position = pos;
}