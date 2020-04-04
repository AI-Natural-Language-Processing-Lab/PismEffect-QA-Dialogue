#include "DXUT.h"
#include "LmMonster.h"
#include <string.h>
#include <tchar.h>

BOOL LmMonster::SearchDirectory()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = NULL;

	WCHAR wBuffer[128];
	GetCurrentDirectory(128,wBuffer);
	_tcscat_s(wBuffer, 128, L"\\*.txt");
	hFind = FindFirstFile(wBuffer, &FindFileData);

	if(hFind == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	do
	{
		WCHAR* pWChar = new WCHAR [lstrlen(FindFileData.cFileName) + 1];
		for(int i = 0; i < lstrlen(FindFileData.cFileName); i++)
		{
			pWChar[i] = WCHAR(FindFileData.cFileName[i]);
			pWChar[lstrlen(FindFileData.cFileName)] = '\0';
		}

		wstring ss(pWChar);

		m_Bag.Push(ss);
	}while(FindNextFile(hFind,&FindFileData));

	FindClose(hFind);

	return TRUE;
}
