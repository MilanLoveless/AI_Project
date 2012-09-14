// SCENES.ZBMatrix.cpp
//////////////////////////////////////////////////////////////////////////////////////////

#include "SCENES.ZBMatrix.h"


ZBCalc::ZBCalc(void)
{	
	this->pImgInfoMatrix = NULL;
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
	this->_Initialize();
}


ZBCalc::~ZBCalc(void)
{
	ZBCalc::_Uninitialize();
}

void ZBCalc::_Initialize()
{
	this->pImgInfoSwitch = CORE::_LoadImage(15, "./RESOURCE/Switch.png", 256, 32);
	this->pImgInfoMatrix = CORE::_LoadImage(14, "./RESOURCE/Matrix.png", 800, 600);
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
	
	// Row One Coefficient
	this->pIIr1Ones = NULL;
	this->pIIr1Tenths = NULL;
	this->pIIr1Hunths = NULL;
	// Row Two Coefficient
	this->pIIr2Ones = NULL;
	this->pIIr2Tenths = NULL;
	this->pIIr2Hunths = NULL;
	// Row Three Coefficient
	this->pIIr3Ones = NULL;
	this->pIIr3Tenths = NULL;
	this->pIIr3Hunths = NULL;
	// Row Four Coefficient
	this->pIIr4Ones = NULL;
	this->pIIr4Tenths = NULL;
	this->pIIr4Hunths = NULL;
	// Row Five Coefficient
	this->pIIr5Ones = NULL;
	this->pIIr5Tenths = NULL;
	this->pIIr5Hunths = NULL;
	// Row Six Coefficient
	this->pIIr6Ones = NULL;
	this->pIIr6Tenths = NULL;
	this->pIIr6Hunths = NULL;
	// Row Seven Coefficient
	this->pIIr7Ones = NULL;
	this->pIIr7Tenths = NULL;
	this->pIIr7Hunths = NULL;
	// Row Eight Coefficient
	this->pIIr8Ones = NULL;
	this->pIIr8Tenths = NULL;
	this->pIIr8Hunths = NULL;
	// A Actual Value
	this->pIIAOnes = NULL;
	this->pIIATenths = NULL;
	this->pIIAHunths = NULL;
	// B Actual Value
	this->pIIBOnes = NULL;
	this->pIIBTenths = NULL;
	this->pIIBHunths = NULL;
	// C Actual Value
	this->pIICOnes = NULL;
	this->pIICTenths = NULL;
	this->pIICHunths = NULL;
	// Z Result
	this->pIIZOnes = NULL;
	this->pIIZTenths = NULL;
	this->pIIZHunths = NULL;

	this->fAActual = 0.50;
	this->fBActual = 0.50;
	this->fCActual = 0.50;
	this->fZActual = 0.0;
	this->fZCoefficients[0] = 0.0;
	this->fZCoefficients[1] = 0.33;
	this->fZCoefficients[2] = 0.33;
	this->fZCoefficients[3] = 0.66;
	this->fZCoefficients[4] = 0.33;
	this->fZCoefficients[5] = 0.66;
	this->fZCoefficients[6] = 0.66;
	this->fZCoefficients[7] = 1.00;
}

void ZBCalc::_Uninitialize()
{
	// Unload Images
	CORE::_UnloadImage(&pImgInfoSwitch);
	CORE::_UnloadImage(&pImgInfoMatrix);
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
	//Set image pointers to NULL
	this->pImgInfoSwitch = NULL;
	this->pImgInfoMatrix = NULL;
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
	// Row One Coefficient
	this->pIIr1Ones = NULL;
	this->pIIr1Tenths = NULL;
	this->pIIr1Hunths = NULL;
	// Row Two Coefficient
	this->pIIr2Ones = NULL;
	this->pIIr2Tenths = NULL;
	this->pIIr2Hunths = NULL;
	// Row Three Coefficient
	this->pIIr3Ones = NULL;
	this->pIIr3Tenths = NULL;
	this->pIIr3Hunths = NULL;
	// Row Four Coefficient
	this->pIIr4Ones = NULL;
	this->pIIr4Tenths = NULL;
	this->pIIr4Hunths = NULL;
	// Row Five Coefficient
	this->pIIr5Ones = NULL;
	this->pIIr5Tenths = NULL;
	this->pIIr5Hunths = NULL;
	// Row Six Coefficient
	this->pIIr6Ones = NULL;
	this->pIIr6Tenths = NULL;
	this->pIIr6Hunths = NULL;
	// Row Seven Coefficient
	this->pIIr7Ones = NULL;
	this->pIIr7Tenths = NULL;
	this->pIIr7Hunths = NULL;
	// Row Eight Coefficient
	this->pIIr8Ones = NULL;
	this->pIIr8Tenths = NULL;
	this->pIIr8Hunths = NULL;
	// A Actual Value
	this->pIIAOnes = NULL;
	this->pIIATenths = NULL;
	this->pIIAHunths = NULL;
	// B Actual Value
	this->pIIBOnes = NULL;
	this->pIIBTenths = NULL;
	this->pIIBHunths = NULL;
	// C Actual Value
	this->pIICOnes = NULL;
	this->pIICTenths = NULL;
	this->pIICHunths = NULL;
	// Z Result
	this->pIIZOnes = NULL;
	this->pIIZTenths = NULL;
	this->pIIZHunths = NULL;
}

void ZBCalc::_Cientos(const float &fCientos, CORE::IMAGEINFO *&pCientos)
{
	int iCientos = (int)(fCientos * 100.0) % 10;
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

void ZBCalc::_Tens(const float &fTens, CORE::IMAGEINFO *&pTens)
{
	int iTens = (int)(fTens * 10.0) % 10;
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

void ZBCalc::_Ones(const float &fOnes, CORE::IMAGEINFO *&pOnes)
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

void ZBCalc::_Update()
{
	//Calculate Z Result
	this->fZActual = (fZCoefficients[0] * ((1.0 - fAActual) * (1.0 - fBActual) * (1.0 - fCActual))) +
					 (fZCoefficients[1] * ((1.0 - fAActual) * (1.0 - fBActual) * (fCActual))) +
					 (fZCoefficients[2] * ((1.0 - fAActual) * (fBActual) * (1.0 - fCActual))) +
					 (fZCoefficients[3] * ((1.0 - fAActual) * (fBActual) * (fCActual))) +
					 (fZCoefficients[4] * ((fAActual) * (1.0 - fBActual) * (1.0 - fCActual))) +
					 (fZCoefficients[5] * ((fAActual) * (1.0 - fBActual) * (fCActual))) +
					 (fZCoefficients[6] * ((fAActual) * (fBActual) * (1.0 - fCActual))) +
					 (fZCoefficients[7] * ((fAActual) * (fBActual) * (fCActual)));
	if(this->fZActual > 1.0) this->fZActual = 1.0;

	// Update Digits for Row One
	ZBCalc::_Ones(this->fZCoefficients[0], this->pIIr1Ones);
	ZBCalc::_Tens(this->fZCoefficients[0], this->pIIr1Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[0], this->pIIr1Hunths);

	// Update Digits for Row Two
	ZBCalc::_Ones(this->fZCoefficients[1], this->pIIr2Ones);
	ZBCalc::_Tens(this->fZCoefficients[1], this->pIIr2Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[1], this->pIIr2Hunths);

	// Update Digits for Row Three
	ZBCalc::_Ones(this->fZCoefficients[2], this->pIIr3Ones);
	ZBCalc::_Tens(this->fZCoefficients[2], this->pIIr3Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[2], this->pIIr3Hunths);

	// Update Digits for Row Four
	ZBCalc::_Ones(this->fZCoefficients[3], this->pIIr4Ones);
	ZBCalc::_Tens(this->fZCoefficients[3], this->pIIr4Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[3], this->pIIr4Hunths);

	// Update Digits for Row Five
	ZBCalc::_Ones(this->fZCoefficients[4], this->pIIr5Ones);
	ZBCalc::_Tens(this->fZCoefficients[4], this->pIIr5Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[4], this->pIIr5Hunths);

	// Update Digits for Row Six
	ZBCalc::_Ones(this->fZCoefficients[5], this->pIIr6Ones);
	ZBCalc::_Tens(this->fZCoefficients[5], this->pIIr6Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[5], this->pIIr6Hunths);

	// Update Digits for Row Seven
	ZBCalc::_Ones(this->fZCoefficients[6], this->pIIr7Ones);
	ZBCalc::_Tens(this->fZCoefficients[6], this->pIIr7Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[6], this->pIIr7Hunths);

	// Update Digits for Row Eight
	ZBCalc::_Ones(this->fZCoefficients[7], this->pIIr8Ones);
	ZBCalc::_Tens(this->fZCoefficients[7], this->pIIr8Tenths);
	ZBCalc::_Cientos(this->fZCoefficients[7], this->pIIr8Hunths);

	// Update Digits for A
	ZBCalc::_Ones(this->fAActual, this->pIIAOnes);
	ZBCalc::_Tens(this->fAActual, this->pIIATenths);
	ZBCalc::_Cientos(this->fAActual, this->pIIAHunths);
	
	// Update Digits for B
	ZBCalc::_Ones(this->fBActual, this->pIIBOnes);
	ZBCalc::_Tens(this->fBActual, this->pIIBTenths);
	ZBCalc::_Cientos(this->fBActual, this->pIIBHunths);

	// Update Digits for C
	ZBCalc::_Ones(this->fCActual, this->pIICOnes);
	ZBCalc::_Tens(this->fCActual, this->pIICTenths);
	ZBCalc::_Cientos(this->fCActual, this->pIICHunths);

	// Update Digits for Z
	ZBCalc::_Ones(this->fZActual, this->pIIZOnes);
	ZBCalc::_Tens(this->fZActual, this->pIIZTenths);
	ZBCalc::_Cientos(this->fZActual, this->pIIZHunths);
}

void ZBCalc::_Draw(float *zb, int *video, int w, int h)
{
	// Adjust Row One Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 64 && Mouse::m_Y < 96 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[0] += 0.01;
		if(this->fZCoefficients[0] > 1.0) this->fZCoefficients[0] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 96 && Mouse::m_Y < 128 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[0] -= 0.01;
		if(this->fZCoefficients[0] < 0.0) this->fZCoefficients[0] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Two Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 128 && Mouse::m_Y < 160 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[1] += 0.01;
		if(this->fZCoefficients[1] > 1.0) this->fZCoefficients[1] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 160 && Mouse::m_Y < 192 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[1] -= 0.01;
		if(this->fZCoefficients[1] < 0.0) this->fZCoefficients[1] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Three Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 192 && Mouse::m_Y < 224 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[2] += 0.01;
		if(this->fZCoefficients[2] > 1.0) this->fZCoefficients[2] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 224 && Mouse::m_Y < 256 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[2] -= 0.01;
		if(this->fZCoefficients[2] < 0.0) this->fZCoefficients[2] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Four Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 256 && Mouse::m_Y < 288 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[3] += 0.01;
		if(this->fZCoefficients[3] > 1.0) this->fZCoefficients[3] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 288 && Mouse::m_Y < 320 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[3] -= 0.01;
		if(this->fZCoefficients[3] < 0.0) this->fZCoefficients[3] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Five Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 320 && Mouse::m_Y < 352 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[4] += 0.01;
		if(this->fZCoefficients[4] > 1.0) this->fZCoefficients[4] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 352 && Mouse::m_Y < 384 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[4] -= 0.01;
		if(this->fZCoefficients[4] < 0.0) this->fZCoefficients[4] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Six Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 384 && Mouse::m_Y < 416 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[5] += 0.01;
		if(this->fZCoefficients[5] > 1.0) this->fZCoefficients[5] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 416 && Mouse::m_Y < 448 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[5] -= 0.01;
		if(this->fZCoefficients[5] < 0.0) this->fZCoefficients[5] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Seven Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 448 && Mouse::m_Y < 480 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[6] += 0.01;
		if(this->fZCoefficients[6] > 1.0) this->fZCoefficients[6] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 480 && Mouse::m_Y < 512 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[6] -= 0.01;
		if(this->fZCoefficients[6] < 0.0) this->fZCoefficients[6] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Row Eight Z Coefficient
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 512 && Mouse::m_Y < 544 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[7] += 0.01;
		if(this->fZCoefficients[7] > 1.0) this->fZCoefficients[7] = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 304 && Mouse::m_X <= 336 && Mouse::m_Y >= 544 && Mouse::m_Y < 576 && Mouse::m_LeftButtonDown)
	{
		this->fZCoefficients[7] -= 0.01;
		if(this->fZCoefficients[7] < 0.0) this->fZCoefficients[7] = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Actual A Value
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 96 && Mouse::m_Y < 128 && Mouse::m_LeftButtonDown)
	{
		this->fAActual += 0.01;
		if(this->fAActual > 1.0) this->fAActual = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 128 && Mouse::m_Y < 160 && Mouse::m_LeftButtonDown)
	{
		this->fAActual -= 0.01;
		if(this->fAActual < 0.0) this->fAActual = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Actual B Value
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 224 && Mouse::m_Y < 256 && Mouse::m_LeftButtonDown)
	{
		this->fBActual += 0.01;
		if(this->fBActual > 1.0) this->fBActual = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 256 && Mouse::m_Y < 288 && Mouse::m_LeftButtonDown)
	{
		this->fBActual -= 0.01;
		if(this->fBActual < 0.0) this->fBActual = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Adjust Actual C Value
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 352 && Mouse::m_Y < 384 && Mouse::m_LeftButtonDown)
	{
		this->fCActual += 0.01;
		if(this->fCActual > 1.0) this->fCActual = 1.0;
		Mouse::m_LeftButtonDown = false;
	}
	if(Mouse::m_X >= 640 && Mouse::m_X <= 672 && Mouse::m_Y >= 384 && Mouse::m_Y < 416 && Mouse::m_LeftButtonDown)
	{
		this->fCActual -= 0.01;
		if(this->fCActual < 0.0) this->fCActual = 0.0;
		Mouse::m_LeftButtonDown = false;
	}

	// Calculate Z Result
	ZBCalc::_Update();

	// Draw the Background Image
	CORE::_DrawBitmap(video, w, h, 0, 0, pImgInfoMatrix->_video, 800, 600);

	// Draw Row One Z Coefficient
	if(this->pIIr1Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 80, pIIr1Ones->_video, 32, 32);
	if(this->pIIr1Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 80, pIIr1Tenths->_video, 32, 32);
	if(this->pIIr1Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 80, pIIr1Hunths->_video, 32, 32); 
	
	// Draw Row Two Z Coefficient
	if(this->pIIr2Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 144, pIIr2Ones->_video, 32, 32);
	if(this->pIIr2Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 144, pIIr2Tenths->_video, 32, 32);
	if(this->pIIr2Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 144, pIIr2Hunths->_video, 32, 32);

	// Draw Row Three Z Coefficient
	if(this->pIIr3Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 208, pIIr3Ones->_video, 32, 32);
	if(this->pIIr3Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 208, pIIr3Tenths->_video, 32, 32);
	if(this->pIIr3Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 208, pIIr3Hunths->_video, 32, 32);

	// Draw Row Four Z Coefficient
	if(this->pIIr4Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 272, pIIr4Ones->_video, 32, 32);
	if(this->pIIr4Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 272, pIIr4Tenths->_video, 32, 32);
	if(this->pIIr4Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 272, pIIr4Hunths->_video, 32, 32);

	// Draw Row Five Z Coefficient
	if(this->pIIr5Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 336, pIIr5Ones->_video, 32, 32);
	if(this->pIIr5Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 336, pIIr5Tenths->_video, 32, 32);
	if(this->pIIr5Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 336, pIIr5Hunths->_video, 32, 32);

	// Draw Row Six Z Coefficient
	if(this->pIIr6Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 400, pIIr6Ones->_video, 32, 32);
	if(this->pIIr6Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 400, pIIr6Tenths->_video, 32, 32);
	if(this->pIIr6Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 400, pIIr6Hunths->_video, 32, 32);

	// Draw Row Seven Z Coefficient
	if(this->pIIr7Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 464, pIIr7Ones->_video, 32, 32);
	if(this->pIIr7Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 464, pIIr7Tenths->_video, 32, 32);
	if(this->pIIr7Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 464, pIIr7Hunths->_video, 32, 32);

	// Draw Row Eight Z Coefficient
	if(this->pIIr8Ones != NULL) CORE::_DrawBitmap(video, w, h, 176, 528, pIIr8Ones->_video, 32, 32);
	if(this->pIIr8Tenths != NULL) CORE::_DrawBitmap(video, w, h, 240, 528, pIIr8Tenths->_video, 32, 32);
	if(this->pIIr8Hunths != NULL) CORE::_DrawBitmap(video, w, h, 272, 528, pIIr8Hunths->_video, 32, 32);

	// Draw Actual A Value
	if(this->pIIAOnes != NULL) CORE::_DrawBitmap(video, w, h, 512, 112, pIIAOnes->_video, 32, 32);
	if(this->pIIATenths != NULL) CORE::_DrawBitmap(video, w, h, 576, 112, pIIATenths->_video, 32, 32);
	if(this->pIIAHunths != NULL) CORE::_DrawBitmap(video, w, h, 608, 112, pIIAHunths->_video, 32, 32);

	// Draw Actual B Value
	if(this->pIIBOnes != NULL) CORE::_DrawBitmap(video, w, h, 512, 240, pIIBOnes->_video, 32, 32);
	if(this->pIIBTenths != NULL) CORE::_DrawBitmap(video, w, h, 576, 240, pIIBTenths->_video, 32, 32);
	if(this->pIIBHunths != NULL) CORE::_DrawBitmap(video, w, h, 608, 240, pIIBHunths->_video, 32, 32);

	// Draw Actual C Value
	if(this->pIICOnes != NULL) CORE::_DrawBitmap(video, w, h, 512, 368, pIICOnes->_video, 32, 32);
	if(this->pIICTenths != NULL) CORE::_DrawBitmap(video, w, h, 576, 368, pIICTenths->_video, 32, 32);
	if(this->pIICHunths != NULL) CORE::_DrawBitmap(video, w, h, 608, 368, pIICHunths->_video, 32, 32);

	// Draw Z Result
	if(this->pIIZOnes != NULL) CORE::_DrawBitmap(video, w, h, 512, 496, pIIZOnes->_video, 32, 32);
	if(this->pIIZTenths != NULL) CORE::_DrawBitmap(video, w, h, 576, 496, pIIZTenths->_video, 32, 32);
	if(this->pIIZHunths != NULL) CORE::_DrawBitmap(video, w, h, 608, 496, pIIZHunths->_video, 32, 32);

	// Draw Switch Button
	CORE::_DrawBitmap(video, w, h, 472, 16, this->pImgInfoSwitch->_video, 256, 32);

		// Switch States
	if(Mouse::m_X >= 472 && Mouse::m_X <= 728 && Mouse::m_Y >= 16 && Mouse::m_Y < 48 && Mouse::m_LeftButtonDown)
	{
		g_pCurrentScene = new ThermoScene();
		Mouse::m_LeftButtonDown = false;
		return;
	}
}
