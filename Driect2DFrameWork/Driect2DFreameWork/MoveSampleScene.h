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
		//���������� ������ ��ü ����׵���̿� �Բ� ����Ѵ�.
		CColorBrushPalettet* m_pColorBrushPalettet;

		//������ �ʿ��� �̹����� �������� ��ü	
		CImage* m_pPlayerImage;
		CImage* m_pOpossumImage;
		CImage* m_pEagleImage;

		CImage* m_pCherryImage;
		CImage* m_pGemImage;

		CImage* m_pItemEffectImage;
		CImage* m_pDeathEffectImage;


		CImage* m_pBackgroundImage;
		CImage* m_pBulletImage;

		//������ �ε�� �̹����� ���� �ִϸ��̼� �� ������ �����Ѵ�.
		//���ӿ�����Ʈ�� ���������� ��ü�� ���Ե��Ƿ� �� ������ �Ϲ����̴�.
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

		void Initialize(HWND hWnd, CDriect2DFramwork* pDX2DFramework) override; //�ʱ�ȭ
		void Release() override; //������ü ����

		void Update() override; //��������
		void Draw() override; //��ü �׸���

	public:
		bool m_isColPlayerToPossum;
		bool m_isColplayerToEagle;

		void BulletCreate(SVector2);
		void CollisionCheckDraw();
		void ColliderDraw();
	};
}