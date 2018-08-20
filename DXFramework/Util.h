#pragma once
class Util
{
private:
	Util();
	~Util();
public:
	static Util* GetInstance() {
		static Util instance;
		return &instance;
	}

	float GetDistance(D3DXVECTOR2 v1, D3DXVECTOR2 v2);
	D3DXVECTOR2 GetNormalVector(D3DXVECTOR2 v1, D3DXVECTOR2 v2);
};

