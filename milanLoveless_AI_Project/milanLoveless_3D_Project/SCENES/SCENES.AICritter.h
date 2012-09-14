// SCENES.Critter.h
////////////////////////////////////////////

#pragma once
#include "..\\AICore\\AICORE.h"
#include "SCENES.Scene.h"
#include "..\\GameCore.h"
#include <list>

extern Scene *g_pCurrentScene;


class AICritter : public Scene
{
public:
	AICritter(void);
	~AICritter(void);
	
	void _Initialize();
	void _Uninitialize();
	void _Draw(float *zb, int *video, int w, int h);
	void _Update();
private:
	list<auto_ptr<ZObject>> Foods;
	list<auto_ptr<ZObject>> Waters;
	list<auto_ptr<ZObject>> Critters;
};
