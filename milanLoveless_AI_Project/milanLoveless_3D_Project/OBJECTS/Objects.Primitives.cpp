//Objects.Primitives.cpp
////////////////////////////////////////////////////////////////////////////////////

#include "Objects.Primitives.h"
#include "..\GameCore.h"
#include <math.h>

namespace OBJECTS
{
	float ClampIt(float ins)
	{
		if(ins<0.0) ins = 0.0;
		if(ins>1.0) ins = 1.0;
		return ins;
	}


	void _VERTEX4F::_Set(float a, float b, float c, float d)
	{
		this->x=a;
		this->y=b;
		this->z=c;
		this->w=d;
	}
	_VERTEX4F::_VERTEX4F()
	{
		this->_Set(0.0, 0.0, 0.0, 1.0);
	}
	_VERTEX4F::_VERTEX4F(float a, float b, float c, float d)
	{
		this->_Set(a, b, c, d);
	}
	float _VERTEX4F::_Magnitude()
	{
		return sqrt(
			this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w
			);
	}
	void _VERTEX4F::_Normalize()
	{
		float m = _Magnitude();
		this->x /= m; this->y /= m;
		this->z /= m; this->w /= m;
	}


	_VERTEX4F _VERTEX4F::operator+(const _VERTEX4F &vt)
	{
		return _VERTEX4F(this->x + vt.x, this->y + vt.y, this->z + vt.z, this->w + vt.w);
	}
	_VERTEX4F _VERTEX4F::operator-(const _VERTEX4F &vt)
	{
		return _VERTEX4F(this->x - vt.x, this->y - vt.y, this->z - vt.z, this->w - vt.w);
	}
	_VERTEX4F _VERTEX4F::operator*(const _VERTEX4F &vt)
	{
		return _VERTEX4F(this->x * vt.x, this->y * vt.y, this->z * vt.z, this->w * vt.w);
	}
	_VERTEX4F _VERTEX4F::operator/(const _VERTEX4F &vt)
	{
		return _VERTEX4F(this->x / vt.x, this->y / vt.y, this->z / vt.z, this->w / vt.w);
	}
	_VERTEX4F _VERTEX4F::operator*(float Scalar)
	{
		return _VERTEX4F(this->x * Scalar, this->y * Scalar, this->z * Scalar, this->w * Scalar);
	}
	_VERTEX4F _VERTEX4F::operator/(float Scalar)
	{
		return _VERTEX4F(this->x / Scalar, this->y / Scalar, this->z / Scalar, this->w / Scalar);
	}

	float _VERTEX4F::_DotProduct(const _VERTEX4F &a, const _VERTEX4F &b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}
	_VERTEX4F _VERTEX4F::_CrossProduct(const _VERTEX4F &a, const _VERTEX4F &b)
	{
		return _VERTEX4F(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	_MATRIX16F::_MATRIX16F()
	{
		_SetToIdentity();
	}

	_MATRIX16F::_MATRIX16F(const _VERTEX4F &right, const _VERTEX4F &up, const _VERTEX4F &forward, const _VERTEX4F &position)
	{
		_MATRIX16F::_Set(right, up, forward, position);
	}

	void _MATRIX16F::_SetToIdentity()
	{
		r0c0 = 1.0; r0c1 = 0.0; r0c2 = 0.0; r0c3 = 0.0;
		r1c0 = 0.0; r1c1 = 1.0; r1c2 = 0.0; r1c3 = 0.0;
		r2c0 = 0.0; r2c1 = 0.0; r2c2 = 1.0; r2c3 = 0.0;
		r3c0 = 0.0; r3c1 = 0.0; r3c2 = 0.0; r3c3 = 1.0;
	}

	void _MATRIX16F::_Set(const _VERTEX4F &right, const _VERTEX4F &up, const _VERTEX4F &forward, const _VERTEX4F &position)
	{
		r0c0 = right.x; r0c1 = up.x; r0c2 = forward.x; r0c3 = position.x;
		r1c0 = right.y; r1c1 = up.y; r1c2 = forward.y; r1c3 = position.y;
		r2c0 = right.z; r2c1 = up.z; r2c2 = forward.z; r2c3 = position.z;
		r3c0 = right.w; r3c1 = up.w; r3c2 = forward.w; r3c3 = position.w;
	}

	_VERTEX4F _MATRIX16F::_Multiply(const _VERTEX4F &v)
	{
		return _VERTEX4F(
			r0c0*v.x + r0c1*v.y + r0c2*v.z + r0c3*v.w,
			r1c0*v.x + r1c1*v.y + r1c2*v.z + r1c3*v.w,
			r2c0*v.x + r2c1*v.y + r2c2*v.z + r2c3*v.w,
			r3c0*v.x + r3c1*v.y + r3c2*v.z + r3c3*v.w
		);
	}

	_MATRIX16F _MATRIX16F::_Scale(float fSX, float fSY, float fSZ)
	{
		return _MATRIX16F(
			_VERTEX4F(fSX, 0.0, 0.0, 0.0),
			_VERTEX4F(0.0, fSY, 0.0, 0.0),
			_VERTEX4F(0.0, 0.0, fSZ, 0.0),
			_VERTEX4F(0.0, 0.0, 0.0, 1.0)
		);
	}
	_MATRIX16F _MATRIX16F::_Translate(const _VERTEX4F &v)
	{
		return _MATRIX16F(
			_VERTEX4F(1.0, 0.0, 0.0, 0.0),
			_VERTEX4F(0.0, 1.0, 0.0, 0.0),
			_VERTEX4F(0.0, 0.0, 1.0, 0.0),
			_VERTEX4F(v.x, v.y, v.z, 1.0)
		);
	}
	_MATRIX16F _MATRIX16F::_RotateX(float fDegrees)
	{
		const float PI = 3.141592653;
		float r = fDegrees * PI / 180;
		return _MATRIX16F(
			_VERTEX4F(1.0,	0.0,	0.0,	0.0),
			_VERTEX4F(0.0,	cos(r),	sin(r),	0.0),
			_VERTEX4F(0.0, -sin(r), cos(r), 0.0),
			_VERTEX4F(0.0,	0.0,	0.0,	1.0)
		);
	}
	_MATRIX16F _MATRIX16F::_RotateY(float fDegrees)
	{
		const float PI = 3.141592653;
		float r = fDegrees * PI / 180;
		return _MATRIX16F(
			_VERTEX4F(cos(r),	0.0,	-sin(r),	0.0),
			_VERTEX4F(	0.0,	1.0,	0.0,		0.0),
			_VERTEX4F(sin(r),	0.0,	cos(r),		0.0),
			_VERTEX4F(	0.0,	0.0,	0.0,		1.0)
		);
	}
	_MATRIX16F _MATRIX16F::_RotateZ(float fDegrees)
	{
		const float PI = 3.141592653;
		float r = fDegrees * PI / 180;
		return _MATRIX16F(
			_VERTEX4F(	cos(r),	sin(r),	0.0,	0.0),
			_VERTEX4F( -sin(r),	cos(r),	0.0,	0.0),
			_VERTEX4F(	0.0,	0.0,	1.0,	0.0),
			_VERTEX4F(	0.0,	0.0,	0.0,	1.0)
		);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float vMax(float v0, float v1, float v2)
	{
		float maxi = v0;
		if(maxi < v1)
		{
			maxi = v1;
		}
		if(maxi < v2)
		{
			maxi = v2;
		}

		return maxi;
	}

	float vMin(float v0, float v1, float v2)
	{
		float mini = v0;
		if(mini > v1)
		{
			mini = v1;
		}
		if(mini > v2)
		{
			mini = v2;
		}
		return mini;
	}

	#define f12(xx, yy) ((v1.y - v2.y) * (xx) + (v2.x - v1.x) * (yy) + v1.x * v2.y - v2.x * v1.y)
	#define f20(xx, yy) ((v2.y - v0.y) * (xx) + (v0.x - v2.x) * (yy) + v2.x * v0.y - v0.x * v2.y)
	#define f01(xx, yy) ((v0.y - v1.y) * (xx) + (v1.x - v0.x) * (yy) + v0.x * v1.y - v1.x * v0.y)

	void _SHASH_ALG(float *zb, int *video, int w, int h, _VERTEX4F v0, _VERTEX4F v1, _VERTEX4F v2, int xmin, int xmax, int ymin, int ymax, _COLOR4F c0, _COLOR4F c1, _COLOR4F c2)
	{
		for(int y = ymin; y <= ymax; y++)
		{
			for(int x = xmin; x <= xmax; x++)
			{
				float alpha = f12(x, y)/f12(v0.x, v0.y);
				float beta = f20(x, y)/f20(v1.x, v1.y);
				float gamma = f01(x, y)/f01(v2.x, v2.y);
				if(alpha >= 0 && beta >= 0 && gamma >= 0)
				{
					if(zb != NULL)
					{
						float z = alpha*v0.z + beta*v1.z + gamma*v2.z;
						if(zb[y*w+x] < z) continue;
						zb[y*w+x] = z;
					}
					// Milan's iridescent shader ^_^ (per triangle version) a creative use of Rodrigues' Rotation Formula 
					///////////////////////////////////////////////////////////////////////
					_VERTEX4F v01 = v1 - v0;
					_VERTEX4F v02 = v2 - v0;
					_VERTEX4F snorm = v01._CrossProduct(v02, v01);
					snorm._Normalize(); //surface normal
					
					if(snorm._DotProduct(_VERTEX4F(0.0, 0.0, 1.0, 0.0), snorm) < 0.0) continue;

					_VERTEX4F k(1.0, 1.0, 1.0, 0.0); // the reference vector, we will be 'rotating' our base color around this point (1.0 r 1.0 g 1.0 b is white, the center of the color wheel of course!?)		
					k._Normalize();

					_VERTEX4F posi((float)x, (float) y, alpha*v0.z + beta*v1.z + gamma*v2.z, 1.0);
					_VERTEX4F camera1(w/2.0, h/2.0, -200.0, 0.0);
					_VERTEX4F cameraV = (posi - camera1);
					cameraV._Normalize();
					//_VERTEX4F light1(-5.0, -10.0, -2.5, 0.0);
					//light1._Normalize();

					float CDN = cameraV._DotProduct(cameraV, snorm);
					//float LDN = ClampIt(light1._DotProduct(light1, snorm));
		
					//CDN = abs(CDN);
					//float theta = sqrt(1.0 / CDN);
					float theta = CDN;
					_VERTEX4F v(0.1, 0.43, 0.9, 0.0); // a color masquerading as a vector!!? madness!

					// ready? ok, here it is!
					_VERTEX4F IRI = (v*cos(theta) + (k._CrossProduct(v, k))*sin(theta)) + (k*(k._DotProduct(k, v))) * (1 - cos(theta));

					//float redC = 255.0 * (c0.r * alpha + c1.r * beta + c2.r * gamma);
					//float greenC = 255.0 * (c0.g * alpha + c1.g * beta + c2.g * gamma);
					//float blueC = 255.0 * (c0.b * alpha + c1.b * beta + c2.g * gamma);
					//int color = CORE::_CreateColor(255, (int)redC, (int)greenC, (int)blueC);
					IRI.x = abs(IRI.x);
					IRI.y = abs(IRI.y);
					IRI.z = abs(IRI.z);					
					IRI.x = ClampIt(IRI.x) * 255.0;
					IRI.y = ClampIt(IRI.y) * 255.0;
					IRI.z = ClampIt(IRI.z) * 255.0;
					int color = CORE::_CreateColor(255, (int)IRI.x, (int)IRI.y, (int)IRI.z); 
					CORE::_PutPixel(video, w, h, x, y, color);
				}
			}
		}
	}

	void _DrawTriangle(float *zb, int *video, int w, int h, _VERTEX4F v0, _VERTEX4F v1, _VERTEX4F v2, _COLOR4F c0, _COLOR4F c1, _COLOR4F c2)
	{
		int xmin = (int)vMin(v0.x, v1.x, v2.x);
		int xmax = (int)vMax(v0.x, v1.x, v2.x);
		int ymin = (int)vMin(v0.y, v1.y, v2.y);
		int ymax = (int)vMax(v0.y, v1.y, v2.y);
		
		if(xmin < 0) xmin = 0;
		if(xmax < 0) xmax = 0;
		if(xmax > w - 1) xmax = w - 1;
		if(xmin >= xmax) return;
		if(ymin < 0) ymin = 0;
		if(ymax < 0) ymax = 0;
		if(ymax > h - 1) ymax = h - 1;
		if(ymin >= ymax) return;
		
		_SHASH_ALG(zb, video, w, h, v0, v1, v2, xmin, xmax, ymin, ymax, c0, c1, c2);
	}
}