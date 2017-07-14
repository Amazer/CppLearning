#include "EFrustum.h"
namespace E3D
{
	EFrustum::EFrustum(CAMERA_TYPE mode, const EVector4D &pos, const EVector4D &dir, const EVector4D& target,
		EFloat nearZ, EFloat farZ, EFloat ffov,
		EFloat viewportWidth, EFloat viewportHeight)
		:camMode(mode), position(pos), direction(dir), camTarget(target),
		clip_z_near(nearZ), clip_z_far(farZ), fov(ffov),
		viewport_width(viewportWidth), viewport_heigh(viewportHeight),
		camUp(EVector4D::UNIT_Y),camRight(EVector4D::UNIT_X),camLook(EVector4D::UNIT_Z),
		mWorldToCamera(EMatrix44::IDENTITY),mCameraToPerspective(EMatrix44::IDENTITY),
		mPerspectiveToScreen(EMatrix44::IDENTITY)
	{
		viewport_center_X = (viewport_width - 1)*0.5f;			// ��Χ������[0-1] or other?
		viewport_center_Y = (viewport_heigh - 1)*0.5f;

		aspect_ratio = viewport_width / viewport_heigh;

		viewplane_width = 2.0f;									//��̫�������ֵ�Ǹ�ɶ��
		viewplane_heigh = 2.0f;

		EFloat	tan_fov_div2 = tan(Degree_TO_Radian(fov*0.5f));		//�������ڼ���Զ���ü�ƽ��ĸ߶�,nearClipPanelHeight=2*Near*tan(FOV/2)
		view_dist = 0.5f*viewplane_width / tan_fov_div2;

		//���òü�ƽ��
		//�ü�ƽ�������ǻ������������ϵ��
		EVector4D point = EVector4D::ZERO;

		//�Ҳü���
		EVector4D normalR = EVector4D(-view_dist, 0, viewplane_width*0.5f);
		clip_plane_R = EPlane3D(point, normalR);

		//��ü�ƽ��
		EVector4D normalL = EVector4D(view_dist, 0, viewplane_width*0.5f);
		clip_plane_L = EPlane3D(point, normalL);

		//�ϲü�ƽ��
		EVector4D normalT = EVector4D(0, -view_dist, viewplane_heigh*0.5f);
		clip_plane_T = EPlane3D(point, normalT);

		//�²ü�ƽ��
		EVector4D normalB = EVector4D(0, view_dist, viewplane_heigh*0.5f);
		clip_plane_B = EPlane3D(point, normalB);

		//���������ϵ��͸������ϵ�任���󣬾�������任����Ҫ����w
		mPerspectiveToScreen = EMatrix44(view_dist, 0, 0, 0,
			0, view_dist*aspect_ratio, 0, 0,
			0, 0, 1, 1,
			0, 0, 0, 0);


	}

}
