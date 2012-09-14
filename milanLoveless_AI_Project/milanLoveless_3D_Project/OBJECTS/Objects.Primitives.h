// Objects.Primitives.h
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

namespace OBJECTS
{

	float ClampIt(float ins);

	class _COLOR4F
	{
	public:
		float a, r, g, b;
	};

	class _VERTEX4F
	{
	public:
		float x, y, z, w;
		_VERTEX4F();
		_VERTEX4F(float a, float b, float c, float d);
		void _Set(float a, float b, float c, float d);
		_VERTEX4F operator+(const _VERTEX4F &vt);
		_VERTEX4F operator-(const _VERTEX4F &vt);
		_VERTEX4F operator*(const _VERTEX4F &vt);
		_VERTEX4F operator/(const _VERTEX4F &vt);
		_VERTEX4F operator*(float ft);
		_VERTEX4F operator/(float ft);
		float _Magnitude();
		void _Normalize();
		float _DotProduct(const _VERTEX4F &a, const _VERTEX4F &b);
		_VERTEX4F _CrossProduct(const _VERTEX4F &a, const _VERTEX4F &b);
	};
/////////////////////////////////////////////////////////////////////////
	class _TEXTURE2F
	{
	public:
		float tu, tv;
	};
/////////////////////////////////////////////////////////////////////////

	class _MATRIX16F
	{
	public:
		_MATRIX16F();
		_MATRIX16F(const _VERTEX4F &right, const _VERTEX4F &up, const _VERTEX4F &forward, const _VERTEX4F &position);
		void _SetToIdentity();
		void _Set(const _VERTEX4F &right, const _VERTEX4F &up, const _VERTEX4F &forward, const _VERTEX4F &position);
		
		_VERTEX4F _Multiply(const _VERTEX4F &v);

		static _MATRIX16F _Scale(float fSX, float fSY, float fSZ);
		static _MATRIX16F _Translate(const _VERTEX4F &vector);
		static _MATRIX16F _RotateX(float fDegrees);
		static _MATRIX16F _RotateY(float fDegrees);
		static _MATRIX16F _RotateZ(float fDegrees);

		float r0c0, r0c1, r0c2, r0c3;
		float r1c0, r1c1, r1c2, r1c3;
		float r2c0, r2c1, r2c2, r2c3;
		float r3c0, r3c1, r3c2, r3c3;
	};

/////////////////////////////////////////////////////////////////////////
	class _TRIANGLE3I
	{
	public:
		int a, b, c;
		int auv, buv, cuv;
		_VERTEX4F surface_normal;
	};
/////////////////////////////////////////////////////////////////////////
	class _MESH
	{
	public:
		//triangle index buffer
		int num_i;
		_TRIANGLE3I *ib;
		
		//vertex buffer
		int num_v;
		_VERTEX4F *vb;
		
		//vertex normal buffer
		int num_vn;
		_VERTEX4F *vn;

		//color channel
		int num_c;
		_COLOR4F *cb;

		//uv channel
		int num_uv;
		_TEXTURE2F *uv;

		///////////////////////////////////////////////
		//texture channels
		int num_textures;
		int *pTW, *pTH; //Width, Height of Texture Channels
		int **ppT; //Pixel data of Texture Channels
		///////////////////////////////////////////////

		int render_settings;
	};
////////////////////////////////////////////////////////////////////////////////////
	class _LIGHT
	{
	public:
		_VERTEX4F position; //The position of the light in worldspace
		_VERTEX4F direction; //The direction that the light is facing in worldspace
		float intensity; //The intensity of the light
		_COLOR4F color; //The color that the light emits
		int lighting_mode;
	};
////////////////////////////////////////////////////////////////////////////////////
	float vMin(float v0, float v1, float v2);
	float vMax(float v0, float v1, float v2);

	void _SHASH_ALG(float *zb, int *video, int w, int h, _VERTEX4F v0, _VERTEX4F v1, _VERTEX4F v2, int xmin, int xmax, int ymin, int ymax, _COLOR4F c0, _COLOR4F c1, _COLOR4F c2);

	void _DrawTriangle(float *zb, int *video, int w, int h, _VERTEX4F v0, _VERTEX4F v1, _VERTEX4F v2, _COLOR4F c0, _COLOR4F c1, _COLOR4F c2);
}

