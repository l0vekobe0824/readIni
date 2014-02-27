#pragma once

#ifndef _RESSTR_H_
#define _RESSTR_H_
#include <string>
#include <map>
#include "SingleTon.h"

class CResStrMgr: public CSingleTon<CResStrMgr>
{
public:
	const char* GetStr(const std::string strID);
	CResStrMgr();
	virtual ~CResStrMgr();
private:
	void LoadFile(const char* pFileName);
	void ParserLine(char* pszLine);

	std::map<std::string, std::string> m_mapStrRes;
};

#define g_objResStrMgr  CResStrMgr::GetInstance()

#endif