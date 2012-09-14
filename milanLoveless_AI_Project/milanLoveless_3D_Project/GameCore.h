// GameCore.h
//////////////////////////////////////////////////////////////

#pragma once
//#ifndef __GAMECORE_H_
//#define __GAMECORE_H_

#include <Windows.h>
#include <dxerr.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <MMSYSTEM.h>
#include <dsound.h>
#include <iostream>

#include <stdio.h>

using namespace std;

// Include all of your further H files here
#include "AICORE\\AICORE.h"

#include "CORE\\CORE.Hardware.3D.h"
#include "CORE\\CORE.Hardware.Drawing.3D.h"
#include "CORE\\CORE.Hardware.3D.Texture.h"

#include "INPUT\\CORE.Keyboard.h"
#include "INPUT\\CORE.Mouse.h"

#include "OLDCORE\\OLDCORE.Software.Drawing.2D.h"
#include "OLDCORE\\oldcore.Image.h"

#include "OBJECTS\\Objects.Primitives.h"
#include "OBJECTS\\Objects.CubeObject.h"
#include "OBJECTS\\Objects.GameObject.h"

#include "SCENES\\SCENES.TestScene.h"
#include "SCENES\\SCENES.Thermostat.h"
#include "SCENES\\SCENES.ZBMatrix.h"
#include "SCENES\\SCENES.AICritter.h"

// Declare any further functions or variables here
void _OnInitialize();
void _OnUninitialize();
void _OnFrame();
/** Remember to declare variables "extern" **/
extern CORE::IMAGEINFO *g_pBackBuffer;
extern Scene *g_pCurrentScene;
//#endif