//Objects.CubeObject.cpp
///////////////////////////////////////////////////

#include "..\GameCore.h"

namespace OBJECTS
{
	void CubeObject::_Initialize()
	{
		//Initialize Cube////////////////////////
		
		this->rotation = 0.0;

		//Bounding region for cube
		float xmin = -100.0, xmax = 100.0;
		float ymin = -100.0, ymax = 100.0;
		float zmin = -100.0, zmax = 100.0;

		//Vertices for cube
		this->_mesh.num_v = 8;
		this->_mesh.vb = new _VERTEX4F[8];

		//Initialize cube verticies
		_VERTEX4F cube_v[] = {
			_VERTEX4F(xmin, ymin, zmin, 1.0),
			_VERTEX4F(xmin, ymin, zmax, 1.0),
			_VERTEX4F(xmin, ymax, zmin, 1.0),
			_VERTEX4F(xmin, ymax, zmax, 1.0),
			_VERTEX4F(xmax, ymin, zmin, 1.0),
			_VERTEX4F(xmax, ymin, zmax, 1.0),
			_VERTEX4F(xmax, ymax, zmin, 1.0),
			_VERTEX4F(xmax, ymax, zmax, 1.0)
		};

		for(int n = 0; n < 8; n++)
		{
			this->_mesh.vb[n] = cube_v[n];
		}

		// Triangles for cube
		this->_mesh.num_i = 12;
		this->_mesh.ib = new _TRIANGLE3I[12];
		
		_TRIANGLE3I cube_i[] = {
			{ 0, 1, 2 }, { 1, 3, 2 },
			{ 0, 5, 1 }, { 0, 4, 5 },
			{ 2, 3, 7 }, { 2, 7, 6 },
			{ 7, 5, 4 }, { 6, 7, 4 },
			{ 0, 2, 4 }, { 2, 6, 4 },
			{ 1, 5, 3 }, { 5, 7, 3 }
		};

		for(int n = 0; n < 12; n++)
		{
			this->_mesh.ib[n] = cube_i[n];
		}

		//Color channel for cube
		this->_mesh.num_c = 8;
		this->_mesh.cb = new _COLOR4F[8];

		_COLOR4F c0 = { 1.0, 0.5, 0.5, 0.5 };
		_COLOR4F c1 = { 1.0, 0.0, 0.0, 1.0 };
		_COLOR4F c2 = { 1.0, 0.0, 1.0, 0.0 };
		_COLOR4F c3 = { 1.0, 1.0, 0.0, 0.0 };

		for(int n = 0; n < 8; n++)
		{
			if((n%4) == 0)
			{
				this->_mesh.cb[n] = c0;
			}
			if((n%4) == 1)
			{
				this->_mesh.cb[n] = c1;
			}
			if((n%4) == 2)
			{
				this->_mesh.cb[n] = c2;
			}
			if((n%4) == 3)
			{
				this->_mesh.cb[n] = c3;
			}
		}
	}



	void CubeObject::_Uninitialize()
	{
		delete [] this->_mesh.vb;
		delete [] this->_mesh.ib;
		delete [] this->_mesh.cb;
	}

	void CubeObject::_Draw(float *zb, int *video, int nWidth, int nHeight)
	{
		this->rotation += 1.0;
		for(int n = 0; n < this->_mesh.num_i; n++)
		{
			_TRIANGLE3I &triangle = this->_mesh.ib[n];
			
			_VERTEX4F v0 = this->_mesh.vb[triangle.a];
			_VERTEX4F v1 = this->_mesh.vb[triangle.b];
			_VERTEX4F v2 = this->_mesh.vb[triangle.c];

			_COLOR4F &c0 = this->_mesh.cb[triangle.a];
			_COLOR4F &c1 = this->_mesh.cb[triangle.b];
			_COLOR4F &c2 = this->_mesh.cb[triangle.c];
			
			_MATRIX16F m;
			m = _MATRIX16F::_RotateZ(1.0*this->rotation);
			v0 = m._Multiply(v0);
			v1 = m._Multiply(v1);
			v2 = m._Multiply(v2);
			m = _MATRIX16F::_RotateY(1.0*this->rotation);
			v0 = m._Multiply(v0);
			v1 = m._Multiply(v1);
			v2 = m._Multiply(v2);

			_VERTEX4F origin(nWidth/2.0, nHeight/2.0, 0.0, 0.0);
			v0 = v0 + origin;
			v1 = v1 + origin;
			v2 = v2 + origin;

			_DrawTriangle(zb, video, nWidth, nHeight, v0, v1, v2, c0, c1, c2);
		}

	}

	void CubeObject::_RunAI()
	{

	}
}