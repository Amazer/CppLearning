#pragma once
#include "ECommon.h"
#include "EVector.h"
#include "EMatrix.h"
#include "ECore.h"		
namespace E3D
{
	// UVN相机使用三个互相垂直的向量来表示相机的位置与朝向
	//1.相机注视的向量N
	//2.相机的上方方向向量V
	//3.相机的右方方向向量U

	enum CAMERA_TYPE
	{
		CAMERA_MODEL_ELUA = 0x0001,		//欧拉摄像机模型
		CAMERA_MODEL_UVN  = 0x0002,		//UVN摄像机模型
	};

	struct EFrustum
	{
		EInt				state;			//摄像机状态
		EInt				attribute;		//摄像机属性				？什么属性？
		CAMERA_TYPE			camMode;		

		EVector4D			position;		//摄像机在世界坐标系中的位置
		EVector4D			direction;		//摄像机注视的方向 -- 朝向    

		//UVN模型	定义UVN摄像机			
		EVector4D			camUp;			//UVN摄像机模型的朝向上向量
		EVector4D			camRight;		//UVN摄像机模型的朝向右向量
		EVector4D			camLook;		//UVN摄像机模型的注视方向
		EVector4D			camTarget;		//UVN摄像机模型的注视点

		EFloat				view_dist;		//视点到投影面的距离

		EFloat				fov;			//Field of View, 水平方向和垂直方向的视野 (Unity中 是竖直方向的张开角度)

		EFloat				clip_z_near;	//近裁剪面距离
		EFloat				clip_z_far;		//远裁剪面距离

		EPlane3D			clip_plane_R;	//右裁剪平面
		EPlane3D			clip_plane_L;	//左裁剪平面
		EPlane3D			clip_plane_T;	//上裁剪平面
		EPlane3D			clip_plane_B;	//下裁剪平面

		EFloat				viewplane_width;	//投影面宽高，对于归一化投影，为2x2,否则大小与屏幕窗口大小相同
		EFloat				viewplane_heigh;

		EFloat				viewport_width;		//屏幕/视口的大小
		EFloat				viewport_heigh;
		EFloat				viewport_center_X;	//屏幕的中心坐标
		EFloat				viewport_center_Y;

		EFloat				aspect_ratio;		//屏幕的宽高比    (Unity中也是宽高比)

		EMatrix44			mWorldToCamera;			//世界坐标到相机坐标的变换矩阵
		EMatrix44			mCameraToPerspective;	//相机坐标到透视坐标系的变换矩阵
		EMatrix44			mPerspectiveToScreen;	//透视坐标系到屏幕坐标系变换矩阵

		EFrustum(CAMERA_TYPE mode, const EVector4D &pos, const EVector4D &dir,
			const EVector4D& target, EFloat nearZ, EFloat farZ, EFloat ffov,
			EFloat viewportWidth, EFloat viewportHeight);
	};
}
