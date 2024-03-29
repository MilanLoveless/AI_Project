// CORE.Hardware.Drawing.3D.h
/////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
//#ifndef __CORE_HARDWARE_DRAWING_3D_H_
//#define __CORE_HARDWARE_DRAWING_3D_H_
#include "CORE.Hardware.3D.h"

namespace CORE
{

	void _InitializeCOREDrawing3D(int left, int top, int right, int bottom);
	void _UninitializeCOREDrawing3D();

	void _FlipSurface(IDirect3DTexture9 *pSurface);

}
//#endif