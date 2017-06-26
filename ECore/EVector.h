#pragma once

#include "ECommon.h"
#include "EUtil.h"
//#include "EMath.h"

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
		EVector2D(EFloat xf,EFloat yf):x(xf),y(yf){}
		EVector2D(const EVector2D &v) :x(v.x), y(v.y) {}

		//�����淶��,���������ĳ���
		inline EFloat normalize()
		{
			EFloat len = length();
			if (len > EPSILON_E6)					//������С���ȣ�������Ϊ��0��
			{
				EFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
			}
			return len;
		}
		//�����ĵ��
		inline EFloat dotProduct(const EVector2D &right)const
		{
			return x*right.x + y*right.y;
		}

		//������������֮��ļн�,���ط�ʽΪ����
		inline EFloat angleSBetween(const EVector2D &right)const
		{
			EFloat lenProduct = length()*right.length();
			
			//������
			if (lenProduct < EPSILON_E6)
				lenProduct = EPSILON_E6;

			EFloat f = dotProduct(right) / lenProduct;
			//--------------> todo

		}

		//���������ĳ���
		inline EFloat length()const
		{
			return sqrt(x*x + y*y);
		}

	};


}

