#pragma once

#include "OpenAssetImporterMesh.h"
#include "BoundingBox.h"

class CPillar {
public:
	CPillar();
	CPillar(CVector3f pos);
	~CPillar();
	void Intialise();
	void Render();
	CBoundingBox GetBBox() const;
	CVector3f GetPosition() const;
	void SetPosition(CVector3f pos);
private:
	COpenAssetImporterMesh m_mesh;
	CBoundingBox m_bbox; // Bounding box
	CVector3f m_position;
};