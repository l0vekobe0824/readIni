#pragma once

#ifndef _RESSTR_H_
#define _RESSTR_H_
#include <string>
#include <map>

class CResStrReader
{
public:
	CResStrReader();
	~CResStrReader();

	const char* GetStr(const std::string strID);
private:
	void LoadFile(const char* pFileName);
	void ParserLine(char* pszLine);

	std::map<std::string, std::string> m_mapStrRes;
};


#endif