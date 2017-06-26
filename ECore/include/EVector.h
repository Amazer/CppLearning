#pragma once

#include "ECommon.h"
#include "EUtil.h"
//#include "EMath.h"

namespace E3D
{

	//2D向量：VECTOR2D_TYP
	struct EVector2D
	{
		static EVector2D ZERO;
		static EVector2D UNIT_X;
		static EVector2D UNIT_Y;

		EFloat x;
		EFloat y;

		EVector2D() :x(0), y(0) {}
		EVector2D(EFloat xf,EFloat yf):x(xf),y(yf){}
		EVector2D(const EVector2D &v) :x(v.x), y(v.y) {}

		//向量规范化
		inline EFloat normalize()
		{
//			EFloat len = length();

		}

	};

}

