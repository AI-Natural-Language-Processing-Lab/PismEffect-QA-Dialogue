#include "DXUT.h"
#include "LmDescript.h"

#include <stdio.h>

LmDescript::LmDescript()
{
	m_pFile = NULL;
	bRead = FALSE;
}

LmDescript::~LmDescript()
{
	if(m_pFile != NULL)
	{
		fclose(m_pFile);
		m_pFile = NULL;
	}
}

VOID LmDescript::Init()
{
	if(m_pFile != NULL)
	{
		fclose(m_pFile);
		m_pFile = NULL;
	}
	bRead = FALSE;
}

BOOL LmDescript::ReadFromFile( CHAR* _pFileName )
{
	if(m_pFile == NULL)
	{
		errno_t err_no = fopen_s(&m_pFile,_pFileName,"r");
		if(err_no != 0)
		{
			m_pFile = NULL;
			return FALSE;
		}
		NextLine();
		bRead = TRUE;
		return TRUE;
	}
	return FALSE;
}

VOID LmDescript::NextLine()
{
	if(m_pFile == NULL)
	{
		return;
	}
	int read_size = fread(m_ReadBuffer,1024,sizeof(CHAR),m_pFile);
	if(read_size == 0)
	{
		Init();
	}
}

CHAR* LmDescript::GetReadBuffer()
{
	return m_ReadBuffer;
}
