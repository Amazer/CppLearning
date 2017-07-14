#pragma once
#include "ECommon.h"
#include "EVector.h"
namespace E3D
{
	enum LIGHT_TYPE
	{
		LIGHT_AMBIENT = 0,						//������
		LIGHT_DIRECTION=1,						//�����
		LIGHT_POINT=2,							//���Դ
	};

	struct ELight
	{
		EInt			id;				//�ƹ�ķ���ID,ȫ��Ψһ
		EBool			lightOn;		//�ƹ��Ƿ�����

		LIGHT_TYPE		lightType;		//�ƹ������

		EFloat			power;			//����ǿ�ȣ�Ĭ��ֵΪ1.0f
		EFloat			shadowFactor;	//�ƹⱳ��ǿ�ȣ�Ĭ��Ϊ0.05f

		EColor			ambient;		//�ƹ�Ļ���ɫ (������ʹ��)
		EColor			diffuse;		//�ƹ����������ɫ
		EColor			specular;		//�߹���ɫ

		EVector4D		position;		//�ƹ���������λ��
		EVector4D		direction;		//��Դ���򣬵��Դ��Ч

		EVector4D		transPosition;	//�ƹ�����������ϵλ��
		EVector4D		transDirection;	//�����������ϵ�У���Դ�ĳ��򡣵��Դ��Ч

		EFloat			kc, kl, kq;		//˥������

		EFloat			spot_inner;		//�۹����׶��
		EFloat			spot_outer;		//�۹����׶��
		EFloat			pf;				//�۹��ָ������

		ELight(EInt lightId, LIGHT_TYPE type);

	};

	//���ƹ���
	#define MAX_LIGHTS 8

	//ȫ�ֵƹ����
	extern std::vector<ELight*> *GLights;

	typedef std::vector<ELight*>::iterator LightItr;

	//����һ���µĵƹ⣬�����ɹ����صƹ�Ψһid(ȫ��Ψһ),����ʧ���򷵻�-1
	//����������Դ��ΪMAX_LIGHTS
	extern EInt CreateLight(LIGHT_TYPE lightType);

	//���һ���ƹ⣬����ƹⲻ���ڣ��򷵻�NULL
	extern ELight*	GetLight(EInt id);
	extern EInt		GetLightSize();
	
	//���ȫ����Դ
	extern void		DestroyAllLights();
}
