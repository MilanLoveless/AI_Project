//Objects.CubeObject.h
/////////////////////////////////////////////////////////////

#pragma once

#include "..\GameCore.h"
#include "Objects.Primitives.h"
#include "Objects.GameObject.h"


namespace OBJECTS
{
	class CubeObject : public GameObject
	{
	public:
		void _Initialize();
		void _Uninitialize();
		void _Draw(float *zb, int *video, int nWidth, int nHeight);
		void _RunAI();
	private:
	_MESH _mesh;
	float rotation;
	};

}