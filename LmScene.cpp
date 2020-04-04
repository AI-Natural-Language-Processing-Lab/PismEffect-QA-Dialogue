#include "DXUT.h"
#include "LmScene.h"
#include <math.h>

BOOL LmScene::Draw(LPDIRECT3DDEVICE9 _pDevice, CHAR* _pText,FLOAT _fAngle)
{
	int i = 0;
	for(i = 0; i < (int)strlen(_pText)-4;i=i+4)
	{
		FLOAT fPoint1 = _pText[i];
		FLOAT fPoint2 = _pText[i+1];
		FLOAT fPoint3 = _pText[i+2];
		FLOAT fPoint4 = _pText[i+3];

		FLOAT fScaleX = 8.0;
		FLOAT fScaleY = 10.0;
		LPD3DXLINE line;
		D3DXCreateLine(_pDevice, &line);
		
		D3DXVECTOR2 lines[] = {
			D3DXVECTOR2(
			fPoint1*fScaleX, 
			fPoint2*fScaleY*cos(_fAngle/180.0f*3.14)),
			D3DXVECTOR2(
			fPoint3*fScaleX*cos(_fAngle/180.0f*3.14), 
			fPoint4*fScaleY)};

		D3DCOLOR color = D3DCOLOR_ARGB((INT)fPoint1,(INT)fPoint2,(INT)fPoint3,(INT)fPoint4);
		FLOAT fScaleColor = 0.000001f;
		FLOAT fWidth = color*fScaleColor;
		line->SetWidth(fWidth);
		line->Begin();
		line->Draw(lines, 2, color);
		line->End();
		line->Release();
	}

	return TRUE;
}