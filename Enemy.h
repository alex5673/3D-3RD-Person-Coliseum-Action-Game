#pragma once

#include <windows.h>
#include "Vector3f.h"
#include "Camera.h"
#include "MD2Animation.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "include/gl.h"

class CEnemy
{
public:
	CEnemy() {}
	CEnemy(CVector3f position, float speed);
	~CEnemy() {}
	void virtual Update(float dt) {}
	void virtual Initialise() = 0;
	void virtual Render(CVector3f playerPos) = 0;
	double GetAttackStrength();
	double GetHealth() const;
	void SetHealth(double hp);
	void SetAttackStrength(int attack);
protected:
	CVector3f m_position; // Position of enemy
	float m_speed; // enemy speed
	CMD2Model m_mesh; // Mesh representing enemy
	double m_attackStrength;
	double m_health;
};