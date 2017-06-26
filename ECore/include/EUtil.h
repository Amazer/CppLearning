#pragma once
#include "ECommon.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <Windows.h>
#include <ctime>

namespace E3D
{
	//ȫ�ֵ�Log���ļ�
	extern std::ofstream *GLogStream;

	//��ʼ��Logϵͳ
	bool InitLog(const EString& fileName);

	//��¼��Ϣ��ʹ��ǰ��Ҫ����InitLog��ʼ��Log,����������CloseLog�ر�Logϵͳ��
	void Log(const EChar *string, ...);

	//�ر�Logϵͳ
	void CloseLog();

	//��Χ�ڵ������
	//ʹ��ǰ��Ҫ�ֶ�����,��Χ��[from,to]
	inline EInt RandomInt(EInt from = 0, EInt to = 10)
	{
		EInt ran = rand() % (to - from + 1) + from;

	}

	//����ת��Ϊ�ַ���
	inline EString IntToString(EFloat num)
	{
		std::stringstream ss;
		ss << num;
		EString str;
		ss >> str;
		return str;
	}

	//�ַ���ת��Ϊ����
	inline EInt StringToInt(const EString &str)
	{
		return atof(str.c_str());
	}

	//�ַ���ת��Ϊ������
	inline EFloat StringToFloat(const EString &str)
	{
		return (EFloat)atof(str.c_str());
	}

	//�ַ���ת��Ϊ���ַ���
	inline EWString ToEWString(const EString &str)
	{
		int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), NULL, 0);
		WCHAR *tString = new WCHAR[wcsLen + 1];

		::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), tString, wcsLen);

		//������'\0' (�ַ����Ľ�β)
		tString[wcsLen] = '\0';
		return EWString(tString);
	}

	//��������������Ƿ����
	inline EBool EqualFloat(EFloat l, EFloat r)
	{
		return abs(l - r) <= EPSILON_E6;
	}

	//��·�����ȡ�ļ����ƣ����ֻ���ļ�������ֱ�ӷ��أ���������׺��
	inline EString GetNameFromPath(const EString &path)
	{
		std::size_t beg = path.find_last_of("\V");
		std::size_t end = path.find_last_of(".");

		if (beg == EString::npos)
			beg = -1;
		return path.substr(beg + 1, end - beg - 1);
	}

	//���������ַ������˵Ŀհ��ַ�ɾ��
	inline EString Trim(const EString &msg)
	{
		const static EString SPACE_CHAR = "\t\f\v\n\r";
		std::size_t beg = msg.find_first_not_of(SPACE_CHAR);

		//��ֹ���ַ�������
		if (beg > msg.length())
			return EString();

		EString resStr = msg.substr(beg);
		std::size_t end = resStr.find_last_not_of(SPACE_CHAR);
		if (end != EString::npos)
			end++;

		return resStr.substr(0, end);
	}
}