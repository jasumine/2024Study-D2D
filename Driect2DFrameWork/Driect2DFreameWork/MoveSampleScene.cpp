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
	m_pBulletObject01->SetUseTrue();

	m_pBulletObject02 = new CGameObject();
	m_pBulletObject02->Initialize(m_pBulletImage, true);
	m_pBulletObject02->SetUseTrue();

	m_pBulletObject03 = new CGameObject();
	m_pBulletObject03->Initialize(m_pBulletImage, true);
	m_pBulletObject03->SetUseTrue();
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
}

void CMoveSampleScene::Update()
{
	// *** player 위치 설정, bullet 발사위치 설정
	static SVector2 vPlayerPos(150,130);
	static SVector2 vBulletFirePos(3000, 2600);
	float fPlayerSpeed = 5;
	float fOpossumSpeed = 3;
	float fEangleSpeed = 5;
	float fBulletSpeed = 100;
	float fBulletReload = 3;
	//벡터방식 연산보다는 효률적이다.
	// *** 플레이어 이동을 제한
	if (CInputManager::GetAsyncKeyStatePress(VK_RIGHT))
	{
		vPlayerPos.x += fPlayerSpeed; //vPlayerPos = vPlayerPos + SVector2::right() * fPlayerSpeed;
		vBulletFirePos.x += fPlayerSpeed*20;
		if (vPlayerPos.x >= 320)
		{
			vPlayerPos.x = 320;
		}
	}
	if (CInputManager::GetAsyncKeyStatePress(VK_LEFT))
	{
		vPlayerPos = vPlayerPos + SVector2::left() * fPlayerSpeed;//vPlayerPos.x -= fPlayerSpeed;
		vBulletFirePos = vBulletFirePos + SVector2::left() * fPlayerSpeed*20;
		if (vPlayerPos.x <= 0)
		{
			vPlayerPos.x = 0;
		}
	}
	//if (CInputManager::GetAsyncKeyStatePress(VK_DOWN))
	//	vPlayerPos = vPlayerPos + SVector2::down() * fPlayerSpeed;//vPlayerPos.y += fPlayerSpeed;
	//if (CInputManager::GetAsyncKeyStatePress(VK_UP))
	//	vPlayerPos.y -= fPlayerSpeed;//vPlayerPos = vPlayerPos + SVector2::up() * fPlayerSpeed;

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
	SVector2 vBulletScale(0.2f, 0.2f);
	static SVector2 vBulletPos(vBulletFirePos.x , 2600);
	{
		CTransform& cTrnasform = m_pBulletObject01->GetTransform();
		SVector2 vSize = m_pBulletObject01->GetImage()->GetImageSize();
		SVector2 vScale(vBulletScale);
		cTrnasform.SetTransrate(vBulletPos);
		//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
		/*SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);*/
		cTrnasform.SetTRS(vBulletPos, 0, vScale);
		m_pBulletObject01->SetUseFalse();
	}
	vBulletPos = vBulletPos + SVector2::up() * fBulletSpeed;
		m_pBulletObject01->Update();

	//SVector2 vBulletScale(0.2f, 0.2f);
	//SVector2 vBulletPos(vBulletFirePos);
	//if (m_pBulletObject01->GetUse() == true)
	//{
	//	CTransform& cTrnasform = m_pBulletObject01->GetTransform();
	//	SVector2 vSize = m_pBulletObject01->GetImage()->GetImageSize();
	//	SVector2 vScale(vBulletScale);
	//	cTrnasform.SetTransrate(vBulletPos);
	//	//m_pBulletObject->SetVector(vBulletPos, vBulletScale);
	//	/*SVector2 vAsix = vSize * 0.5f;
	//	cTrnasform.SetAsixPoint(vAsix);*/
	//	cTrnasform.SetTRS(vBulletFirePos, 0, vScale);
	//	m_pBulletObject01->SetUseFalse();
	//}
	//else
	//{
	//	vBulletFirePos = vBulletFirePos + SVector2::up() * fBulletSpeed;
	//	if (vBulletPos.y <= 0) m_pBulletObject01->SetUseTrue();
	//	m_pBulletObject01->Update();
	//}
	// ======================================================

	static SVector2 vOpossumPos(1000, 0);
	{
		CTransform& cTrnasform = m_pOpossumObject->GetTransform();
		SVector2 vSize = m_pOpossumObject->GetImage()->GetImageSize();
		SVector2 vScale(1, 1);
		cTrnasform.SetTransrate(vOpossumPos);
		SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);
		cTrnasform.SetTRS(vOpossumPos, 0, vScale);
	}
	vOpossumPos = vOpossumPos + SVector2::left() * fOpossumSpeed;
	m_pOpossumObject->Update();

	static SVector2 vEaglePos(1000, 500);
	{
		CTransform& cTrnasform = m_pEagleObject->GetTransform();
		SVector2 vSize = m_pEagleObject->GetImage()->GetImageSize();
		SVector2 vScale(1, 1);
		cTrnasform.SetTransrate(vEaglePos);
		SVector2 vAsix = vSize * 0.5f;
		cTrnasform.SetAsixPoint(vAsix);
		cTrnasform.SetTRS(vEaglePos, 0, vScale);

		//SVector2 vDir = vPlayerPos - vEaglePos;
		SVector2 vDir = vEaglePos - vPlayerPos;
		vDir = vDir.Normalize();
		vEaglePos = vEaglePos + vDir * fEangleSpeed;
	}
	m_pEagleObject->Update();



	//m_pBackgroundObject->GetTransform().SetTransrate(50, 50);
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
	m_pBackgroundImage->DrawBitmap(vBackgroundPos, vBackgroundScale, 0, 0);

	m_pBulletObject01->Draw();
	m_pBulletObject02->Draw();
	m_pBulletObject03->Draw();

	m_pPlayerObject->Draw();

	m_pOpossumObject->Draw();

	m_pEagleObject->Draw();

	m_pCherryObject->Draw();
	m_pGemObject->Draw();

	m_pItemEffectObject->Draw();
	m_pDeathEffectObject->Draw();

}