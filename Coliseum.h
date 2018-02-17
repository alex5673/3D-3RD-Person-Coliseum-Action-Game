#pragma once

#include "OpenAssetImporterMesh.h"
#include "BoundingBox.h"

class CColiseum {
public:
	CColiseum();
	~CColiseum();
	void Intialise();
	void Render();
private:
	COpenAssetImporterMesh m_mesh;
};