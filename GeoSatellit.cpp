#include "GeoSatellit.h"



CGeoSatellit::CGeoSatellit()
{
	//Vorderseite des Satellits

	m_aVertex[0].Init(
		CHVector(-0.4f, 0.0f, 0.0f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		0.0f, 1.0f);

	m_aVertex[1].Init(
		CHVector(-0.3f, -0.4f, 0.0f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		1.0f, 1.0f);

	m_aVertex[2].Init(
		CHVector(0.3f, -0.4f, 0.0f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		0.0f, 0.0f);

	m_aVertex[3].Init(
		CHVector(0.4f, 0.0f, 0.0f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		1.0f, 0.0f);

	m_aVertex[4].Init(
		CHVector(0.0f, 0.3f, 0.0f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		1.0f, 0.0f);

	//Rückseite des Satellits

	m_aVertex[5].Init(
		CHVector(-0.4f, 0.0f, 2.5f),
		CHVector(0.0f, 0.0f, -1.0f),
		CHVector(1.0f, 0.0f, 0.0f),
		0.0f, 1.0f);

	m_aVertex[6].Init(
		CHVector(-0.3f, -0.4f, 2.5f),
		CHVector(0.0f, 0.0f, -1.0f),
		CHVector(1.0f, 0.0f, 0.0f),
		1.0f, 1.0f);

	m_aVertex[7].Init(
		CHVector(0.3f, -0.4f, 2.5f),
		CHVector(0.0f, 0.0f, -1.0f),
		CHVector(1.0f, 0.0f, 0.0f),
		0.0f, 0.0f);

	m_aVertex[8].Init(
		CHVector(0.4f, 0.0f, 2.5f),
		CHVector(0.0f, 0.0f, -1.0f),
		CHVector(1.0f, 0.0f, 0.0f),
		1.0f, 0.0f);

	m_aVertex[9].Init(
		CHVector(0.0f, 0.3f, 2.5f),
		CHVector(0.0f, 0.0f, -1.0f),
		CHVector(1.0f, 0.0f, 0.0f),
		1.0f, 0.0f);

	//Flügel

	m_aVertex[10].Init(
		CHVector(-2.5f, 0.15f, 1.25f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		0.0f, 1.0f);

	m_aVertex[11].Init(
		CHVector(-2.5f, -0.15f, 1.25f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		0.0f, 0.0f);

	m_aVertex[12].Init(
		CHVector(2.5f, -0.15f, 1.25f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		1.0f, 0.0f);

	m_aVertex[13].Init(
		CHVector(2.5f, 0.15f, 1.25f),
		CHVector(0.0f, 0.0f, 1.0f),
		CHVector(-1.0f, 0.0f, 0.0f),
		1.0f, 1.0f);

	for (int i = 0; i < 14; ++i)
	{
		AddVertex(&m_aVertex[i]);
	}

	//Vorderseite

	AddIndex(0);
	AddIndex(1);
	AddIndex(2);

	AddIndex(0);
	AddIndex(2);
	AddIndex(3);

	AddIndex(0);
	AddIndex(3);
	AddIndex(4);

	//Rückseite

	AddIndex(5);
	AddIndex(6);
	AddIndex(7);

	AddIndex(5);
	AddIndex(7);
	AddIndex(8);

	AddIndex(5);
	AddIndex(8);
	AddIndex(9);

	//Verbindung von Vorder und Rückseite

	AddIndex(9);
	AddIndex(5);
	AddIndex(0);

	AddIndex(9);
	AddIndex(0);
	AddIndex(4);

	AddIndex(9);
	AddIndex(4);
	AddIndex(3);

	AddIndex(9);
	AddIndex(3);
	AddIndex(8);

	AddIndex(8);
	AddIndex(3);
	AddIndex(2);

	AddIndex(8);
	AddIndex(2);
	AddIndex(7);

	AddIndex(0);
	AddIndex(5);
	AddIndex(6);

	AddIndex(0);
	AddIndex(6);
	AddIndex(1);

	AddIndex(2);
	AddIndex(1);
	AddIndex(6);

	AddIndex(2);
	AddIndex(6);
	AddIndex(7);

	//Flügelverbindung

	AddIndex(13);
	AddIndex(10);
	AddIndex(11);
	
	AddIndex(13);
	AddIndex(11);
	AddIndex(12);

	


	Init();
}


CGeoSatellit::~CGeoSatellit()
{
}
