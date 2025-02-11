#pragma once
#include "DX2DClasses/SceneManager.h"
#include "DX2DClasses/Vector2.h"
#include <queue>

using namespace std;

namespace DX2DClasses
{
	class CRect;
	class CPolygon;
	class CTriangle;
	class CCircle;
	class CImage;
	class CColorBrush;
	class CColorBrushPalettet;
	class CGameObject;

	class CCircleCollider;
	class CRectCollider;
	class CBoxCollider;

	class CMoveSampleScene : public ISceneManager
	{
		//색상정보가 설정된 객체 디버그도우미와 함께 사용한다.
		CColorBrushPalettet* m_pColorBrushPalettet;

		//게임이 필요한 이미지를 가져오는 객체	
		CImage* m_pPlayerImage;
		CImage* m_pOpossumImage;
		CImage* m_pEagleImage;

		CImage* m_pCherryImage;
		CImage* m_pGemImage;

		CImage* m_pItemEffectImage;
		CImage* m_pDeathEffectImage;


		CImage* m_pBackgroundImage;
		CImage* m_pBulletImage;

		//실제로 로드된 이미지를 토대로 애니메이션 및 변형을 수행한다.
		//게임오브젝트는 실제복제된 객체도 포함도므로 더 많은게 일반적이다.
		CGameObject* m_pPlayerObject;
		CGameObject* m_pOpossumObject;
		CGameObject* m_pEagleObject;
		
		CGameObject* m_pCherryObject;
		CGameObject* m_pGemObject;

		CGameObject* m_pItemEffectObject;
		CGameObject* m_pDeathEffectObject;


		CGameObject* m_pBackgroundObject;
		CGameObject* m_pBulletObject01;
		CGameObject* m_pBulletObject02;
		CGameObject* m_pBulletObject03;

		CGameObject* m_pBulletObject04;
		CGameObject* m_pBulletObject05;
		CGameObject* m_pBulletObject06;

		queue<CGameObject*> m_qBulletUse;
		queue<CGameObject*> m_qBulletUnUse;


		CBoxCollider* m_pPlayerBoxCollider;
		CRectCollider* m_pPlayerRectCollider;
		CCircleCollider* m_pPlayerCircleCollider;

		CBoxCollider* m_pOpossumBoxCollider;
		CRectCollider* m_pOpossumRectCollider;

		CCircleCollider* m_pEagleCircleCollider;

		CBoxCollider* m_pBullet01BoxCollider;
		CRectCollider* m_pBullet01RectCollider;


	public:
		CMoveSampleScene();
		~CMoveSampleScene();

		void Initialize(HWND hWnd, CDriect2DFramwork* pDX2DFramework) override; //초기화
		void Release() override; //동적객체 제거

		void Update() override; //정보변경
		void Draw() override; //객체 그리기

	public:
		bool m_isColPlayerToPossum;
		bool m_isColplayerToEagle;

		void BulletCreate(SVector2);
		void CollisionCheckDraw();
		void ColliderDraw();
	};
}