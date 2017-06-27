#pragma once

#include "ECommon.h"
#include "EUtil.h"
#include "EMath.h"

namespace E3D
{

	//2D������VECTOR2D_TYP
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

		//�����淶��,���������ĳ���
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

		//�����ĵ��
		inline EFloat dotProduct(const EVector2D &right)const {
			return x*right.x + y*right.y;
		}

		//������������֮��ļнǣ����ط�ʽΪ����
		inline EFloat angleBetween(const EVector2D &right)const
		{
			EFloat lenProduct = length()*right.length();

			//������
			if (lenProduct < EPSILON_E6)
			{
				lenProduct = EPSILON_E6;
			}

			EFloat f = dotProduct(right) / lenProduct;
			f = Clamp(f, -1.0f, 1.0f);
			return acos(f);
		}

		//�жϳ����Ƿ�Ϊ0
		inline bool isZero()const
		{
			return length() < EPSILON_E6;
		}

		//������������
		inline EFloat length()const
		{
			return sqrt(x*x + y*y);
		}

		//���س��ȵ�ƽ��
		inline EFloat squaredLenght() const
		{
			return x*x + y*y;
		}

		//���������ĳ˷�
		inline EVector2D operator*(float right)const
		{
			return EVector2D(x*right, y*right);
		}

		//�����ĵ��
		inline EVector2D operator*(const EVector2D &right)const
		{
			return EVector2D(x*right.x, y*right.y);
		}

		//�����ļӷ�
		inline EVector2D operator+(const EVector2D &right)const
		{
			return EVector2D(x + right.x, y + right.y);
		}

		//�����ļ���
		inline EVector2D operator-(const EVector2D &right)const
		{
			return EVector2D(x - right.x, y - right.y);
		}

		//����ȡ��
		inline EVector2D operator-()
		{
			x = -x;
			y = -y;
			return *this;
		}

		//����ȡ��
		inline EVector2D operator+()
		{
			x = +x;
			y = +y;
			return *this;
		}

		//�ж����������Ƿ����
		inline bool operator==(const EVector2D &right)const
		{
			return EqualFloat(x, right.x) && EqualFloat(y, right.y);
		}

		//�����ĸ�ֵ
		inline EVector2D operator=(const EVector2D &right)
		{
			x = right.x;
			y = right.y;
			return *this;
		}
	};

	//3D������VECTOR3D_TYP

	struct EVector3D
	{
		static EVector3D ZERO;
		static EVector3D UNIT_X;
		static EVector3D UNIT_Y;
		static EVector3D UNIT_Z;

		EFloat x;
		EFloat y;
		EFloat z;

		//���캯��
		EVector3D() :x(0), y(0), z(0) {}
		EVector3D(EFloat xf, EFloat yf, EFloat zf) :x(xf), y(yf), z(zf) {}
		EVector3D(const EVector3D &v) :x(v.x), y(v.y), z(v.z) {};

		//�����ĵ��
		inline EFloat dotProduct(const EVector3D &right)const
		{
			return x*right.x + y*right.y + z*right.z;
		}
	};
}

