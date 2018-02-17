#pragma once

#include <windows.h>
#include "Vector3f.h"
#include "OpenAssetimporterMesh.h"
#include "Player.h"
#include "Pillar.h"
#include "CrossFade.h"
#include ".\include\glut.h"

class CBullet
{
public:
	CBullet();
	~CBullet();
	void Fire(CVector3f player, CVector3f enemyPos);
	void Update(float dt, CPlayer& player, CCrossFade &crossFade, vector<CPillar*> &pillars);
	void Initialise();
	void Render();
	CVector3f GetPosition();
	CVector3f GetLastPosition();
	int GetBulletDamage();
	void SetBulletDamage(int damage);
public:

	// Linear physical quantities
	CVector3f m_position;
	CVector3f m_velocity;
	CVector3f m_acceleration;
	CVector3f m_instantaneousAcceleration;
	CVector3f m_lastPosition;
	CVector3f m_direction;

	// Other physical quantities
	float m_mass; // in kg
	float m_contactTime; // in seconds

	// Mesh
	COpenAssetImporterMesh m_mesh;

	// Methods to handle collisions with the ground
	bool CollisionDetection(CPlayer& player);
	void CollisionResponse(CPlayer& player, CCrossFade &crossFade);

	// is the bullet active
	bool m_active;
	float m_bulletActiveTimer;
	int m_bulletDamage;
};