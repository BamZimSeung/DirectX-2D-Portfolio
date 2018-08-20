#include "stdafx.h"
#include "Util.h"


Util::Util()
{
}


Util::~Util()
{
}

float Util::GetDistance(D3DXVECTOR2 v1, D3DXVECTOR2 v2)
{
	D3DXVECTOR2 deltaV = v1 - v2;
	return sqrtf(deltaV.x * deltaV.x + deltaV.y * deltaV.y);
}

D3DXVECTOR2 Util::GetNormalVector(D3DXVECTOR2 v1, D3DXVECTOR2 v2)
{
	D3DXVECTOR2 tmpV = v2 - v1;
	return tmpV / GetDistance(v1, v2);
}
