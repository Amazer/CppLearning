#include "EGraphics.h"
#include "EUtil.h"

namespace E3D
{
	//------------------------------------------------------------------------

	EBitmap::EBitmap(const EString &filename) :name(filename), pixels(NULL),
		pitch(0), width(0), height(0), valid(false)
	{

		//材质脚本，首先获取默认路径
		hBitmap = (HBITMAP)::LoadImage(GHInstance, GetPath(filename).c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		if (hBitmap != NULL)
		{
			bitmapHDC = ::CreateCompatibleDC(NULL);
			::SelectObject(bitmapHDC, (HGDIOBJ)hBitmap);
			::GetObject(hBitmap, sizeof(BITMAP), &bitmap);

			width = bitmap.bmWidth;
			height = bitmap.bmHeight;
			pitch = bitmap.bmHeight;
			valid = true;

			pixels = new EColor(width*height);
			for (EInt i = 0; i < getHeight(); ++i)
			{
				for (EInt j = 0; j < getWidht(); ++j)
				{
					COLORREF color = ::GetPixel(bitmapHDC,i,j);
					pixels[j*width + i] = EColor(GetRValue(color), GetGValue(color), GetBValue(color));

				}
			}
		}
	}

	// -----------------------------
	EBitmap::~EBitmap()
	{
		DeleteObject(hBitmap);
		DeleteDC(bitmapHDC);
		SafeDeleteArray(pixels);
	}

	// -----------------------------

	EColor EBitmap::getPixel(EInt x, EInt y)
	{
		return pixels[y*pitch + x];
	}

	// -----------------------------

	HINSTANCE GHInstance;

	HBITMAP					EGraphics::GBufferedHandle;
	HDC						EGraphics::GBufferedHDC;
	HBRUSH					EGraphics::GBgBrush;
	HPEN					EGraphics::GPen;
	HINSTANCE  	 			EGraphics::GHInstance;
	RECT					EGraphics::GBufferSize;
	DIBSECTION				EGraphics::GDIBSection;
	BYTE					*EGraphics::GDatas;
	EInt					EGraphics::GPitch;


	EFloat					*EGraphics::GZBuffer;

	//---------------------------------

	// 初始化绘图系统
	bool EGraphics::initGraphics(HINSTANCE hinstance)
	{
		GBufferedHDC = ::CreateCompatibleDC(NULL);

		//////////////////
		BITMAPINFO info = { 0 };
		info.bmiHeader.biSize = sizeof(info.bmiHeader);
	}

}