#include "StdAfx.h"
#include "Game.h"



CGame::CGame(void)
{
	bThirdPerson = false;
	iPointsPlayerLeft = 10;
	iPointsPlayerRight = 10;
	bSupplyActivated = false;
	fSupSatRadius = 5.0f;
	fTimer = 0.0f;
	iCounterLeft = 0;
	for (int i = 0; i < 20; i++)
	{
		m_zpMissileLeft[i].SwitchOff();
	}
	m_zpExplosion.SwitchOff();
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	srand(time(NULL));
	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	m_zr.Init(psplash);
	//m_zc.Init(QUARTERPI);
	//Kameras für Viewports
	m_zcLeftScreen.Init(QUARTERPI);
	m_zcRightScreen.Init(QUARTERPI);
	//
	m_zf.Init(hwnd, procOS); 
	//m_zv.InitFull(&m_zc);

	//Materialien für Satellit
	m_zr.AddMaterial(&m_zmSupSatNotActivated);
	m_zr.AddMaterial(&m_zmSupSatActivated);
	//Splitscreen
	m_zvLeftScreen.Init(&m_zcLeftScreen, 0.0f, 0.0f, 0.5f, 1.0f);
	m_zvRightScreen.Init(&m_zcRightScreen, 0.5f, 0.0f, 0.5f, 1.0f);
	//Writings Punkteanzeige
	m_zwFPunkteanzeige.LoadPreset("OCRAExtendedWhite");
	m_zwPunkteanzeigeLeft.Init(CFloatRect(0.01f, 0.01f, 0.5f, 0.1f), 12, &m_zwFPunkteanzeige);
	m_zvLeftScreen.AddWriting(&m_zwPunkteanzeigeLeft);
	m_zwPunkteanzeigeRight.Init(CFloatRect(0.01f, 0.01f, 0.5f, 0.1f), 12, &m_zwFPunkteanzeige);
	m_zvRightScreen.AddWriting(&m_zwPunkteanzeigeRight);

	//Overlay Loser/Winner
	m_zmOverlayWinner.MakeTextureGlow("textures\\Winner.png");
	m_zmOverlayLoser.MakeTextureGlow("textures\\LoserRot.jpg");
	m_zoWinner.Init(&m_zmOverlayWinner, CFloatRect(0.15f, 0.25f, 0.7f, 0.2f));
	m_zoLoser.Init(&m_zmOverlayLoser, CFloatRect(0.15f, 0.25f, 0.7f, 0.2f));

	m_zs.SetLightAmbient(CColor(0.2f, 0.2f, 0.2f));

	//m_zl.Init(CHVector(1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));
	m_zl.Init(CHVector(-1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));
	m_zb.InitFull("textures\\Galaxietextur.jpg");
	m_zgSphere.Init(1.5F, &m_zm, 50, 50);

	//Wolken
	m_zgWolkenSphere.Init(1.55F, &m_zmWolkenMaterial, 50, 50);
	m_zpWolkenSphere.FixDistance(0.1F);

	//Mond
	m_zgMondSphere.Init(0.35F, &m_zmMondMaterial, 50, 50);

	//Sonne
	m_zgSonneSphere.Init(5.0F, &m_zmSonneMaterial, 50, 50);

	m_zm.MakeTextureDiffuse("textures\\Erdentextur.jpg");

	//Todesstern
	m_zgTodessternSphere.Init(2.5F, &m_zmTodessternMaterial, 50, 50);

	//Raketen
	m_zgRakete.SetMaterial(&m_zmRakete);
	m_zgRaketePlayer2.SetMaterial(&m_zmRaketePlayer2);

	//SkyCube
	m_zgSkyCube.Init(CHVector(200.0f, 200.0f, 200.0f), &m_zmSkyCube, 4, false);

	//Sonnenlicht
	m_zlSunlight.Init(CColor(1.0f, 1.0f, 0.8f), 2.0f * PI / 180, 8.97f * PI / 180, 0.6f);
	m_zlSunlight.SetMinDistance(2.5f);
	m_zlSunlight.SetMaxDistance(30.0f);
	m_zlSunlight.SetShadowMapResolution(1024, 1024);
	m_zlSunlight.SetShadowOn();

	//Materialien
	m_zmWolkenMaterial.MakeTextureDiffuse("textures\\Earth_CloudsL3.gif");
	m_zmWolkenMaterial.SetTransparencyOn();
	m_zmMondMaterial.MakeTextureDiffuse("textures\\MondTextur.jpg"); //Mond_Material
	m_zmSonneMaterial.MakeTextureDiffuse("textures\\Sonnetextur.jpg"); //Sonne_Material
	m_zmSonneMaterial.MakeTextureGlow("textures\\Sonnetextur.jpg");
	m_zmSonneMaterial.SetGlowEverywhere();
	m_zmTodessternMaterial.MakeTextureDiffuse("textures\\Todesstern_Textur.jpg");

	m_zmRed.LoadPreset("Blood");
	m_zmSatellit.MakeTextureDiffuse("textures\\Metalltextur.jpg");
	m_zmPunktwolke.LoadPreset("Quicksilver");// Material für die Punktwolke
	m_zmLinien.MakeTextureDiffuse("textures\\yellow_image.jpg");
	m_zmLinien.MakeTextureGlow("textures\\yellow_image.jpg"); //Material für das Sternenbild
	m_zmLinien.SetGlowEverywhere();
	m_zmRakete.MakeTextureGlow("textures\\rakete.jpg");
	m_zmRaketePlayer2.MakeTextureGlow("textures\\rakete.jpg");

	//SupSatellit Material
	m_zmSupSatNotActivated.MakeTextureGlow("textures\\white_image.jpg");
	//m_zmSupSatNotActivated.LoadPreset("MetalRustyFlaking");
	m_zmSupSatActivated.MakeTextureGlow("textures\\yellow_image.jpg");
	//m_zmSupSatActivated.LoadPreset("Blood");

	//SkyCube
	m_zmSkyCube.MakeTextureSky("textures\\UniversumTextur.jpg");

	m_zPunkteListe.SetMaterial(&m_zmPunktwolke);
	m_zLineListe.SetMaterial(&m_zmLinien);

	m_zr.AddMaterial(&m_zmRed);
	m_zr.AddFrameHere(&m_zf);
	//m_zf.AddViewport(&m_zv);
	//Splitscreen
	m_zf.AddViewport(&m_zvLeftScreen);
	m_zf.AddViewport(&m_zvRightScreen);

	m_zf.AddDeviceKeyboard(&m_zdk);
	m_zf.AddDeviceCursor(&m_zdc);
	m_zf.AddDeviceGameController(&m_zdController);
	m_zf.AddDeviceGameController(&m_zdControllerPlayer2);

	//m_zv.AddBackground(&m_zb);
	m_zvLeftScreen.SetBackfaceCullingOff();
	m_zvRightScreen.SetBackfaceCullingOff();
	m_zr.AddScene(&m_zs);
	

	m_zs.AddPlacement(&m_zpSphere);
	m_zs.AddPlacement(&m_zpCameraLeft);
	m_zs.AddPlacement(&m_zpCameraRight);
	//m_zpRakete.AddPlacement(&m_zpCamera);
	//Placement der Raketen mit Kameras
	m_zpCameraLeft.AddPlacement(&m_zpRakete);
	m_zpCameraRight.AddPlacement(&m_zpRaketePlayer2);
	//
	m_zs.AddPlacement(&m_zpWolkenSphere); //Wolken
	m_zs.AddPlacement(&m_zpMondSphere); //Mond
	m_zs.AddPlacement(&m_zpSonneSphere); //Sonne
	m_zs.AddPlacement(&m_zpTodessternSphere); //Todesstern
	m_zs.AddPlacement(&m_zpPunktwolke);//Punktwolke
	//m_zs.AddPlacement(&m_zpRakete); //Rakete
	m_zgs.Add(&m_zgTodessternSphere); //Hinzufügen von dem Todesstern zum Geometrie Container
	m_zs.AddLightParallel(&m_zl);
	m_zs.AddPlacement(&m_zpSkyCube); //SkyCube
	m_zs.AddPlacement(&m_zpSunlight);
	//Splitscreen
	//m_zs.AddPlacement(&m_zpCameraLeft);
	//m_zs.AddPlacement(&m_zpCameraRight);
	//


	m_zpSunlight.AddLightSpot(&m_zlSunlight); //Sonnenlicht
	//m_zpCamera.AddCamera(&m_zc);
	//
	m_zpCameraLeft.AddCamera(&m_zcLeftScreen);
	m_zpCameraRight.AddCamera(&m_zcRightScreen);
	//m_zpCameraLeft.RotateY(180 * PI / 180);
	//m_zpCameraLeft.TranslateZDelta(-20.0f);
	m_zpCameraRight.RotateYDelta(180 * PI / 180);
	//m_zpCameraRight.TranslateZDelta(-20.0f);
	//
	m_zpSphere.AddGeo(&m_zgSphere);
	m_zpWolkenSphere.AddGeo(&m_zgWolkenSphere); //Wolken
	m_zpMondSphere.AddGeo(&m_zgMondSphere); //Mond
	m_zpSonneSphere.AddGeo(&m_zgSonneSphere);
	m_zpTodessternSphere.AddGeo(&m_zgTodessternSphere);
	m_zpPunktwolke.AddGeo(&m_zPunkteListe);
	m_zpRakete.AddGeo(&m_zgRakete); //Rakete 1
	m_zpRaketePlayer2.AddGeo(&m_zgRaketePlayer2); //Rakete 2
	m_zpSkyCube.SetSky();
	m_zpSkyCube.AddGeo(&m_zgSkyCube); //SkyCube

	//Missiles
	/*m_zmMissiles.MakeTextureGlow("textures\\blue_image.jpg");
	m_zmMissilesPlayer2.MakeTextureGlow("textures\\red_image.jpg");
	m_zgMissiles.Init(0.1f, &m_zmMissiles, 50, 50);
	m_zgMissilesPlayer2.Init(0.1f, &m_zmMissilesPlayer2, 50, 50);
	m_zpMissiles.AddGeo(&m_zgMissiles);
	m_zpMissilesPlayer2.AddGeo(&m_zgMissilesPlayer2);
	m_zpMissiles.AddEmitter(&m_zeMissiles);
	m_zpMissilesPlayer2.AddEmitter(&m_zeMissilesPlayer2);
	m_zpRakete.AddPlacement(&m_zpMissiles);
	m_zpRaketePlayer2.AddPlacement(&m_zpMissilesPlayer2);*/
	//
	//m_zpRakete.TranslateZ(-10.0f);
	//m_zpRakete.TranslateYDelta(5.0f);
	//m_zpSatellit[5].AddGeo(pzgSatellit);
	//Satelliten
	for (int i = 0; i < 5; i++)
	{
		m_zs.AddPlacement(&m_zpSatellit[i]);
		m_zpSatellit[i].AddGeo(&m_zgSatellit[i]);
		m_zgSatellit[i].SetMaterial(&m_zmSatellit);
		m_zpSatellit[i].Scale(0.5f);


		m_zpSatellit[i].RotateXDelta(rand() % 100 + 1);
		m_zpSatellit[i].RotateYDelta(rand() % 100 + 1);

		m_zpSatellit[i].TranslateXDelta(rand() % 10 + 10);
		m_zpSatellit[i].TranslateYDelta(rand() % 10 + 10);
	}

	//m_zpCamera.TranslateZ(8.0f);
	/*m_zpSatellit[5].TranslateZDelta(-9.5f);
	m_zpSatellit[5].ScaleDelta(0.5f);
	m_zpSatellit[5].TranslateZDelta(9.5f);*/
	//m_zpCamera.TranslateZ(100.0f);
	//m_zpCamera.RotateYDelta(180 * PI / 180);
	//m_zpCamera.TranslateZDelta(8.5f);

	//m_zpRakete.RotateYDelta(180 * PI / 180);

	m_zpRakete.Scale(0.1f); //Scale der Rakete 1
	m_zpRaketePlayer2.Scale(0.1f); //Scale der Rakete 2

	m_zpRakete.RotateXDelta(180 * PI / 180);
	m_zpRaketePlayer2.RotateYDelta(180 * PI / 180);

	m_zpCameraLeft.TranslateZ(15.4f);
	m_zpCameraRight.TranslateZDelta(-15.4f);
	m_zpRakete.TranslateZDelta(-1.0f);
	m_zpRakete.TranslateYDelta(-0.4f);
	m_zpRaketePlayer2.TranslateZDelta(-1.0f);
	m_zpRaketePlayer2.TranslateYDelta(-0.4f);

	m_zpCameraLeft.SetTranslationSensitivity(5.0f);
	m_zpCameraRight.SetTranslationSensitivity(5.0f);
	m_zpSphere.RotateZ(24.0f * PI / 180);

	m_zpTodessternSphere.TranslateDelta(CHVector(-20.0f, 10.0f,10.0f));

	//m_zpRakete.TranslateXDelta(20.0f); //Raketenverschiebung

	//Sternen Himmel
	for (int i = 0; i < 2500; i++)
	{
		CHVector vPos = CHVector(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50, 1.0f);
		CHVector vNormal = vPos;
		vNormal.Normal();
		CHVector vTangente = CHVector(0.0f, 1.0f, 0.0f, 0.0f);

		m_zVertex[i].Init(vPos, vNormal, vTangente, 0.0f, 0.0f);
		m_zPunkteListe.AddVertex(&m_zVertex[i]);
	}

	for (int i = 0; i<6; i++)
	{
		//Sternbild ab hier
		m_zLineListe.AddVertex(&m_zVertex[i]);
		if (i>0 && i <5)
		{
			m_zLineListe.AddVertex(&m_zVertex[i]);
		}
		if (i == 5)
		{
			m_zLineListe.AddVertex(&m_zVertex[5]);
			m_zLineListe.AddVertex(&m_zVertex[0]);

		}
		//Bis hier
	}

	m_zLineListe.Init();
	m_zPunkteListe.Init();

	//Verschieben des Spotlights
	m_zpSunlight.TranslateX(5.5f);

	//Missile Geo
	m_zgMissile.Init(0.1f, &m_zmRed, 50, 50);
	m_zpMissile.AddGeo(&m_zgMissile);
	for (int i = 0; i < 20; i++)
	{
		m_zs.AddPlacement(&m_zpMissileLeft[i]);
		m_zpMissileLeft[i].AddGeo(&m_zgMissile);
		cSchussVektor[i] = CHVector(0.0, 0.0, 0.0, 1.0f);
		cMissileLeftSpaceRight[i] = CHVector(10.0, 10.0, 10.0, 1.0f);

	}

	//Sound





	m_zaBackgroundMugge.Init("sounds\\test.wav");
	m_zaLaser.Init3D("sounds\\laser1.wav", 10.0f);
	m_zpRakete.AddAudio(&m_zaLaser);
	m_zs.AddAudio(&m_zaBackgroundMugge);
	m_zaBackgroundMugge.Loop();

	//Explosion
	m_zmExplo.MakeTextureSprite("explosions-pack\\explosion-6.png");
	m_zmExplo.SetBot(8, 1);
	m_zpExplosion.SetBillboard();
	m_zgExplosion.Init(1.0f, &m_zmExplo);
	m_zpExplosion.AddGeo(&m_zgExplosion);
	m_zs.AddPlacement(&m_zpExplosion);

}


void CGame::Tick(float fTime, float fTimeDelta)
{

	// Hier die Echtzeit-Veränderungen einfügen:
	m_zdk.PlaceWASD(m_zpCameraLeft, fTimeDelta);
	//m_zdk.PlaceWASD(m_zpCameraRight, fTimeDelta);
	m_zr.Tick(fTimeDelta);
	m_zpSphere.RotateY(fTimeDelta * 0.2f);
	m_zpSphere.TranslateXDelta(15.0f);
	m_zpSphere.RotateYDelta(fTime * 0.2f);

	m_zpWolkenSphere.RotateY(fTime * 0.5f);
	m_zpWolkenSphere.RotateXDelta(fTime * 0.01f);
	m_zpWolkenSphere.TranslateXDelta(15.0f);
	m_zpWolkenSphere.RotateYDelta(fTime * 0.2f);

	m_zpMondSphere.TranslateX(5.0f);
	m_zpMondSphere.RotateYDelta(fTime * 0.2f);
	m_zpMondSphere.TranslateXDelta(15.0f);
	m_zpMondSphere.RotateYDelta(fTime * 0.2f);

	//Tobi's Super Duper Code
	/*
	if (m_zdk.KeyPressed(DIK_Y))
	{
		m_zc.SetFov(m_zc.m_faFovHorizontal + fTimeDelta);
	}
	*/

	if (m_zdk.KeyDown(DIK_Y))
	{
		m_zc.SetFov(30.0f * PI / 180);
	}
	else if (m_zdk.KeyUp(DIK_Y))
	{
		m_zc.SetFov(45.0f * PI / 180);
	}

	if (m_zdc.ButtonDownLeft())
	{
		CGeo * pzg = m_zdc.PickGeoPreselected(m_zgs);
		if (pzg)
		{
			pzg->SetMaterial(&m_zmRed);
		}
	}

	//Controller
	if (m_zdController.ButtonPressed(1))
	{
		m_zpCameraLeft.TranslateXDelta(m_zcLeftScreen.m_faFovVertical - fTimeDelta);
	}

	if (m_zdController.ButtonPressed(2))
	{
		m_zpCameraLeft.TranslateXDelta(-(m_zcLeftScreen.m_faFovVertical - fTimeDelta));
	}

	if (m_zdController.ButtonPressed(3))
	{
		m_zpCameraLeft.TranslateYDelta(m_zcLeftScreen.m_faFovHorizontal - fTimeDelta);
	}

	if (m_zdController.ButtonPressed(0))
	{
		m_zpCameraLeft.TranslateYDelta(-(m_zcLeftScreen.m_faFovHorizontal - fTimeDelta));
	}

	if (m_zdController.ButtonPressed(4))
	{
		m_zcLeftScreen.SetFov(m_zcLeftScreen.m_faFovHorizontal + fTimeDelta);
	}

	if (m_zdController.ButtonPressed(5))
	{
		m_zcLeftScreen.SetFov(m_zcLeftScreen.m_faFovHorizontal - fTimeDelta);
	}

	//Controller Player 2

	if (m_zdControllerPlayer2.ButtonPressed(1))
	{
		m_zpCameraRight.TranslateXDelta(m_zcRightScreen.m_faFovVertical - fTimeDelta);
	}

	if (m_zdControllerPlayer2.ButtonPressed(2))
	{
		m_zpCameraRight.TranslateXDelta(-(m_zcRightScreen.m_faFovVertical - fTimeDelta));
	}

	if (m_zdControllerPlayer2.ButtonPressed(3))
	{
		m_zpCameraRight.TranslateYDelta(m_zcRightScreen.m_faFovHorizontal - fTimeDelta);
	}

	if (m_zdControllerPlayer2.ButtonPressed(0))
	{
		m_zpCameraRight.TranslateYDelta(-(m_zcRightScreen.m_faFovHorizontal - fTimeDelta));
	}

	if (m_zdControllerPlayer2.ButtonPressed(4))
	{
		m_zcRightScreen.SetFov(m_zcRightScreen.m_faFovHorizontal + fTimeDelta);
	}

	if (m_zdControllerPlayer2.ButtonPressed(5))
	{
		m_zcRightScreen.SetFov(m_zcRightScreen.m_faFovHorizontal - fTimeDelta);
	}


	if (m_zdk.KeyDown(DIK_F2))
	{
		m_zpPunktwolke.AddGeo(&m_zLineListe);
	}
	/*m_zpCamera.TranslateZDelta(100.0f);
	m_zpCamera.RotateYDelta(m_zdController.GetRelativeX()*(0.01));
	m_zpCamera.RotateXDelta(m_zdController.GetRelativeY()*(0.01));
	m_zpCamera.TranslateZDelta(-100.0f);*/

	//Steuerung Rakete Kamera Ego
	if (m_zdk.KeyDown(DIK_F1))
	{
		if (bThirdPerson)
		{
			m_zpCameraLeft.TranslateYDelta(5.0f);
			m_zpCameraLeft.TranslateZDelta(11.4f);
			m_zpRakete.TranslateZDelta(-30.4f);
			m_zpRakete.TranslateYDelta(-5.4f);
			bThirdPerson = false;
		}
	}

	if (m_zdk.KeyDown(DIK_F3))
	{
		if (bThirdPerson == false)
		{
			m_zpCameraLeft.TranslateYDelta(-5.0f);
			m_zpCameraLeft.TranslateZDelta(-11.4f);
			m_zpRakete.TranslateZDelta(30.4f);
			m_zpRakete.TranslateYDelta(5.4f);
			bThirdPerson = true;
		}
	}
	
	for (int i = 0; i < 5; i++)
	{
		m_zpSatellit[i].RotateZDelta(fTimeDelta * 0.1f);
		m_zpSatellit[i].RotateYDelta(fTimeDelta * 0.1f);
	}

	//Sunlight auf Erde setzen
	m_zpSunlight.RotateYDelta(fTimeDelta * 0.2f);
	m_zpSunlight.SetPointing(&m_zpSphere);

	//Punkteanzeige
	m_zwPunkteanzeigeLeft.PrintF("Punkte: %i", iPointsPlayerLeft);
	m_zwPunkteanzeigeRight.PrintF("Punkte: %i", iPointsPlayerRight);

	if (iPointsPlayerLeft == 0)
	{
		m_zvLeftScreen.AddOverlay(&m_zoLoser);
		m_zvRightScreen.AddOverlay(&m_zoWinner);
	}
	else if (iPointsPlayerRight == 0)
	{
		m_zvLeftScreen.AddOverlay(&m_zoWinner);
		m_zvRightScreen.AddOverlay(&m_zoLoser);
	}

	// --------------------- Sup Sat ---------------------
	CHVector cSupSatPos, cCamLeftPos, cCamRightPos, cSupplySpaceship1, cSupplySpaceship2;
	cSupSatPos = m_zpSatellit[0].GetPos();
	cCamLeftPos = m_zpCameraLeft.GetPos();
	cCamRightPos = m_zpCameraRight.GetPos();
	cSupplySpaceship1 = cCamLeftPos - cSupSatPos;
	cSupplySpaceship2 = cCamRightPos - cSupSatPos;
	float fDistanceShip1 = cSupplySpaceship1.Length() - 1.0f;
	float fDistanceShip2 = cSupplySpaceship2.Length() - 1.0f;

	//Aktivierung/Deaktivierung des Satelliten
	if (!bSupplyActivated)
	{
		fTimer -= fTimeDelta;
		m_zgSatellit[0].SetMaterial(&m_zmSupSatNotActivated);
		if (fTimer <= 0.0f)
		{
			bSupplyActivated = true;
			fTimer = 60.0f;
			m_zgSatellit[0].SetMaterial(&m_zmSupSatActivated);
		}
	}
	else
	{
		if (fDistanceShip1 <= fSupSatRadius)
		{
			iPointsPlayerLeft += 10;
			bSupplyActivated = false;
		}

		if (fDistanceShip2 <= fSupSatRadius)
		{
			iPointsPlayerRight += 10;
			bSupplyActivated = false;
		
		}
	}

	//Missile
 

	static bool bHitRight = false;
	static float fTimeExpl = -1;


	if(m_zdk.KeyDown(DIK_SPACE)){
		m_zaLaser.Start();
		m_zpMissileLeft[iCounterLeft].SwitchOn();
//		m_zs.AddPlacement(&m_zpMissileLeft[iCounterLeft]);
		m_zpMissileLeft[iCounterLeft].Translate(m_zpRakete.m_anodeinstance[0].m_mGlobal.GetPos());

		cSchussVektor[iCounterLeft] = m_zpCameraLeft.GetDirection();
		iCounterLeft =(iCounterLeft+ 1) % 20;
	}
		for (int i = 0; i < 20; i++) {
			if(m_zpMissileLeft[i].IsOn()){
				m_zpMissileLeft[i].TranslateDelta(cSchussVektor[i] * 50.0f * fTimeDelta);
				cMissileLeftSpaceRight[i] = m_zpMissileLeft[i].GetPos() - m_zpRaketePlayer2.m_anodeinstance[0].m_mGlobal.GetPos();
			}
			if (m_zpMissileLeft[i].IsOn()) {
				if (cMissileLeftSpaceRight[i].Length() <= 0.5f) {
					iPointsPlayerRight--;
					iPointsPlayerLeft++;
					m_zpMissileLeft[i].SwitchOff();
					m_zpExplosion.SwitchOn();
					fTimeExpl = 0.0F;
					m_zpExplosion.Translate(m_zpMissileLeft[i].GetPos());
				

				}
			}
			if (cMissileLeftSpaceRight[i].Length() > 500.0f)
				m_zpMissileLeft[i].SwitchOff();
		}
		if (m_zpExplosion.IsOn()) {
			int iExplFrame = (int)(fTimeExpl * 12.0f);
			fTimeExpl += fTimeDelta;

			m_zmExplo.SetPic(iExplFrame, 0);
			if (iExplFrame >= 8)
			{
				m_zpExplosion.SwitchOff();
				iExplFrame = -1;
			}
		}
		//m_zpMissile.TranslateDelta(cSchussVektor * 50.0f * fTimeDelta);

	//cMissileLeftSpaceRight = m_zpMissile.GetPos() - m_zpRaketePlayer2.m_anodeinstance[0].m_mGlobal.GetPos();



}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	m_zf.ReSize(iNewWidth, iNewHeight);
}

