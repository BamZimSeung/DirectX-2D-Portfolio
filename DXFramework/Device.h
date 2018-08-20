#pragma once
class Device
{
private:
	LPDIRECT3DDEVICE9 device;

	Device();
	~Device();
public:
	static Device* GetInstance();

	LPDIRECT3DDEVICE9 GetDevice() { return device; }

	void DrawBegin();
	void DrawEnd();
};

