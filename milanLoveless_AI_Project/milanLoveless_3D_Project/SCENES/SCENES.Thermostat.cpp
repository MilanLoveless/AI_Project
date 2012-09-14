#include "scenes.Thermostat.h"


ThermoScene::ThermoScene(void)
{	
	this->pImgInfoUp = NULL;
	this->pImgInfoDown = NULL;
	this->pImgInfoZero = NULL;
	this->pImgInfoOne = NULL;
	this->pImgInfoTwo = NULL;
	this->pImgInfoThree = NULL;
	this->pImgInfoFour = NULL;
	this->pImgInfoFive = NULL;
	this->pImgInfoSix = NULL;
	this->pImgInfoSeven = NULL;
	this->pImgInfoEight = NULL;
	this->pImgInfoNine = NULL;
	this->pImgInfoCurOnes = NULL;
	this->pImgInfoCurTens = NULL;
	this->pImgInfoCurCientos = NULL;
	this->pImgInfoMinOnes = NULL;
	this->pImgInfoMinTens = NULL;
	this->pImgInfoMinCientos = NULL;
	this->pImgInfoMaxOnes = NULL;
	this->pImgInfoMaxTens = NULL;
	this->pImgInfoMaxCientos = NULL;
	this->_Initialize();
}


ThermoScene::~ThermoScene(void)
{
	ThermoScene::_Uninitialize();
}

void ThermoScene::_Initialize()
{
	this->pImgInfoSwitch = CORE::_LoadImage(15, "./RESOURCE/Switch.png", 256, 32);
	this->pImgInfoUp = CORE::_LoadImage(12, "./RESOURCE/Up.png", 32, 32);
	this->pImgInfoDown = CORE::_LoadImage(13, "./RESOURCE/Down.png", 32, 32);
	this->pImgInfoZero = CORE::_LoadImage(11, "./RESOURCE/Zero.png", 32, 32);
	this->pImgInfoOne = CORE::_LoadImage(2, "./RESOURCE/One.png", 32, 32);
	this->pImgInfoTwo = CORE::_LoadImage(3, "./RESOURCE/Two.png", 32, 32);
	this->pImgInfoThree = CORE::_LoadImage(4, "./RESOURCE/Three.png", 32, 32);
	this->pImgInfoFour = CORE::_LoadImage(5, "./RESOURCE/Four.png", 32, 32);
	this->pImgInfoFive = CORE::_LoadImage(6, "./RESOURCE/Five.png", 32, 32);
	this->pImgInfoSix = CORE::_LoadImage(7, "./RESOURCE/Six.png", 32, 32);
	this->pImgInfoSeven = CORE::_LoadImage(8, "./RESOURCE/Seven.png", 32, 32);
	this->pImgInfoEight = CORE::_LoadImage(9, "./RESOURCE/Eight.png", 32, 32);
	this->pImgInfoNine = CORE::_LoadImage(10, "./RESOURCE/Nine.png", 32, 32);
	
	this->pImgInfoCurOnes = NULL;
	this->pImgInfoCurTens = NULL;
	this->pImgInfoCurCientos = NULL;
	this->pImgInfoMinOnes = NULL;
	this->pImgInfoMinTens = NULL;
	this->pImgInfoMinCientos = NULL;
	this->pImgInfoMaxOnes = NULL;
	this->pImgInfoMaxTens = NULL;
	this->pImgInfoMaxCientos = NULL;
	this->fMinimum = 32.0;
	this->fMaximum = 100.0;
	this->fCurrent = 32.0;
	this->fTarget = (fMinimum + fMaximum) / 2.0;
}

void ThermoScene::_Uninitialize()
{
	CORE::_UnloadImage(&pImgInfoSwitch);
	CORE::_UnloadImage(&pImgInfoUp);
	CORE::_UnloadImage(&pImgInfoDown);
	CORE::_UnloadImage(&pImgInfoZero);
	CORE::_UnloadImage(&pImgInfoOne);
	CORE::_UnloadImage(&pImgInfoTwo);
	CORE::_UnloadImage(&pImgInfoThree);
	CORE::_UnloadImage(&pImgInfoFour);
	CORE::_UnloadImage(&pImgInfoFive);
	CORE::_UnloadImage(&pImgInfoSix);
	CORE::_UnloadImage(&pImgInfoSeven);
	CORE::_UnloadImage(&pImgInfoEight);
	CORE::_UnloadImage(&pImgInfoNine);
	this->pImgInfoSwitch = NULL;
	this->pImgInfoZero = NULL;
	this->pImgInfoOne = NULL;
	this->pImgInfoTwo = NULL;
	this->pImgInfoThree = NULL;
	this->pImgInfoFour = NULL;
	this->pImgInfoFive = NULL;
	this->pImgInfoSix = NULL;
	this->pImgInfoSeven = NULL;
	this->pImgInfoEight = NULL;
	this->pImgInfoNine = NULL;
	this->pImgInfoCurOnes = NULL;
	this->pImgInfoCurTens = NULL;
	this->pImgInfoCurCientos = NULL;
	this->pImgInfoMinOnes = NULL;
	this->pImgInfoMinTens = NULL;
	this->pImgInfoMinCientos = NULL;
	this->pImgInfoMaxOnes = NULL;
	this->pImgInfoMaxTens = NULL;
	this->pImgInfoMaxCientos = NULL;
}

void ThermoScene::_Cientos(const float &fCientos, CORE::IMAGEINFO *&pCientos)
{
	int iCientos = ((int)fCientos / 100) % 10;
	if(iCientos == 0) pCientos = this->pImgInfoZero;
	else if(iCientos == 1) pCientos = this->pImgInfoOne;
	else if(iCientos == 2) pCientos = this->pImgInfoTwo;
	else if(iCientos == 3) pCientos = this->pImgInfoThree;
	else if(iCientos == 4) pCientos = this->pImgInfoFour;
	else if(iCientos == 5) pCientos = this->pImgInfoFive;
	else if(iCientos == 6) pCientos = this->pImgInfoSix;
	else if(iCientos == 7) pCientos = this->pImgInfoSeven;
	else if(iCientos == 8) pCientos = this->pImgInfoEight;
	else if(iCientos == 9) pCientos = this->pImgInfoNine;
	else pCientos = NULL;
}

void ThermoScene::_Tens(const float &fTens, CORE::IMAGEINFO *&pTens)
{
	int iTens = ((int)fTens / 10) % 10;
	if(iTens == 0) pTens = this->pImgInfoZero;
	else if(iTens == 1) pTens = this->pImgInfoOne;
	else if(iTens == 2) pTens = this->pImgInfoTwo;
	else if(iTens == 3) pTens = this->pImgInfoThree;
	else if(iTens == 4) pTens = this->pImgInfoFour;
	else if(iTens == 5) pTens = this->pImgInfoFive;
	else if(iTens == 6) pTens = this->pImgInfoSix;
	else if(iTens == 7) pTens = this->pImgInfoSeven;
	else if(iTens == 8) pTens = this->pImgInfoEight;
	else if(iTens == 9) pTens = this->pImgInfoNine;
	else pTens = NULL;
}

void ThermoScene::_Ones(const float &fOnes, CORE::IMAGEINFO *&pOnes)
{
	int iOnes = (int)fOnes % 10;
	if(iOnes == 0) pOnes = this->pImgInfoZero;
	else if(iOnes == 1) pOnes = this->pImgInfoOne;
	else if(iOnes == 2) pOnes = this->pImgInfoTwo;
	else if(iOnes == 3) pOnes = this->pImgInfoThree;
	else if(iOnes == 4) pOnes = this->pImgInfoFour;
	else if(iOnes == 5) pOnes = this->pImgInfoFive;
	else if(iOnes == 6) pOnes = this->pImgInfoSix;
	else if(iOnes == 7) pOnes = this->pImgInfoSeven;
	else if(iOnes == 8) pOnes = this->pImgInfoEight;
	else if(iOnes == 9) pOnes = this->pImgInfoNine;
	else pOnes = NULL;
}

void ThermoScene::_Update()
{
	// Update Target Temperature
	this->fTarget = (this->fMinimum + this->fMaximum) / 2.0;

	// Is it hot in here?
	float zHot = 1.0 - (fMaximum - fCurrent)/(fMaximum - fTarget);
	if(zHot > 0.01) this->fCurrent -= (zHot * 1.0);
	
	// Is it cold in here?
	float zCold = 1.0 - (fMinimum - fCurrent)/(fMinimum - fTarget);
	if(zCold > 0.01) this->fCurrent += (zCold * 1.0);

	// Update Digits for Current
	ThermoScene::_Ones(this->fCurrent, this->pImgInfoCurOnes);
	ThermoScene::_Tens(this->fCurrent, this->pImgInfoCurTens);
	ThermoScene::_Cientos(this->fCurrent, this->pImgInfoCurCientos);
	
	// Update Digits for Minimum
	ThermoScene::_Ones(this->fMinimum, this->pImgInfoMinOnes);
	ThermoScene::_Tens(this->fMinimum, this->pImgInfoMinTens);
	ThermoScene::_Cientos(this->fMinimum, this->pImgInfoMinCientos);

	// Update Digits for Maximum
	ThermoScene::_Ones(this->fMaximum, this->pImgInfoMaxOnes);
	ThermoScene::_Tens(this->fMaximum, this->pImgInfoMaxTens);
	ThermoScene::_Cientos(this->fMaximum, this->pImgInfoMaxCientos);
}

void ThermoScene::_Draw(float *zb, int *video, int w, int h)
{
	// Adjust Minimum Temperature
	if(Mouse::m_X >= 32 && Mouse::m_X <= 64 && Mouse::m_Y >= 284 && Mouse::m_Y < 316 && Mouse::m_LeftButtonDown)
	{
		this->fMinimum += 1.0;
		if(fMinimum > fMaximum - 1.0) this->fMinimum = this->fMaximum - 1.0;
		//Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 32 && Mouse::m_X <= 64 && Mouse::m_Y >= 316 && Mouse::m_Y < 348 && Mouse::m_LeftButtonDown)
	{
		this->fMinimum -= 1.0;
		if(fMinimum < 0.0) this->fMinimum = 0.0;
		//Mouse::m_LeftButtonDown = false;
	}
	// Adjust Maximum Temperature
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 284 && Mouse::m_Y < 316 && Mouse::m_LeftButtonDown)
	{
		this->fMaximum += 1.0;
		if(fMaximum > 999.0) this->fMaximum = 999.0;
		//Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 316 && Mouse::m_Y < 348 && Mouse::m_LeftButtonDown)
	{
		this->fMaximum -= 1.0;
		if(fMaximum < fMinimum + 1.0) this->fMaximum = this->fMinimum + 1.0;
		//Mouse::m_LeftButtonDown = false;
	}

	//Update image pointers and variables
	ThermoScene::_Update();

	//Draw Minimum Temperature
	CORE::_DrawBitmap(video, w, h, 32, (h/2)-16, pImgInfoUp->_video, 32, 32);
	CORE::_DrawBitmap(video, w, h, 32, (h/2)+16, pImgInfoDown->_video, 32, 32);
	if(this->pImgInfoMinOnes != NULL) CORE::_DrawBitmap(video, w, h, 64, h/2, pImgInfoMinCientos->_video, 32, 32);
	if(this->pImgInfoMinTens != NULL) CORE::_DrawBitmap(video, w, h, 96, h/2, pImgInfoMinTens->_video, 32, 32);
	if(this->pImgInfoMinOnes != NULL) CORE::_DrawBitmap(video, w, h, 128, h/2, pImgInfoMinOnes->_video, 32, 32); 
	
	//Draw Maximum Temperature
	if(this->pImgInfoMaxOnes != NULL) CORE::_DrawBitmap(video, w, h, w-64, h/2, pImgInfoMaxOnes->_video, 32, 32);
	if(this->pImgInfoMaxTens != NULL) CORE::_DrawBitmap(video, w, h, w-96, h/2, pImgInfoMaxTens->_video, 32, 32);
	if(this->pImgInfoMaxCientos != NULL) CORE::_DrawBitmap(video, w, h, w-128, h/2, pImgInfoMaxCientos->_video, 32, 32);
	CORE::_DrawBitmap(video, w, h, w-160, (h/2)-16, pImgInfoUp->_video, 32, 32);
	CORE::_DrawBitmap(video, w, h, w-160, (h/2)+16, pImgInfoDown->_video, 32, 32);

	//Draw Current Temperature
	if(this->pImgInfoCurOnes != NULL) CORE::_DrawBitmap(video, w, h, (w/2)+16, h/2, pImgInfoCurOnes->_video, 32, 32);
	if(this->pImgInfoCurTens != NULL) CORE::_DrawBitmap(video, w, h, (w/2)-16, h/2, pImgInfoCurTens->_video, 32, 32);
	if(this->pImgInfoCurCientos != NULL) CORE::_DrawBitmap(video, w, h, (w/2)-48, h/2, pImgInfoCurCientos->_video, 32, 32);

	// Draw Switch Button
	CORE::_DrawBitmap(video, w, h, 472, 16, this->pImgInfoSwitch->_video, 256, 32);

	// Switch States
	if(Mouse::m_X >= 472 && Mouse::m_X <= 728 && Mouse::m_Y >= 16 && Mouse::m_Y < 48 && Mouse::m_LeftButtonDown)
	{
		g_pCurrentScene = new ZBCalc();
		Mouse::m_LeftButtonDown = false;
		return;
	}
}
