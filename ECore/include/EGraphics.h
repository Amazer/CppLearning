#pragma once

#include "ECommon.h"
#include <Windows.h>

//ͼ����Ⱦ�ײ��ʵ�� ���� ��ʲô������)
namespace E3D
{
	extern HINSTANCE GHInstance;

	//ͼƬ��װ������ͼƬʹ�õ�GDI+��ͼƬ��
	//��������Ҳ�������з�װ����ƽ̨��صĶ�������
	class EBitmap
	{
	public:
		EInt width, height;
		EBitmap(const EString &filename);
		~EBitmap();

		inline EString	getName() const { return name; }
		inline bool isValid() const { return valid; }
		EColor getPixel(EInt x, EInt y);
		inline EInt getHeight()const { return height; }
		inline EInt getWidht()const { return width; }

	private:
		EString name;

		HBITMAP hBitmap;
		BITMAP bitmap;
		HDC bitmapHDC;

	public:
		EColor *pixels;
		EInt pitch;
		EBool valid;
	};

	class EGraphics
	{
	public:

		//��ʼ����ͼϵͳ
		static bool initGraphics(HINSTANCE hinstance);

		//�رջ�ͼϵͳ
		static void shutdownGraphics();

		//���zֵ������true��ʾͨ����⣬���Ե���setPixed (��ȼ��)
		static EBool checkZ(EInt x, EInt y, EFloat z);
		static void setPixel(EInt x, EInt y,/*EFloat z*/ const EColor &c);
		static EColor getPixel(EInt x, EInt y);

		//�ڵ�ǰ�������ڻ���һ����
		static void drawLine(EInt x0, EInt y0, EInt x1, EInt y1, const EColor &c);
		static void drawString(const EString &str, EInt x, EInt y, const EColor &c = EColor(255, 155, 155));
		static void fillTriangle(EInt x0, EInt y0, EInt x1, EInt y1, EInt x2, EInt y2,
			const EColor &c = EColor(255, 255, 255));

		static void enableSmoothingMode(EBool enable);
		
		//��յ�ǰ����������������ɫ����Ϊ��ɫ
		static void clearBuffer(const EColor &c = EColor());

		//���Ѿ����ƺõĻ������ݽ���Graphics��������Ļ�ϻ��ƣ�����ǰ����������Ϊ��һ��������
		static void fillBuffer(HDC hdc);

		static EInt getScreenWidth() { return SCREEN_WIDTH; }
		static EInt getScreenHeight() { return SCREEN_HEIGHT; };

	private:

		//�������
		static HBITMAP				GBufferedHandle;
		static HDC					GBufferedHDC;
		static HBRUSH				GBgBrush;
		static HPEN					GPen;
		static HINSTANCE			GHInstance;

		static BYTE					*GDatas;
		static EInt					GPitch;

		static DIBSECTION			GDIBSection;

		static RECT					GBufferSize;
		static EFloat				*GZBuffer;
	};
}
