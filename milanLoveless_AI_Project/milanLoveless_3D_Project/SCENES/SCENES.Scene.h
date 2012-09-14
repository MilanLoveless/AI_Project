#pragma once
class Scene
{
public:
	virtual void _Draw(float *zb, int *video, int w, int h) = 0;
	virtual void _Update() = 0;
	virtual void _Initialize() = 0;
	virtual void _Uninitialize() = 0;
};

