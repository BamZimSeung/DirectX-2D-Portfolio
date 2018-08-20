#include "stdafx.h"
#include "Device.h"


Device::Device()
{
	LPDIRECT3D9 d3d;

	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS param = {};
	param.Windowed = TRUE;
	param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	param.AutoDepthStencilFormat = D3DFMT_D16;
	param.EnableAutoDepthStencil = TRUE;

	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&param,
		&device
	);

	d3d->Release();
}


Device::~Device()
{
	device->Release();
}

Device * Device::GetInstance()
{
	static Device instance;
	return &instance;
}

void Device::DrawBegin()
{
	device->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		//소거할 대상 지정
		//target : 후면버퍼, zbuffer : 깊이버퍼
		0xffff69b4,
		1.0f,
		0
	);
	device->BeginScene();//장면시작
}

void Device::DrawEnd()
{
	device->EndScene();
	device->Present(NULL, NULL, NULL, NULL);
}
