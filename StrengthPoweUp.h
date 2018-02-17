#pragma once

#include "Audio.h"
#include "Pickup.h"
#include "Texture.h"
#include "Player.h"

class CStrengthPowerUP : public CPickup {
	UINT m_bladeMetalTextureID;
	UINT m_goldTextureID;
	UINT m_blackMetalTextureID;
	UINT m_katanaHandleTextureID;
public:
	CStrengthPowerUP();
	~CStrengthPowerUP();
	void Initialise(CVector3f position);
	void Update(CPlayer &player, CAudio &audio);
	void Render();
};