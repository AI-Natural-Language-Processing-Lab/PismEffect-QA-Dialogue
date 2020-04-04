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
		// 첫번째 앨리먼트 꺼내기
		wstring first_element =  (wstring)m_FileNameList.front();

		// 첫번째 앨리먼트 삭제
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