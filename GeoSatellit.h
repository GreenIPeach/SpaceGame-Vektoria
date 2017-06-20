#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CGeoSatellit :
	public CGeoTriangleTable
{
public:
	CGeoSatellit();
	~CGeoSatellit();

	CVertex m_aVertex[14];
};

