#include "DXUT.h"
#include "LmBag.h"

LmBag::~LmBag()
{
	m_FileNameList.clear();
}
BOOL LmBag::Push( wstring _stringFileName )
{
	m_FileNameList.push_back(_stringFileName);

	return TRUE;
}
