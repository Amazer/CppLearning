#pragma once
#include "ECommon.h"
#include "EVector.h"
#include "EMatrix.h"
#include "ECore.h"		
namespace E3D
{
	// UVN���ʹ���������ഹֱ����������ʾ�����λ���볯��
	//1.���ע�ӵ�����N
	//2.������Ϸ���������V
	//3.������ҷ���������U

	enum CAMERA_TYPE
	{
		CAMERA_MODEL_ELUA = 0x0001,		//ŷ�������ģ��
		CAMERA_MODEL_UVN  = 0x0002,		//UVN�����ģ��
	};

	struct EFrustum
	{
		EInt				state;			//�����״̬
		EInt				attribute;		//���������				��ʲô���ԣ�
		CAMERA_TYPE			camMode;		

		EVector4D			position;		//���������������ϵ�е�λ��
		EVector4D			direction;		//�����ע�ӵķ��� -- ����    

		//UVNģ��	����UVN�����			
		EVector4D			camUp;			//UVN�����ģ�͵ĳ���������
		EVector4D			camRight;		//UVN�����ģ�͵ĳ���������
		EVector4D			camLook;		//UVN�����ģ�͵�ע�ӷ���
		EVector4D			camTarget;		//UVN�����ģ�͵�ע�ӵ�

		EFloat				view_dist;		//�ӵ㵽ͶӰ��ľ���

		EFloat				fov;			//Field of View, ˮƽ����ʹ�ֱ�������Ұ (Unity�� ����ֱ������ſ��Ƕ�)

		EFloat				clip_z_near;	//���ü������
		EFloat				clip_z_far;		//Զ�ü������

		EPlane3D			clip_plane_R;	//�Ҳü�ƽ��
		EPlane3D			clip_plane_L;	//��ü�ƽ��
		EPlane3D			clip_plane_T;	//�ϲü�ƽ��
		EPlane3D			clip_plane_B;	//�²ü�ƽ��

		EFloat				viewplane_width;	//ͶӰ���ߣ����ڹ�һ��ͶӰ��Ϊ2x2,�����С����Ļ���ڴ�С��ͬ
		EFloat				viewplane_heigh;

		EFloat				viewport_width;		//��Ļ/�ӿڵĴ�С
		EFloat				viewport_heigh;
		EFloat				viewport_center_X;	//��Ļ����������
		EFloat				viewport_center_Y;

		EFloat				aspect_ratio;		//��Ļ�Ŀ�߱�    (Unity��Ҳ�ǿ�߱�)

		EMatrix44			mWorldToCamera;			//�������굽�������ı任����
		EMatrix44			mCameraToPerspective;	//������굽͸������ϵ�ı任����
		EMatrix44			mPerspectiveToScreen;	//͸������ϵ����Ļ����ϵ�任����

		EFrustum(CAMERA_TYPE mode, const EVector4D &pos, const EVector4D &dir,
			const EVector4D& target, EFloat nearZ, EFloat farZ, EFloat ffov,
			EFloat viewportWidth, EFloat viewportHeight);
	};
}
