#pragma once
#include "SCENES.Scene.h"
#include "..\GameCore.h"

class TestScene :
	public Scene
{
public:
	TestScene(void);
	~TestScene(void);
	
	void _Initialize();
	void _Uninitialize();
	void _Draw(float *zb, int *video, int w, int h);
	void _Update();

private:
	OBJECTS::CubeObject _cube;
	
};
