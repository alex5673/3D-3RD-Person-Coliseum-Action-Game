#pragma once

#include "Audio.h"
#include "Pickup.h"
#include "Texture.h"
#include "Player.h"
#include "SpecialFX.h"

class CFogActivationSphere : public CPickup {
	
public:
	CFogActivationSphere();
	~CFogActivationSphere();
	void Initialise(CVector3f position);
	void Update(CPlayer &player, CAudio &audio, CSpecialFX &fog);
	void Render();
};