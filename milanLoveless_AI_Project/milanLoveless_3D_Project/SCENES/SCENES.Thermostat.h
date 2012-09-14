// SCENES.Thermostat.h
////////////////////////////////////////////

#pragma once
#include "SCENES.Scene.h"
#include "SCENES.ZBMatrix.h"
#include "..\\CORE\\CORE.Hardware.3D.h"
#include "..\\CORE\\CORE.Hardware.3D.Texture.h"
#include "..\\OLDCORE\\OLDCORE.Image.h"
#include "..\GameCore.h"

extern Scene *g_pCurrentScene;


class ThermoScene :
	public Scene
{
public:
	ThermoScene(void);
	~ThermoScene(void);
	
	void _Initialize();
	void _Uninitialize();
	void _Draw(float *zb, int *video, int w, int h);
	void _Update();
	void _Ones(const float &fOnes, CORE::IMAGEINFO *&pOnes);
	void _Tens(const float &fTens, CORE::IMAGEINFO *&pTens);
	void _Cientos(const float &fCientos, CORE::IMAGEINFO *&pCientos);

//private:
	CORE::IMAGEINFO *pImgInfoSwitch;
	CORE::IMAGEINFO *pImgInfoUp;
	CORE::IMAGEINFO *pImgInfoDown;
	CORE::IMAGEINFO *pImgInfoZero;
	CORE::IMAGEINFO *pImgInfoOne;
	CORE::IMAGEINFO *pImgInfoTwo;
	CORE::IMAGEINFO *pImgInfoThree;
	CORE::IMAGEINFO *pImgInfoFour;
	CORE::IMAGEINFO *pImgInfoFive;
	CORE::IMAGEINFO *pImgInfoSix;
	CORE::IMAGEINFO *pImgInfoSeven;
	CORE::IMAGEINFO *pImgInfoEight;
	CORE::IMAGEINFO *pImgInfoNine;
	CORE::IMAGEINFO *pImgInfoCurOnes;
	CORE::IMAGEINFO *pImgInfoCurTens;
	CORE::IMAGEINFO *pImgInfoCurCientos;
	CORE::IMAGEINFO *pImgInfoMinOnes;
	CORE::IMAGEINFO *pImgInfoMinTens;
	CORE::IMAGEINFO *pImgInfoMinCientos;
	CORE::IMAGEINFO *pImgInfoMaxOnes;
	CORE::IMAGEINFO *pImgInfoMaxTens;
	CORE::IMAGEINFO *pImgInfoMaxCientos;
	float fMinimum;
	float fMaximum;
	float fCurrent;
	float fTarget;
};
