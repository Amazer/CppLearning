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

	//将val的范围限制在min-max之间
	template<typename T>
	const T& Clamp(const T& val, const T& minV, const T& maxV)
	{
		return Min(Max(val, maxV), minV);
	}

	//获取平移变换矩阵
	void GetTranslateMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//获取缩放变换矩阵
	void GetScaleMatrix44(EMatrix44 &mat, EFloat x, EFloat y, EFloat z);

	//获取延x轴旋转的变换矩阵
	//旋转参数为角度，非弧度
	void GetRotateMatrix44X(EMatrix44 &mat, EFloat degree);

	//获取延y轴旋转的变换矩阵
	//旋转参数为角度，非弧度
	void GetRotateMatrix44Y(EMatrix44 &mat, EFloat degree);

	//获取延z轴旋转的变换矩阵
	//旋转参数为角度，非弧度
	void GetRotateMatrix44Z(EMatrix44 &mat, EFloat degree);


	//获取延任意轴旋转的变换矩阵
	//旋转参数为角度，非弧度
	void GetRotateMatrix44(EMatrix44 &mat, const EVector4D &normal,EFloat degree);

	// 4D顶点和向量相加
	void GetVertex4DAddVector4D(const EVertex4D &v, const EVector4D &p, EVertex4D &result);

	//3D向量X44向量
	void GetVector3DMulMatrix44(const EVector3D &vec, const EMatrix44 &mat, EVector3D &result);

	//4D向量X44向量
	void GetVector4DMulMatrix44(const EVector4D &vec, const EMatrix44 &mat, EVector4D &result);

	//4D顶点X44向量
	void GetVertex4DMulMatrix44(const EVector4D &vec, const EMatrix44 &mat, EVector4D &result);
}
