#include "MoveSampleScene.h"
#include "DX2DClasses/Driect2DFramework.h"
#include "DX2DClasses/SingletonRenderTarget.h"
#include "DX2DClasses/ColorBrush.h"
#include "DX2DClasses/Vector2.h"
#include "DX2DClasses/Image.h"
#include "DX2DClasses/InputManager.h"
#include "DX2DClasses/CollisionCheck.h"
#include "DX2DClasses/ColorBrushPalettet.h"
#include "DX2DClasses/DebugHelper.h"
#include "DX2DClasses/GameObject.h"
#include "DX2DClasses/Colliders.h"
#include "DX2DClasses/Matrix3.h"
#include <conio.h>

using namespace DX2DClasses;


CMoveSampleScene::CMoveSampleScene()
{
	//Initialize();
}

CMoveSampleScene::~CMoveSampleScene()
{
	//Release();
}

void CMoveSampleScene::Initialize(HWND hWnd, CDriect2DFramwork* pDX2DFramework)
{

	ID2D1HwndRenderTarget* pRenderTarget = CSingletonRenderTarget::GetRenderTarget();

	m_pColorBrushPalettet = new CColorBrushPalettet();
	m_pColorBrushPalettet->Initialize(pRenderTarget);

	m_pPlayerImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 6);
	m_pPlayerImage->ManualLoadImage(hWnd, L"Images\\player%02d.png");
	m_pPlayerObject = new CGameObject();
	m_pPlayerObject->Initialize(m_pPlayerImage, true);

	m_pOpossumImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(),6);
	m_pOpossumImage->ManualLoadImage(hWnd, L"Images\\opossum%02d.png");
	m_pOpossumObject = new CGameObject();
	m_pOpossumObject->Initialize(m_pOpossumImage, true);

	m_pEagleImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 4);
	m_pEagleImage->ManualLoadImage(hWnd, L"Images\\eagle%02d.png");
	m_pEagleObject = new CGameObject();
	m_pEagleObject->Initialize(m_pEagleImage, true);

	m_pCherryImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 6);
	m_pCherryImage->ManualLoadImage(hWnd, L"Images\\cherry%02d.png");
	m_pCherryObject = new CGameObject();
	m_pCherryObject->Initialize(m_pCherryImage, true);

	m_pGemImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 5);
	m_pGemImage->ManualLoadImage(hWnd, L"Images\\gem%02d.png");
	m_pGemObject = new CGameObject();
	m_pGemObject->Initialize(m_pGemImage, true);

	m_pItemEffectImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 4);
	m_pItemEffectImage->ManualLoadImage(hWnd, L"Images\\itemeffect%02d.png");
	m_pItemEffectObject = new CGameObject();
	m_pItemEffectObject->Initialize(m_pItemEffectImage, true);

	m_pDeathEffectImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 5);
	m_pDeathEffectImage->ManualLoadImage(hWnd, L"Images\\death%02d.png");
	m_pDeathEffectObject = new CGameObject();
	m_pDeathEffectObject->Initialize(m_pDeathEffectImage, true);


	m_pBackgroundImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 1);
	m_pBackgroundImage->ManualLoadImage(hWnd, L"Images\\SpaceBackground.jpg");
	/*m_pBackgroundObject = new CGameObject();
	m_pBackgroundObject->Initialize(m_pBackgroundImage, false);*/

	m_pBulletImage = new CImage(pDX2DFramework->GetD2DRenderTarget(), pDX2DFramework->GetImagingFactory(), 1);
	m_pBulletImage->ManualLoadImage(hWnd, L"Images\\bullet00.png");
	m_pBulletObject01 = new CGameObject();
	m_pBulletObject01->Initialize(m_pBulletImage, true);

	m_pBulletObject02 = new CGameObject();
	m_pBulletObject02->Initialize(m_pBulletImage, true);

	m_pBulletObject03 = new CGameObject();
	m_pBulletObject03->Initialize(m_pBulletImage, true);

	m_pBulletObject04 = new CGameObject();
	m_pBulletObject04->Initialize(m_pBulletImage, true);

	m_pBulletObject05 = new CGameObject();
	m_pBulletObject05->Initialize(m_pBulletImage, true);

	m_pBulletObject06 = new CGameObject();
	m_pBulletObject06->Initialize(m_pBulletImage, true);


	/*m_qBulletUnUse.push(m_pBulletObject);
	m_qBulletUnUse.push(m_pBulletObject);
	m_qBulletUnUse.push(m_pBulletObject);
	m_qBulletUnUse.push(m_pBulletObject);
	m_qBulletUnUse.push(m_pBulletObject);
	m_qBulletUnUse.push(m_pBulletObject);*/

	// =============collider================
	m_pPlayerBoxCollider = new CBoxCollider();
	m_pPlayerBoxCollider->InitCollider(&m_pPlayerObject->GetTransform(), SVector2(), m_pPlayerImage->GetImageSize());

	m_pPlayerRectCollider = new CRectCollider();
	m_pPlayerRectCollider->InitCollider(&m_pPlayerObject->GetTransform(), SVector2(), m_pPlayerImage->GetImageSize());

	m_pPlayerCircleCollider = new CCircleCollider();
	m_pPlayerCircleCollider->InitCollider(&m_pPlayerObject->GetTransform(), SVector2(), m_pPlayerImage->GetImageSize());

	m_pOpossumBoxCollider = new CBoxCollider();
	m_pOpossumBoxCollider->InitCollider(&m_pOpossumObject->GetTransform(), SVector2(), m_pOpossumImage->GetImageSize());
	m_pOpossumRectCollider = new CRectCollider();
	m_pOpossumRectCollider->InitCollider(&m_pOpossumObject->GetTransform(), SVector2(), m_pOpossumImage->GetImageSize());
	m_pEagleCircleCollider = new CCircleCollider();
	m_pEagleCircleCollider->InitCollider(&m_pEagleObject->GetTransform(), SVector2(), m_pEagleImage->GetImageSize());


	m_pBullet01BoxCollider = new CBoxCollider();
	m_pBullet01BoxCollider->InitCollider(&m_pBulletObject01->GetTransform(), SVector2(), m_pBulletImage->GetImageSize());

	m_pBullet01RectCollider = new CRectCollider();
	m_pBullet01RectCollider->InitCollider(&m_pBulletObject01->GetTransform(), SVector2(), m_pBulletImage->GetImageSize());
	// =====================================
}

void CMoveSampleScene::Release()
{
	m_pPlayerObject->Release();
	delete m_pPlayerObject;
	m_pOpossumObject->Release();
	delete m_pOpossumObject;
	m_pEagleObject->Release();
	delete m_pEagleObject;
	m_pCherryObject->Release();
	delete m_pCherryObject;
	m_pGemObject->Release();
	delete m_pGemObject;
	m_pItemEffectObject->Release();
	delete m_pItemEffectObject;
	m_pDeathEffectObject->Release();
	delete m_pDeathEffectObject;

	m_pBulletObject01->Release();
	delete m_pBulletObject01;
	m_pBulletObject02->Release();
	delete m_pBulletObject02;
	m_pBulletObject03->Release();
	delete m_pBulletObject03;

	m_pBulletObject04->Release();
	delete m_pBulletObject04;
	m_pBulletObject05->Release();
	delete m_pBulletObject05;
	m_pBulletObject06->Release();
	delete m_pBulletObject06;


	delete m_pPlayerImage;
	delete m_pOpossumImage;
	delete m_pEagleImage;
	delete m_pCherryImage;
	delete m_pGemImage;
	delete m_pItemEffectImage;
	delete m_pDeathEffectImage;
	delete m_pBackgroundImage;


	m_pColorBrushPalettet->Release();
	delete m_pColorBrushPalettet;


	delete m_pPlayerBoxCollider;
	delete m_pOpossumRectCollider;
	delete m_pEagleCircleCollider;

	delete m_pBullet01BoxCollider;
	delete m_pBullet01RectCollider;
}

void CMoveSampleScene::Update()
{
	// *** player 위치 설정, bullet 발사위치 설정
	static SVector2 vPlayerPos(150, 130);
	static SVector2 vBulletFirePos(3000, 2600);
	float fPlayerSpeed = 5;
	float fOpossumSpeed = 3;
	float fEangleSpeed = 5;
	//벡터방식 연산보다는 효률적이다.
	// *** 플레이어 이동을 제한
	if (CInputManager::GetAsyncKeyStatePress(VK_RIGHT))
	{
		vPlayerPos.x += fPlayerSpeed; //vPlayerPos = vPlayerPos + SVector2::right() * fPlayerSpeed;
		vBulletFirePos.x += fPlayerSpeed *20;
		if (vPlayerPos.x >= 320)
		{
			vPlayerPos.x = 320;
			vBulletFirePos.x = 6400;
		}
	}
	if (CInputManager::GetAsyncKeyStatePress(VK_LEFT))
	{
		vPlayerPos = vPlayerPos + SVector2::left() * fPlayerSpeed;//vPlayerPos.x -= fPlayerSpeed;
		vBulletFirePos = vBulletFirePos + SVector2::left() * fPlayerSpeed * 20;
		if (vPlayerPos.x <= 0)
		{
			vPlayerPos.x = 0;
			vBulletFirePos.x = 0;
		}
	}
	if (CInputManager::GetAsyncKeyStatePress(VK_DOWN))
		vPlayerPos = vPlayerPos + SVector2::down() * fPlayerSpeed;//vPlayerPos.y += fPlayerSpeed;
	if (CInputManager::GetAsyncKeyStatePress(VK_UP))
		vPlayerPos.y -= fPlayerSpeed;//vPlayerPos = vPlayerPos + SVector2::up() * fPlayerSpeed;

	static float fAngle = 0;
	{
		CTransform& cTrnasform = m_pPlayerObject->GetTransform();
		SVector2 vSize = m_pPlayerObject->GetImage()->GetImageSize();
		SVector2 vScale(4, 4);
		cTrnasform.SetTransrate(vPlayerPos);
		SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);
		cTrnasform.SetTRS(vPlayerPos, fAngle, vScale);
	}
	m_pPlayerObject->Update();

	// ==================bullet 컨트롤=========================
	
	BulletCreate(vBulletFirePos);

	// ======================================================

	static SVector2 vOpossumPos(300, 100);
	{
		CTransform& cTrnasform = m_pOpossumObject->GetTransform();
		SVector2 vSize = m_pOpossumObject->GetImage()->GetImageSize();
		SVector2 vScale(3, 3);
		cTrnasform.SetTransrate(vOpossumPos);
		SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);
		cTrnasform.SetTRS(vOpossumPos, 0, vScale);

		CTransform* cColTransform = new CTransform();
		cColTransform->SetAsixPoint(vAsix);
		cColTransform->SetTRS(vOpossumPos, 0, vScale);

		cColTransform->SetTransrate(SVector2(300, 300));
		m_pOpossumBoxCollider->InitCollider(&cTrnasform, SVector2(), m_pOpossumImage->GetImageSize());

		//m_pOpossumRectCollider->InitCollider(&cTrnasform, SVector2(vOpossumPos.x+100, vOpossumPos.y-100), m_pOpossumImage->GetImageSize(),20);

	}
	vOpossumPos = vOpossumPos + SVector2::left() * fOpossumSpeed;
	if (vOpossumPos.x <= 0)
		vOpossumPos.x = 300;
	m_pOpossumObject->Update();
	
	CCollisionCheck collision;
	

	static SVector2 vEaglePos(200, 0);
	{
		CTransform& cTrnasform = m_pEagleObject->GetTransform();
		SVector2 vSize = m_pEagleObject->GetImage()->GetImageSize();
		SVector2 vScale(5, 5);
		cTrnasform.SetTransrate(vEaglePos);
		SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);
		cTrnasform.SetTRS(vEaglePos, 0, vScale);

		//SVector2 vDir = vPlayerPos - vEaglePos;
		/*SVector2 vDir = vEaglePos - vPlayerPos;
		vDir = vDir.Normalize();
		vEaglePos = vEaglePos + vDir * fEangleSpeed;*/
	}
	m_pEagleObject->Update();

	m_pCherryObject->Update();
	m_pCherryObject->GetTransform().SetTransrate(0, 50);
	m_pGemObject->Update();
	m_pGemObject->GetTransform().SetTransrate(0, 80);
	m_pItemEffectObject->Update();
	m_pItemEffectObject->GetTransform().SetTransrate(0, 100);
	m_pDeathEffectObject->Update();
	m_pDeathEffectObject->GetTransform().SetTransrate(0, 120);
}

void CMoveSampleScene::Draw()
{
	ID2D1HwndRenderTarget* pRenderTarget = CSingletonRenderTarget::GetRenderTarget();

	SVector2 vBackgroundScale(1.4f, 1.3f);
	SVector2 vBackgroundPos(00, 00);
	//m_pBackgroundImage->DrawBitmap(vBackgroundPos, vBackgroundScale, 0, 0);

	m_pBulletObject01->Draw();
	m_pBulletObject02->Draw();
	m_pBulletObject03->Draw();


	m_pBulletObject04->Draw();
	m_pBulletObject05->Draw();
	m_pBulletObject06->Draw();

	m_pPlayerObject->Draw();

	m_pOpossumObject->Draw();

	m_pEagleObject->Draw();

	m_pCherryObject->Draw();
	m_pGemObject->Draw();

	m_pItemEffectObject->Draw();
	m_pDeathEffectObject->Draw();

	ColliderDraw();
}

void CMoveSampleScene::BulletCreate(SVector2 vBulletFirePos)
{
	float fBulletSpeed = 100;


	SVector2 vBulletScale(0.2f, 0.2f);
	static SVector2 vBulletPos01(vBulletFirePos.x, 2600);
	{
		CTransform& cTrnasform = m_pBulletObject01->GetTransform();
		SVector2 vSize = m_pBulletObject01->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos01);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos01, 0, vScale);
		//m_qBulletUnUse.pop();
	}
	vBulletPos01 = vBulletPos01 + SVector2::up() * fBulletSpeed;

	if (vBulletPos01.y <= 0)
	{
		vBulletPos01.x = vBulletFirePos.x;
		vBulletPos01.y = 2600;
	}

	static SVector2 vBulletPos02(vBulletFirePos.x, 3030);
	{
		CTransform& cTrnasform = m_pBulletObject02->GetTransform();
		SVector2 vSize = m_pBulletObject02->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos02);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos02, 0, vScale);
		//m_qBulletUnUse.pop();
	}
	vBulletPos02 = vBulletPos02 + SVector2::up() * fBulletSpeed;


	if (vBulletPos02.y <= 0)
	{
		vBulletPos02.x = vBulletFirePos.x;
		vBulletPos02.y = 2600;
	}

	static SVector2 vBulletPos03(vBulletFirePos.x, 3460);
	{
		CTransform& cTrnasform = m_pBulletObject03->GetTransform();
		SVector2 vSize = m_pBulletObject03->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos03);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos03, 0, vScale);
		//m_qBulletUnUse.pop();
	}
	vBulletPos03 = vBulletPos03 + SVector2::up() * fBulletSpeed;

	if (vBulletPos03.y <= 0)
	{
		vBulletPos03.x = vBulletFirePos.x;
		vBulletPos03.y = 2600;
	}

	static SVector2 vBulletPos04(vBulletFirePos.x, 3890);
	{
		CTransform& cTrnasform = m_pBulletObject04->GetTransform();
		SVector2 vSize = m_pBulletObject04->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos04);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos04, 0, vScale);
		//m_qBulletUnUse.pop();
	}
	vBulletPos04 = vBulletPos04 + SVector2::up() * fBulletSpeed;

	if (vBulletPos04.y <= 0)
	{
		vBulletPos04.x = vBulletFirePos.x;
		vBulletPos04.y = 2600;
	}

	static SVector2 vBulletPos05(vBulletFirePos.x, 4320);
	{
		CTransform& cTrnasform = m_pBulletObject05->GetTransform();
		SVector2 vSize = m_pBulletObject05->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos05);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos05, 0, vScale);
		//m_qBulletUnUse.pop();
	}
	vBulletPos05 = vBulletPos05 + SVector2::up() * fBulletSpeed;

	if (vBulletPos05.y <= 0)
	{
		vBulletPos05.x = vBulletFirePos.x;
		vBulletPos05.y = 2600;
	}

	static SVector2 vBulletPos06(vBulletFirePos.x, 4750);
	{
		CTransform& cTrnasform = m_pBulletObject06->GetTransform();
		SVector2 vSize = m_pBulletObject06->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos06);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos06, 0, vScale);
		//m_qBulletUnUse.pop();
	}
	vBulletPos06 = vBulletPos06 + SVector2::up() * fBulletSpeed;

	if (vBulletPos06.y <= 0)
	{
		vBulletPos06.x = vBulletFirePos.x;
		vBulletPos06.y = 2600;
	}


}

void CMoveSampleScene::CollisionCheckDraw()
{
	CDebugHelper::LogConsole("CollisionCheckProccess 1\n");
	CColorBrush* pRedBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::RED);
	CColorBrush* pGreenBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::GREEN);
	CColorBrush* pYellowBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::YELLOW);
	CColorBrush* pBlackBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::BLACK);

	SVector2 vPlayerSize = m_pPlayerObject->GetImage()->GetImageSize();
	SVector2 vPlayerSizeHalf = vPlayerSize * 0.5f;
	SVector2 vPlayerPos = m_pPlayerObject->GetTransform().GetTransrate();
	/*SVector2 vPlayerTopLeft = vPlayerPos;
	SVector2 vPlayerBottomRight = vPlayerPos + vPlayerSize;
	SVector2 vPlayerTopRight = SVector2(vPlayerTopLeft.x,vPlayerBottomRight.y);
	SVector2 vPlayerBottomLeft = SVector2(vPlayerBottomRight.x,vPlayerTopLeft.y);*/
	SVector2 vPlayerTopLeft = m_pPlayerBoxCollider->GetWorldTL();
	SVector2 vPlayerBottomRight = m_pPlayerBoxCollider->GetWorldBR();
	SVector2 vPlayerTopRight = m_pPlayerBoxCollider->GetWorldTR();
	SVector2 vPlayerBottomLeft = m_pPlayerBoxCollider->GetWorldBL();


	SVector2 vBulletSize = m_pBulletObject01->GetImage()->GetImageSize();
	SVector2 vBulletSizeHalf = vBulletSize * 0.5f;
	SVector2 vBulletPos = m_pBulletObject01->GetTransform().GetTransrate();

	SVector2 vBulletTopLeft = m_pBullet01BoxCollider->GetWorldTL();
	SVector2 vBulletBottomRight = m_pBullet01BoxCollider->GetWorldBR();
	SVector2 vBulletTopRight = m_pBullet01BoxCollider->GetWorldTR();
	SVector2 vBulletBottomLeft = m_pBullet01BoxCollider->GetWorldBL();



	/*SVector2 vOpossumSize = m_pOpossumObject->GetImage()->GetImageSize();
	SVector2 vOpossumPos = m_pOpossumObject->GetTransform().GetTransrate();
	SVector2 vOpossumTopLeft = vOpossumPos;
	SVector2 vOpossumBottomRight = vOpossumPos + vOpossumSize;*/

	SVector2 vEagleSize = m_pEagleObject->GetImage()->GetImageSize();
	SVector2 vEaglePos = m_pEagleObject->GetTransform().GetTransrate() + vEagleSize * 0.5f;
	float fEagleRad = vEagleSize.Magnitude() * 0.3f;

	//플레이어와 주머니쥐를 OBB로 놓고 계산하기
	SVector2 vOpossumTopLeft = m_pOpossumBoxCollider->GetWorldTL();
	SVector2 vOpossumTopRight = m_pOpossumBoxCollider->GetWorldTR();
	SVector2 vOpossumBottomRight = m_pOpossumBoxCollider->GetWorldBR();
	SVector2 vOpossumBottomLeft = m_pOpossumBoxCollider->GetWorldBL();


	CDebugHelper::LogConsole("CollisionCheckProccess 2\n");
}



void CMoveSampleScene::ColliderDraw()
{
	CColorBrush* pRedBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::RED);
	CColorBrush* pGreenBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::GREEN);
	CColorBrush* pYellowBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::YELLOW);
	CColorBrush* pBlackBrush = m_pColorBrushPalettet->GetBrushClass(CColorBrushPalettet::BLACK);

	////플레이어 충돌테스트
	//if (m_pPlayerBoxCollider->ToRect(m_pOpossumRectCollider))
	//	m_pPlayerBoxCollider->DrawOutline(pRedBrush);
	//else
	//	m_pPlayerBoxCollider->DrawOutline(pBlackBrush);

	//if (m_pPlayerBoxCollider->ToBox(m_pOpossumBoxCollider))
	//	m_pPlayerBoxCollider->DrawOutline(pRedBrush);
	//else
	//	m_pPlayerBoxCollider->DrawOutline(pBlackBrush);

	//if(m_pPlayerBoxCollider->ToCircle(m_pEagleCircleCollider))
	//	m_pPlayerBoxCollider->DrawOutline(pRedBrush);
	//else
	//	m_pPlayerBoxCollider->DrawOutline(pBlackBrush);
	//m_pPlayerBoxCollider->DrawOutline(pBlackBrush);

	//주머니쥐 충돌테스트
	if (m_pOpossumBoxCollider->ToRect(m_pPlayerRectCollider))
		m_pOpossumBoxCollider->DrawOutline(pRedBrush);
	else
		m_pOpossumBoxCollider->DrawOutline(pBlackBrush);

	if (m_pOpossumBoxCollider->ToBox(m_pPlayerBoxCollider))
		m_pOpossumBoxCollider->DrawOutline(pRedBrush);
	else
		m_pOpossumBoxCollider->DrawOutline(pBlackBrush);

	if (m_pOpossumBoxCollider->ToCircle(m_pEagleCircleCollider))
		m_pOpossumBoxCollider->DrawOutline(pRedBrush);
	else
		m_pOpossumBoxCollider->DrawOutline(pBlackBrush);





	if (m_pOpossumBoxCollider->ToRect(m_pBullet01RectCollider))
		m_pOpossumBoxCollider->DrawOutline(pRedBrush);
	else
		m_pOpossumBoxCollider->DrawOutline(pBlackBrush);

	//if (m_pOpossumBoxCollider->ToBox(m_pBullet01BoxCollider))
	//	m_pOpossumBoxCollider->DrawOutline(pRedBrush);
	//else
	//	m_pOpossumBoxCollider->DrawOutline(pBlackBrush);

	if (m_pOpossumBoxCollider->ToCircle(m_pEagleCircleCollider))
		m_pOpossumBoxCollider->DrawOutline(pRedBrush);
	else
		m_pOpossumBoxCollider->DrawOutline(pBlackBrush);

	//m_pOpossumBoxCollider->DrawOutline(pBlackBrush);

	////독수리 충돌테스트
	//if(m_pEagleCircleCollider->ToRect(m_pOpossumRectCollider))
	//	m_pEagleCircleCollider->DrawOutline(pBlackBrush);
	//else
	//	m_pEagleCircleCollider->DrawOutline(pRedBrush);

	//if (m_pEagleCircleCollider->ToBox(m_pPlayerBoxCollider))
	//	m_pEagleCircleCollider->DrawOutline(pBlackBrush);
	//else
	//	m_pEagleCircleCollider->DrawOutline(pRedBrush);

	//if(m_pEagleCircleCollider->ToCircle(m_pPlayerCircleCollider))
	//	m_pEagleCircleCollider->DrawOutline(pBlackBrush);
	//else
	//	m_pEagleCircleCollider->DrawOutline(pRedBrush);

	//m_pEagleCircleCollider->DrawOutline(pBlackBrush);
}