#pragma once

#include "ECommon.h"

namespace E3D
{
	template<typename T>
	const T& Min(const T& a, const T& b)
	{
		return (a < b) ? a : b;
	}

	template<typename T>
	const T& Max(const T& a, const T& b)
	{
		return (a > b) ? a : b;
	}

	//��val�ķ�Χ������min-max֮��
	template<typename T>
	const T& Clamp(const T& val, const T& minV, const T& maxV)
	{
		return Min(Max(val, maxV), minV);
	}

	//��ȡƽ�Ʊ任����
	void GetTranslateMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//��ȡ���ű任����
	void GetScaleMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//��ȡ��x����ת�ı任����
	//��ת����Ϊ�Ƕȣ��ǻ���
	void GetRotateMatrix44X(EMatrix44 &mat, EFloat degree);

	//��ȡ��y����ת�ı任����
	//��ת����Ϊ�Ƕȣ��ǻ���
	void GetRotateMatrix44Y(EMatrix44 &mat, EFloat degree);

	//��ȡ��z����ת�ı任����
	//��ת����Ϊ�Ƕȣ��ǻ���
	void GetRotateMatrix44Z(EMatrix44 &mat, EFloat degree);


	//��ȡ����������ת�ı任����
	//��ת����Ϊ�Ƕȣ��ǻ���
	void GetRotateMatrix44(EMatrix44 &mat, const EVector4D &normal,EFloat degree);

	// 4D������������
	void GetVertex4DAddVector4D(const EVertex4D &v, const EVector4D &p, EVertex4D &result);

	//3D����X44����
	void GetVector3DMulMatrix44(const EVector3D &vec, const EMatrix44 &mat, EVector3D &result);

	//4D����X44����
	void GetVector4DMulMatrix44(const EVector4D &vec, const EMatrix44 &mat, EVector4D &result);

	//4D����X44����
	void GetVertex4DMulMatrix44(const EVector4D &vec, const EMatrix44 &mat, EVector4D &result);
}
