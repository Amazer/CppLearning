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

		//向量规范化,返回向量的长度
		inline EFloat normalize()
		{
			EFloat len = length();
			if (len > EPSILON_E6)					//大于最小精度，否则认为是0；
			{
				EFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
			}
			return len;
		}
		//向量的点乘
		inline EFloat dotProduct(const EVector2D &right)const
		{
			return x*right.x + y*right.y;
		}

		//返回两个向量之间的夹角,返回方式为弧度
		inline EFloat angleSBetween(const EVector2D &right)const
		{
			EFloat lenProduct = length()*right.length();
			
			//除零检测
			if (lenProduct < EPSILON_E6)
				lenProduct = EPSILON_E6;

			EFloat f = dotProduct(right) / lenProduct;
			//--------------> todo

		}

		//返回向量的长度
		inline EFloat length()const
		{
			return sqrt(x*x + y*y);
		}

	};


}

