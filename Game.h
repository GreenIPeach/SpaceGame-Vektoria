#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#pragma comment (lib, "ApiUtils_Debug64.lib")
#pragma comment (lib, "ApiNullRenderer_Debug64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug64.lib")
#pragma comment (lib, "ApiDirectInput08_Debug64.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug64.lib")
#pragma comment (lib, "ApiOpenGL40_Debug64.lib")
#pragma comment (lib, "ApiNullSound_Debug64.lib")
#pragma comment (lib, "ApiDirectSound_Debug64.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#pragma comment (lib, "ApiUtils_Release64.lib")
#pragma comment (lib, "ApiNullRenderer_Release64.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release64.lib")
#pragma comment (lib, "ApiDirectInput08_Release64.lib")
#pragma comment (lib, "ApiDirectX11FP_Release64.lib")
#pragma comment (lib, "ApiOpenGL40_Release64.lib")
#pragma comment (lib, "ApiNullSound_Release64.lib")
#pragma comment (lib, "ApiDirectSound_Release64.lib")
#pragma comment (lib, "ApiRenderDistributed_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#pragma comment (lib, "ApiUtils_Debug.lib")
#pragma comment (lib, "ApiNullRenderer_Debug.lib")
#pragma comment (lib, "ApiDirectX11Basic_Debug.lib")
#pragma comment (lib, "ApiDirectInput08_Debug.lib")
#pragma comment (lib, "ApiDirectX11FP_Debug.lib")
#pragma comment (lib, "ApiOpenGL40_Debug.lib")
#pragma comment (lib, "ApiNullSound_Debug.lib")
#pragma comment (lib, "ApiDirectSound_Debug.lib")
#pragma comment (lib, "ApiRenderDistributed_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#pragma comment (lib, "ApiUtils_Release.lib")
#pragma comment (lib, "ApiNullRenderer_Release.lib")
#pragma comment (lib, "ApiDirectX11Basic_Release.lib")
#pragma comment (lib, "ApiDirectInput08_Release.lib")
#pragma comment (lib, "ApiDirectX11FP_Release.lib")
#pragma comment (lib, "ApiOpenGL40_Release.lib")
#pragma comment (lib, "ApiNullSound_Release.lib")
#pragma comment (lib, "ApiDirectSound_Release.lib")
#pragma comment (lib, "ApiRenderDistributed_Release.lib")
#endif
#endif


#include "Vektoria\Root.h"
#include <time.h>
#include "GeoSatellit.h"
#include "GeoRakete.h"

using namespace Vektoria;


class CGame
{
public:
	CGame(void);																				// Wird vor Begin einmal aufgerufen (Konstruktor)
	~CGame(void);																				// Wird nach Ende einmal aufgerufen (Destruktor)

	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash);	// Wird zu Begin einmal aufgerufen
	void Tick(float fTime, float fTimeDelta);													// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen
	void Fini();																				// Wird am Ende einmal aufgerufen

	void WindowReSize(int iNewWidth, int iNewHeight);											// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat

private:
    // Hier ist Platz für Deine Vektoriaobjekte:
	CRoot m_zr;
	CScene m_zs;
	CPlacement m_zpCamera;
	CPlacement m_zpSphere;
	CGeoSphere m_zgSphere;
	CFrame m_zf;
	CViewport m_zv;
	CCamera m_zc;
	CLightParallel m_zl;
	CBackground m_zb;
	CMaterial m_zm;
	CTexture m_zt;
	CImage m_zi;
	CQuaternion m_zq;
	//Wolken
	CPlacement m_zpWolkenSphere;
	CGeoSphere m_zgWolkenSphere;
	CMaterial m_zmWolkenMaterial;
	//Mond
	CPlacement m_zpMondSphere;
	CGeoSphere m_zgMondSphere;
	CMaterial m_zmMondMaterial;
	//Sonne
	CPlacement m_zpSonneSphere;
	CGeoSphere m_zgSonneSphere;
	CMaterial m_zmSonneMaterial;
	//Todesstern
	CPlacement m_zpTodessternSphere;
	CGeoSphere m_zgTodessternSphere;
	CMaterial m_zmTodessternMaterial;

	CMaterial m_zmRed;

	//Keyboard
	CDeviceCursor m_zdc;
	CDeviceKeyboard m_zdk;
	//Container für Geometrieobjekte
	CGeos m_zgs;

	//Game Controller
	CDeviceGameController m_zdController;
	CDeviceGameController m_zdControllerPlayer2;

	//Punktewolke
	CGeoPointList m_zPunkteListe;
	CVertex m_zVertex[2500];
	CPlacement m_zpPunktwolke;
	CMaterial m_zmPunktwolke;


	//Sternbild
	CGeoLineList m_zLineListe;
	CMaterial m_zmLinien;

	//Satellit
	CPlacement m_zpSatellit[5];
	//CGeoSatellit* pzgSatellit = new CGeoSatellit();
	CGeoSatellit m_zgSatellit[5];

	CMaterial m_zmSatellit;

	//Rakete
	CPlacement m_zpRakete;
	CGeoRakete m_zgRakete;
	CMaterial m_zmRakete;

	bool bThirdPerson;

	//Cube
	CPlacement m_zpSkyCube;
	CGeoCube m_zgSkyCube;
	CMaterial m_zmSkyCube;

	//Spotlight
	CLightSpot m_zlSunlight;
	CPlacement m_zpSunlight;

	//Splitscreen
	CViewport m_zvRightScreen;
	CViewport m_zvLeftScreen;
	CCamera m_zcRightScreen;
	CCamera m_zcLeftScreen;
	CPlacement m_zpCameraLeft;
	CPlacement m_zpCameraRight;

	//Zweite Rakete
	CPlacement m_zpRaketePlayer2;
	CGeoRakete m_zgRaketePlayer2;
	CMaterial m_zmRaketePlayer2;

	//Punkteanzeige Writings
	CWritingFont m_zwFPunkteanzeige;
	CWriting m_zwPunkteanzeigeLeft;
	CWriting m_zwPunkteanzeigeRight;

	//Variablen
	int iPointsPlayerLeft;
	int iPointsPlayerRight;

	//Overlays
	COverlay m_zoWinner;
	COverlay m_zoLoser;
	CMaterial m_zmOverlayWinner;
	CMaterial m_zmOverlayLoser;

	//Supply Satelite
	bool bSupplyActivated;
	float fTimer;
	float fSupSatRadius;
	CMaterial m_zmSupSatNotActivated;
	CMaterial m_zmSupSatActivated;

	//Missiles
	//CGeo m_zgMissile
	CGeoSphere m_zgMissile;
	CPlacement m_zpMissile;
	CPlacement m_zpMissileLeft[20];
	int iCounterLeft;
	CHVector cSchussVektor[20];
	CHVector cMissileLeftSpaceRight[20];
	CAudio m_zaLaser;
	CAudio m_zaBackgroundMugge;
	CMaterial m_zmExplo;
	CPlacement m_zpExplosion;
	CGeoQuad m_zgExplosion;
};


