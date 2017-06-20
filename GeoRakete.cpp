#include "GeoRakete.h"



CGeoRakete::CGeoRakete()
{
	// Erzeuge Patch 0:
	m_aav[0][0] = CHVector(1.5f, 0.0f, 2.4f, 1.0f); 
	m_aav[1][0] = CHVector(1.5f, -0.84f, 2.4f, 1.0f);
	m_aav[2][0] = CHVector(0.84f, -1.5f, 2.4f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, -1.5f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(1.75f, 0.0f, 1.875f, 1.0f); 
	m_aav[1][1] = CHVector(1.75f, -0.98f, 1.875f, 1.0f);
	m_aav[2][1] = CHVector(0.98f, -1.75f, 1.875f, 1.0f);
	m_aav[3][1] = CHVector(0.0f, -1.75f, 1.875f, 1.0f);
	m_aav[0][2] = CHVector(2.0f, 0.0f, 1.35f, 1.0f); 
	m_aav[1][2] = CHVector(2.0f, -1.12f, 1.35f, 1.0f);
	m_aav[2][2] = CHVector(1.12f, -2.0f, 1.35f, 1.0f);
	m_aav[3][2] = CHVector(0.0f, -2.0f, 1.35f, 1.0f);
	m_aav[0][3] = CHVector(2.0f, 0.0f, 0.9f, 1.0f); 
	m_aav[1][3] = CHVector(2.0f, -1.12f, 0.9f, 1.0f);
	m_aav[2][3] = CHVector(1.12f, -2.0f, 0.9f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, -2.0f, 0.9f, 1.0f);
	AddPatch(m_aav, 20, 20); // Patch 0 hat 20x20 Vertices

	// Erzeuge Patch 1:
	m_aav[0][0] = CHVector(0.0f, -1.5f, 2.4f, 1.0f);
	m_aav[1][0] = CHVector(-0.84f, -1.5f, 2.4f, 1.0f);
	m_aav[2][0] = CHVector(-1.5f, -0.84f, 2.4f, 1.0f);
	m_aav[3][0] = CHVector(-1.5f, 0.0f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(0.0f, -1.75f, 1.875f, 1.0f);
	m_aav[1][1] = CHVector(-0.98f, -1.75f, 1.875f, 1.0f);
	m_aav[2][1] = CHVector(-1.75f, -0.98f, 1.875f, 1.0f);
	m_aav[3][1] = CHVector(-1.75f, 0.0f, 1.875f, 1.0f);
	m_aav[0][2] = CHVector(0.0f, -2.0f, 1.35f, 1.0f);
	m_aav[1][2] = CHVector(-1.12f, -2.0f, 1.35f, 1.0f);
	m_aav[2][2] = CHVector(-2.0f, -1.12f, 1.35f, 1.0f);
	m_aav[3][2] = CHVector(-2.0f, 0.0f, 1.35f, 1.0f);
	m_aav[0][3] = CHVector(0.0f, -2.0f, 0.9f, 1.0f);
	m_aav[1][3] = CHVector(-1.12f, -2.0f, 0.9f, 1.0f);
	m_aav[2][3] = CHVector(-2.0f, -1.12f, 0.9f, 1.0f);
	m_aav[3][3] = CHVector(-2.0f, 0.0f, 0.9f, 1.0f);
	AddPatch(m_aav, 20, 20); // Patch 1 hat 20x20 Vertices

	// Erzeuge Patch 2:
	m_aav[0][0] = CHVector(-1.5f, 0.0f, 2.4f, 1.0f);
	m_aav[1][0] = CHVector(-1.5f, 0.84f, 2.4f, 1.0f);
	m_aav[2][0] = CHVector(-0.84f, 1.5f, 2.4f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, 1.5f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(-1.75f, 0.0f, 1.875f, 1.0f);
	m_aav[1][1] = CHVector(-1.75f, 0.98f, 1.875f, 1.0f);
	m_aav[2][1] = CHVector(-0.98f, 1.75f, 1.875f, 1.0f);
	m_aav[3][1] = CHVector(0.0f, 1.75f, 1.875f, 1.0f);
	m_aav[0][2] = CHVector(-2.0f, 0.0f, 1.35f, 1.0f);
	m_aav[1][2] = CHVector(-2.0f, 1.12f, 1.35f, 1.0f);
	m_aav[2][2] = CHVector(-1.12f, 2.0f, 1.35f, 1.0f);
	m_aav[3][2] = CHVector(0.0f, 2.0f, 1.35f, 1.0f);
	m_aav[0][3] = CHVector(-2.0f, 0.0f, 0.9f, 1.0f);
	m_aav[1][3] = CHVector(-2.0f, 1.12f, 0.9f, 1.0f);
	m_aav[2][3] = CHVector(-1.12f, 2.0f, 0.9f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, 2.0f, 0.9f, 1.0f);
	AddPatch(m_aav, 20, 20); // Patch 2 hat 20x20 Vertices

	// Erzeuge Patch 3:
	m_aav[0][0] = CHVector(0.0f, 1.5f, 2.4f, 1.0f);
	m_aav[1][0] = CHVector(0.84f, 1.5f, 2.4f, 1.0f);
	m_aav[2][0] = CHVector(1.5f, 0.84f, 2.4f, 1.0f);
	m_aav[3][0] = CHVector(1.5f, 0.0f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(0.0f, 1.75f, 1.875f, 1.0f);
	m_aav[1][1] = CHVector(0.98f, 1.75f, 1.875f, 1.0f);
	m_aav[2][1] = CHVector(1.75f, 0.98f, 1.875f, 1.0f);
	m_aav[3][1] = CHVector(1.75f, 0.0f, 1.875f, 1.0f);
	m_aav[0][2] = CHVector(0.0f, 2.0f, 1.35f, 1.0f);
	m_aav[1][2] = CHVector(1.12f, 2.0f, 1.35f, 1.0f);
	m_aav[2][2] = CHVector(2.0f, 1.12f, 1.35f, 1.0f);
	m_aav[3][2] = CHVector(2.0f, 0.0f, 1.35f, 1.0f);
	m_aav[0][3] = CHVector(0.0f, 2.0f, 0.9f, 1.0f);
	m_aav[1][3] = CHVector(1.12f, 2.0f, 0.9f, 1.0f);
	m_aav[2][3] = CHVector(2.0f, 1.12f, 0.9f, 1.0f);
	m_aav[3][3] = CHVector(2.0f, 0.0f, 0.9f, 1.0f);
	AddPatch(m_aav, 20, 20); // Patch 3 hat 20x20 Vertices

	//Ab hier Raketenhauptteil

	// Erzeuge Patch 4:
	m_aav[0][0] = CHVector(0.0f, 1.6f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(0.0f, 1.6f, 5.5f, 1.0f);
	m_aav[2][0] = CHVector(0.0f, 1.6f, 4.0f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, 1.6f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(-1.15f, 1.27f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(-1.15f, 1.27f, 5.5f, 1.0f);
	m_aav[2][1] = CHVector(-1.15f, 1.27f, 4.0f, 1.0f);
	m_aav[3][1] = CHVector(-1.15f, 1.27f, 2.4f, 1.0f);
	m_aav[0][2] = CHVector(-1.45f, 0.9f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(-1.45f, 0.9f, 5.5f, 1.0f);
	m_aav[2][2] = CHVector(-1.45f, 0.9f, 4.0f, 1.0f);
	m_aav[3][2] = CHVector(-1.45f, 0.9f, 2.4f, 1.0f);
	m_aav[0][3] = CHVector(-1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(-1.55f, 0.0f, 5.5f, 1.0f);
	m_aav[2][3] = CHVector(-1.55f, 0.0f, 4.0f, 1.0f);
	m_aav[3][3] = CHVector(-1.55f, 0.0f, 2.4f, 1.0f);
	AddPatch(m_aav, 20, 20);
	
	// Erzeuge Patch 5:
	m_aav[0][0] = CHVector(1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(1.55f, 0.0f, 5.5f, 1.0f);
	m_aav[2][0] = CHVector(1.55f, 0.0f, 4.0f, 1.0f);
	m_aav[3][0] = CHVector(1.55f, 0.0f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(1.45f, 0.9f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(1.45f, 0.9f, 5.5f, 1.0f);
	m_aav[2][1] = CHVector(1.45f, 0.9f, 4.0f, 1.0f);
	m_aav[3][1] = CHVector(1.45f, 0.9f, 2.4f, 1.0f);
	m_aav[0][2] = CHVector(1.15f, 1.27f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(1.15f, 1.27f, 5.5f, 1.0f);
	m_aav[2][2] = CHVector(1.15f, 1.27f, 4.0f, 1.0f);
	m_aav[3][2] = CHVector(1.15f, 1.27f, 2.4f, 1.0f);
	m_aav[0][3] = CHVector(0.0f, 1.6f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(0.0f, 1.6f, 5.5f, 1.0f);
	m_aav[2][3] = CHVector(0.0f, 1.6f, 4.0f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, 1.6f, 2.4f, 1.0f);
	AddPatch(m_aav, 20, 20);
	
	// Erzeuge Patch 6:
	m_aav[0][0] = CHVector(0.0f, -1.6f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(0.0f, -1.6f, 5.5f, 1.0f);
	m_aav[2][0] = CHVector(0.0f, -1.6f, 4.0f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, -1.6f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(1.15f, -1.27f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(1.15f, -1.27f, 5.5f, 1.0f);
	m_aav[2][1] = CHVector(1.15f, -1.27f, 4.0f, 1.0f);
	m_aav[3][1] = CHVector(1.15f, -1.27f, 2.4f, 1.0f);
	m_aav[0][2] = CHVector(1.45f, -0.9f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(1.45f, -0.9f, 5.5f, 1.0f);
	m_aav[2][2] = CHVector(1.45f, -0.9f, 4.0f, 1.0f);
	m_aav[3][2] = CHVector(1.45f, -0.9f, 2.4f, 1.0f);
	m_aav[0][3] = CHVector(1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(1.55f, 0.0f, 5.5f, 1.0f);
	m_aav[2][3] = CHVector(1.55f, 0.0f, 4.0f, 1.0f);
	m_aav[3][3] = CHVector(1.55f, 0.0f, 2.4f, 1.0f);
	AddPatch(m_aav, 20, 20);
	
	// Erzeuge Patch 7:
	m_aav[0][0] = CHVector(-1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(-1.55f, 0.0f, 5.5f, 1.0f);
	m_aav[2][0] = CHVector(-1.55f, 0.0f, 4.0f, 1.0f);
	m_aav[3][0] = CHVector(-1.55f, 0.0f, 2.4f, 1.0f);
	m_aav[0][1] = CHVector(-1.45f, -0.9f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(-1.45f, -0.9f, 5.5f, 1.0f);
	m_aav[2][1] = CHVector(-1.45f, -0.9f, 4.0f, 1.0f);
	m_aav[3][1] = CHVector(-1.45f, -0.9f, 2.4f, 1.0f);
	m_aav[0][2] = CHVector(-1.15f, -1.27f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(-1.15f, -1.27f, 5.5f, 1.0f);
	m_aav[2][2] = CHVector(-1.15f, -1.27f, 4.0f, 1.0f);
	m_aav[3][2] = CHVector(-1.15f, -1.27f, 2.4f, 1.0f);
	m_aav[0][3] = CHVector(0.0f, -1.6f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(0.0f, -1.6f, 5.5f, 1.0f);
	m_aav[2][3] = CHVector(0.0f, -1.6f, 4.0f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, -1.6f, 2.4f, 1.0f);
	AddPatch(m_aav, 20, 20);

	//Spitze der Rakete
	
	// Erzeuge Patch 8:
	m_aav[0][0] = CHVector(-1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(-1.05f, 0.0f, 7.5f, 1.0f);
	m_aav[2][0] = CHVector(-0.65f, 0.0f, 8.0f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][1] = CHVector(-1.45f, 0.9f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(-1.0f, 0.6f, 7.5f, 1.0f);
	m_aav[2][1] = CHVector(-0.6f, 0.3f, 8.0f, 1.0f);
	m_aav[3][1] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][2] = CHVector(-1.15f, 1.27f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(-0.8f, 0.9f, 7.5f, 1.0f);
	m_aav[2][2] = CHVector(-0.4f, 0.5f, 8.0f, 1.0f);
	m_aav[3][2] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][3] = CHVector(0.0f, 1.6f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(0.0f, 1.27f, 7.5f, 1.0f);
	m_aav[2][3] = CHVector(0.0f, 0.9f, 8.0f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	AddPatch(m_aav, 20, 20);
	
	// Erzeuge Patch 9:
	m_aav[0][0] = CHVector(0.0f, 1.6f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(0.0f, 1.27f, 7.5f, 1.0f);
	m_aav[2][0] = CHVector(0.0f, 0.9f, 8.0f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][1] = CHVector(1.15f, 1.27f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(0.8f, 0.9f, 7.5f, 1.0f);
	m_aav[2][1] = CHVector(0.4f, 0.5f, 8.0f, 1.0f);
	m_aav[3][1] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][2] = CHVector(1.45f, 0.9f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(1.0f, 0.6f, 7.5f, 1.0f);
	m_aav[2][2] = CHVector(0.6f, 0.3f, 8.0f, 1.0f);
	m_aav[3][2] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][3] = CHVector(1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(1.05f, 0.0f, 7.5f, 1.0f);
	m_aav[2][3] = CHVector(0.65f, 0.0f, 8.0f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	AddPatch(m_aav, 20, 20);
	
	// Erzeuge Patch 10:
	m_aav[0][0] = CHVector(1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(1.05f, 0.0f, 7.5f, 1.0f);
	m_aav[2][0] = CHVector(0.65f, 0.0f, 8.0f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][1] = CHVector(1.45f, -0.9f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(1.0f, -0.6f, 7.5f, 1.0f);
	m_aav[2][1] = CHVector(0.6f, -0.3f, 8.0f, 1.0f);
	m_aav[3][1] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][2] = CHVector(1.15f, -1.27f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(0.8f, -0.9f, 7.5f, 1.0f);
	m_aav[2][2] = CHVector(0.4f, -0.5f, 8.0f, 1.0f);
	m_aav[3][2] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][3] = CHVector(0.0f, -1.6f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(0.0f, -1.27f, 7.5f, 1.0f);
	m_aav[2][3] = CHVector(0.0f, -0.9f, 8.0f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	AddPatch(m_aav, 20, 20);
	
	// Erzeuge Patch 11:
	m_aav[0][0] = CHVector(0.0f, -1.6f, 7.0f, 1.0f);
	m_aav[1][0] = CHVector(0.0f, -1.27f, 7.5f, 1.0f);
	m_aav[2][0] = CHVector(0.0f, -0.9f, 8.0f, 1.0f);
	m_aav[3][0] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][1] = CHVector(-1.15f, -1.27f, 7.0f, 1.0f);
	m_aav[1][1] = CHVector(-0.8f, -0.9f, 7.5f, 1.0f);
	m_aav[2][1] = CHVector(-0.4f, -0.5f, 8.0f, 1.0f);
	m_aav[3][1] = CHVector(-0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][2] = CHVector(-1.45f, -0.9f, 7.0f, 1.0f);
	m_aav[1][2] = CHVector(-1.0f, -0.6f, 7.5f, 1.0f);
	m_aav[2][2] = CHVector(-0.6f, -0.3f, 8.0f, 1.0f);
	m_aav[3][2] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	m_aav[0][3] = CHVector(-1.55f, 0.0f, 7.0f, 1.0f);
	m_aav[1][3] = CHVector(-1.05f, 0.0f, 7.5f, 1.0f);
	m_aav[2][3] = CHVector(-0.65f, 0.0f, 8.0f, 1.0f);
	m_aav[3][3] = CHVector(0.0f, 0.0f, 8.5f, 1.0f);
	AddPatch(m_aav, 20, 20);

	Init();
}


CGeoRakete::~CGeoRakete()
{
}
