#pragma once

#include "Audio.h"
#include "Pickup.h"
#include "Texture.h"
#include "Player.h"
#include "SpecialFX.h"
#include "AlphaSphere.h"

class CFakeSphere : public CPickup {

public:
	CFakeSphere();
	~CFakeSphere();
	void Initialise(CVector3f position);
	void Update(CPlayer &player, CAudio &audio, CAlphaSphere &fog);
	void Render();
};