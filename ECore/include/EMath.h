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

}
