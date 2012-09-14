// GameCore.cpp
////////////////////////////////////////////////////////////////////////////////////////////

#include "GameCore.h"

CORE::TEXTUREINFO *g_pBackBuffer;
float *g_pZBuffer = NULL;
Scene *g_pCurrentScene;

void _OnInitialize() {
	g_pBackBuffer = CORE::_CreateTexture(0, 800, 600);
	g_pCurrentScene = new AICritter();
	//g_pCurrentScene->_Initialize();
	// Load or create any other resources for the application here
}

void _OnUninitialize() {

	CORE::_UnloadTexture(&g_pBackBuffer);
	delete(g_pCurrentScene);
	// Unload any other resources for the application here
}

void _OnFrame() {
	CORE::_ClearBackBuffer();
    CORE::_BeginDrawing();

	CORE::_LockTexture(g_pBackBuffer);

	int *video = g_pBackBuffer->_video;
	int w = g_pBackBuffer->_nActualWidth;
	int h = g_pBackBuffer->_nHeight;

	if(g_pZBuffer == NULL)
	{
		g_pZBuffer = CORE::CreateZBuffer(w,h);
	}

	CORE::ClearZBuffer(g_pZBuffer, w, h);

	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			video[y*w+x] = 0xffffffff;
		}
	}

	g_pCurrentScene->_Draw (g_pZBuffer, video, w, h);

	CORE::_UnlockTexture(g_pBackBuffer);

	CORE::_FlipSurface(g_pBackBuffer->_pSurface);

    CORE::_EndDrawing();
    CORE::_DisplayBackBuffer();

}