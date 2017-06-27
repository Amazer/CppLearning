#pragma once

#include "ECommon.h"
#include "EUtil.h"
#include "EMath.h"

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
		EVector2D(EFloat xf, EFloat yf) :x(xf), y(yf) {}
		EVector2D(const EVector2D &v) :x(v.x), y(v.y) {}

		//向量规范化,返回向量的长度
		inline EFloat normalize()
		{
			EFloat len = length();
			if (len > EPSILON_E6)
			{
				EFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
			}
			return len;
		}

		//向量的点乘
		inline EFloat dotProduct(const EVector2D &right)const {
			return x*right.x + y*right.y;
		}

		//返回两个向量之间的夹角，返回方式为弧度
		inline EFloat angleBetween(const EVector2D &right)const
		{
			EFloat lenProduct = length()*right.length();

			//除零检查
			if (lenProduct < EPSILON_E6)
			{
				lenProduct = EPSILON_E6;
			}

			EFloat f = dotProduct(right) / lenProduct;
			f = Clamp(f, -1.0f, 1.0f);
			return acos(f);
		}

		//判断长度是否为0
		inline bool isZero()const
		{
			return length() < EPSILON_E6;
		}

		//返回向量长度
		inline EFloat length()const
		{
			return sqrt(x*x + y*y);
		}

		//返回长度的平方
		inline EFloat squaredLenght() const
		{
			return x*x + y*y;
		}

		//向量与数的乘法
		inline EVector2D operator*(float right)const
		{
			return EVector2D(x*right, y*right);
		}

		//向量的点积
		inline EVector2D operator*(const EVector2D &right)const
		{
			return EVector2D(x*right.x, y*right.y);
		}

		//向量的加法
		inline EVector2D operator+(const EVector2D &right)const
		{
			return EVector2D(x + right.x, y + right.y);
		}

		//向量的减法
		inline EVector2D operator-(const EVector2D &right)const
		{
			return EVector2D(x - right.x, y - right.y);
		}

		//向量取反
		inline EVector2D operator-()
		{
			x = -x;
			y = -y;
			return *this;
		}

		//向量取正
		inline EVector2D operator+()
		{
			x = +x;
			y = +y;
			return *this;
		}

		//判断两个向量是否相等
		inline bool operator==(const EVector2D &right)const
		{
			return EqualFloat(x, right.x) && EqualFloat(y, right.y);
		}

		//向量的赋值
		inline EVector2D operator=(const EVector2D &right)
		{
			x = right.x;
			y = right.y;
			return *this;
		}
	};

	//3D向量：VECTOR3D_TYP

	struct EVector3D
	{
		static EVector3D ZERO;
		static EVector3D UNIT_X;
		static EVector3D UNIT_Y;
		static EVector3D UNIT_Z;

		EFloat x;
		EFloat y;
		EFloat z;

		//构造函数
		EVector3D() :x(0), y(0), z(0) {}
		EVector3D(EFloat xf, EFloat yf, EFloat zf) :x(xf), y(yf), z(zf) {}
		EVector3D(const EVector3D &v) :x(v.x), y(v.y), z(v.z) {};

		//向量的点乘
		inline EFloat dotProduct(const EVector3D &right)const
		{
			return x*right.x + y*right.y + z*right.z;
		}
	};
}

