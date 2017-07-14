#include "ECommon.h"
#include "EVector.h"
#include <list>

#pragma once
namespace E3D
{

	// 顶点对象，包含顶点，发现，uv
	struct  EVertex4D
	{
		EFloat x, y, z, w;

		EFloat u, v;

		EVertex4D();
		EVertex4D(const EVertex4D &v);
		EVertex4D(EFloat xf, EFloat yf, EFloat zf);
		EVertex4D operator *(const EVector4D &right);
		EVertex4D operator -(const EVertex4D &right);
		EVertex4D operator =(const EVertex4D &right);
		EVertex4D operator +(const EVertex4D &right);
		EVertex4D operator +(const EVector4D &right);
		EVertex4D operator /(EFloat factor);

		EVertex4D toVector4D() const;

	};

	//面		，由法线和平面上的一点确定一个面
	struct EPlane3D
	{
		EVector4D	point;		//面上一点
		EVector4D	normal;		//面的法线

		EPlane3D() {}
		EPlane3D(const EVector4D &p, const EVector4D &nor);
		EPlane3D& operator=(const EPlane3D &right);

	};
}