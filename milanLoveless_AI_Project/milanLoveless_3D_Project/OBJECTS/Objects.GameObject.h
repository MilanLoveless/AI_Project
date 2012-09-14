//Objects.GameObject.h
////////////////////////////////////////////////////////////////

#pragma once

namespace OBJECTS
{
	class GameObject
	{
	public:
		virtual void _Initialize() = 0;
		virtual void _Uninitialize() = 0;
		virtual void _Draw(float *zb, int *video, int nWidth, int nHeight) = 0;
		virtual void _RunAI() = 0;
	};
}