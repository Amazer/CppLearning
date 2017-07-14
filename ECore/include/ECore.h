#include "ECommon.h"
#include "EVector.h"
#include <list>

#pragma once
namespace E3D
{

	// ������󣬰������㣬���֣�uv
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

	//��		���ɷ��ߺ�ƽ���ϵ�һ��ȷ��һ����
	struct EPlane3D
	{
		EVector4D	point;		//����һ��
		EVector4D	normal;		//��ķ���

		EPlane3D() {}
		EPlane3D(const EVector4D &p, const EVector4D &nor);
		EPlane3D& operator=(const EPlane3D &right);

	};
}