#include "Enemy.h"

CEnemy::CEnemy(CVector3f position, float speed) {
	m_position = position;
	m_speed = speed;
	m_attackStrength = 0;
	m_health = 150;
}

double CEnemy::GetAttackStrength() {
	return m_attackStrength;
}

void CEnemy::SetAttackStrength(int attack) {
	m_attackStrength = attack;
}

double CEnemy::GetHealth() const {
	return m_health;
}

void CEnemy::SetHealth(double hp) {
	m_health = hp;
}
