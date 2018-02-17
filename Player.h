#pragma once

#include <windows.h>
#include "Vector3f.h"
#include "Camera.h"
#include "BoundingBox.h"
#include "MD2Animation.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "include/gl.h"


#define SEPIROTH_STAND 0
#define SEPIROTH_RUN 1
#define SEPIROTH_ATTACK 2
#define SEPIROTH_JUMP 6

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void Update(float dt, bool gameOver);
	void Initialise();
	void Render();
	void UpdateCamera(Camera &camera); // Update camera based on player
	void Turn(float angle); // Turn the player left / right
	void Attack();
	void Run();
	void Stop();
	void Jump();
	void PushBack();
	CVector3f GetPosition();
	CVector3f GetDirection();
	float GetSpeed();
	double GetHealth();
	CBoundingBox GetBBox() const;
	double GetAttackStrength() const;
	bool IsJumping();
	bool Attacked() const;
	void SetAttacked(bool attackd);
	void SetAttackStrength(double attack);
	void SetHealth(double hp);
	void SetPosition(CVector3f pos);
	void SetDirection(CVector3f direct);
	void SetSpeed(float sped);
	void SetJumping(bool jumping);
private:
	CVector3f m_position; // Position of player
	CVector3f m_direction; // Direction they are facing
	float m_speed; // Player speed
	CMD2Model m_mesh; // Mesh representing player
	// physics
	CVector3f m_velocity;
	CVector3f m_acceleration;
	CVector3f m_instantaneousAcceleration;
	CVector3f m_lastPosition;
	float m_mass; // in kg
	float m_contactTime; // in seconds
	float m_attackTimer;
	bool m_attacking;
	bool m_jumping;
	double m_health;
	double m_attackStrength;
	CBoundingBox m_bbox; // Bounding box
	bool m_attacked;
	float m_pushBackTimer;
	bool m_pushedBack;
};

