#pragma once

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CrossFade.h"
#include "Pillar.h"

#define FANGRIN_STAND 0
#define FANGRIN_RUN 1
#define FANGRIN_ATTACK1 2
#define FANGRIN_ATTACK2 15

class CFanGrin : public CEnemy {
public:
	CFanGrin();
	CFanGrin(CVector3f position, float speed, const Camera &camera);
	CFanGrin(CVector3f position, float speed);

	void Update(float dt, CPlayer &player, CCrossFade &crossFade, vector<CPillar*> &pillars);
	void Initialise();
	void Render(CVector3f playerPos);
	void LongRangeAttack(CVector3f direction);
	CVector3f GetPosition();
	CBoundingBox GetBBox() const;
	void MeleeAttack(CPlayer &player, float dt, CCrossFade &crossFade);
	void MoveTowardsPlayer(CVector3f player, float dt);
	void SetPosition(CVector3f pos);
	void SetIdle();
	void SetEngagePlayer();
	void SetInRange();
	void SetShootPlayer();
	void SetMoveTowardsPlayer();
	void SetMeleePlayer();
private:
	Camera m_camera;
	CBullet m_bullet;
	CVector3f m_direction;
	CBoundingBox m_bbox; // Bounding box

	bool m_isFiring;
	float m_shootTimer;

	enum State {
		IDLE,
		ENGAGE_PLAYER,
	};

	enum InnerState {
		IN_RANGE,
		SHOOT_PLAYER,
	};

	enum InnerState2 {
		MOVE_TOWARDS_PLAYER,
		MELEE_PLAYER,
	};

	State state;
	InnerState innerState;
	InnerState2 innerState2;
};