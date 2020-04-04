#pragma once

#include <string>
#include <vector>
using namespace std;

class LmBag
{
public:
	virtual ~LmBag();

	BOOL Push(wstring _stringFileName);
	wstring Pop()
	{
		// ù��° �ٸ���Ʈ ������
		wstring first_element =  (wstring)m_FileNameList.front();

		// ù��° �ٸ���Ʈ ����
		vector<wstring>::iterator itr;
		itr = m_FileNameList.begin();
		m_FileNameList.erase(itr);
		
		return first_element;
	}

	UINT GetFileNamesCount()
	{
		return (UINT)m_FileNameList.size();
	}
private:
	vector<wstring> m_FileNameList;
};