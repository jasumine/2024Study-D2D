#pragma once
#include <typeinfo>

namespace DX2DClasses
{
	class CColorBrush;
	struct SVector2;

	class CDebugHelper
	{
	public: 
		//�ֵܼ����
		static void OpenConsole();
		static void CloseConsole();
		static void LogConsole(const char* msg, ...);
	public: 
		//�׷��ȵ����
		static void DrawLine(SVector2& start, SVector2& end, CColorBrush* pColorBrush, float stroke = 1.0f);
		static void DrawCircle(SVector2& pos, float rad, CColorBrush* pColorBrush, float stroke = 1.0f);
		static void DrawRect(SVector2& tl, SVector2& br, CColorBrush* pColorBrush, float stroke = 1.0f);
		static void DrawPolygon(SVector2 posArr[], int size, CColorBrush* pColorBrush, float stroke = 1.0f);
	};
}