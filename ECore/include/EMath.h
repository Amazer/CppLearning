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

}
