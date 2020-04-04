#pragma once

class LmDescript
{
public:
	LmDescript();
	virtual ~LmDescript();

	VOID Init();
	BOOL ReadFromFile(CHAR* _pFileName);
	VOID NextLine();
	CHAR* GetReadBuffer();
	BOOL bRead;
private:
	FILE* m_pFile;
	CHAR m_ReadBuffer[1024];
};