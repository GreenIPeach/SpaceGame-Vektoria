#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;


class CGeoRakete :
	public CGeoBezierTable
{
public:
	CGeoRakete();
	~CGeoRakete();

private:
	CHVector m_aav[4][4];
};

