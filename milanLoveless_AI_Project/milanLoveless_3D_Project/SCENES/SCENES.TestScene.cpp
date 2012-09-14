#include "SCENES.TestScene.h"


TestScene::TestScene(void)
{	

}


TestScene::~TestScene(void)
{

}

void TestScene::_Initialize()
{
	this->_cube._Initialize();
}

void TestScene::_Uninitialize()
{
	this->_cube._Uninitialize();
}

void TestScene::_Draw(float *zb, int *video, int w, int h)
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// Put your drawing code here
	//for(int x = 0; x < w; x++) 
	//{
	//	for(int y = 1; y < h; y++) 
	//	{
	//		video[y*w+x] = 0xFF000000 + x*y + (w-x)*(h-y); //0xDEADBEEF;
	//	}
	//}
	this->_cube._Draw(zb, video, w, h);

	////////////////////////////////////////////////////////////////////////////////////////////////////

}


void TestScene::_Update()
{
	this->_cube._RunAI();
}