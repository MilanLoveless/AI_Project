// SCENES.ZBMatrix.h
////////////////////////////////////////////

#pragma once

#include "SCENES.Scene.h"
#include "SCENES.Thermostat.h"
#include "..\\CORE\\CORE.Hardware.3D.h"
#include "..\\CORE\\CORE.Hardware.3D.Texture.h"
#include "..\\OLDCORE\\OLDCORE.Image.h"
#include "..\GameCore.h"

extern Scene *g_pCurrentScene;

class ZBCalc :
	public Scene
{
public:
	ZBCalc(void);
	~ZBCalc(void);
	
	void _Initialize();
	void _Uninitialize();
	void _Draw(float *zb, int *video, int w, int h);
	void _Update();
	void _Ones(const float &fOnes, CORE::IMAGEINFO *&pOnes);
	void _Tens(const float &fTens, CORE::IMAGEINFO *&pTens);
	void _Cientos(const float &fCientos, CORE::IMAGEINFO *&pCientos);

//private:
	CORE::IMAGEINFO *pImgInfoSwitch;
	CORE::IMAGEINFO *pImgInfoMatrix;
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
	CORE::IMAGEINFO *pIIr1Ones;
	CORE::IMAGEINFO *pIIr1Tenths;
	CORE::IMAGEINFO *pIIr1Hunths;
	CORE::IMAGEINFO *pIIr2Ones;
	CORE::IMAGEINFO *pIIr2Tenths;
	CORE::IMAGEINFO *pIIr2Hunths;
	CORE::IMAGEINFO *pIIr3Ones;
	CORE::IMAGEINFO *pIIr3Tenths;
	CORE::IMAGEINFO *pIIr3Hunths;
	CORE::IMAGEINFO *pIIr4Ones;
	CORE::IMAGEINFO *pIIr4Tenths;
	CORE::IMAGEINFO *pIIr4Hunths;
	CORE::IMAGEINFO *pIIr5Ones;
	CORE::IMAGEINFO *pIIr5Tenths;
	CORE::IMAGEINFO *pIIr5Hunths;
	CORE::IMAGEINFO *pIIr6Ones;
	CORE::IMAGEINFO *pIIr6Tenths;
	CORE::IMAGEINFO *pIIr6Hunths;
	CORE::IMAGEINFO *pIIr7Ones;
	CORE::IMAGEINFO *pIIr7Tenths;
	CORE::IMAGEINFO *pIIr7Hunths;
	CORE::IMAGEINFO *pIIr8Ones;
	CORE::IMAGEINFO *pIIr8Tenths;
	CORE::IMAGEINFO *pIIr8Hunths;
	CORE::IMAGEINFO *pIIAOnes;
	CORE::IMAGEINFO *pIIATenths;
	CORE::IMAGEINFO *pIIAHunths;
	CORE::IMAGEINFO *pIIBOnes;
	CORE::IMAGEINFO *pIIBTenths;
	CORE::IMAGEINFO *pIIBHunths;
	CORE::IMAGEINFO *pIICOnes;
	CORE::IMAGEINFO *pIICTenths;
	CORE::IMAGEINFO *pIICHunths;
	CORE::IMAGEINFO *pIIZOnes;
	CORE::IMAGEINFO *pIIZTenths;
	CORE::IMAGEINFO *pIIZHunths;
	float fAActual;
	float fBActual;
	float fCActual;
	float fZActual;
	float fZCoefficients[8];
};
