
#pragma once

#ifndef _INIMGR_H_
#define _INIMGR_H_

#include "SingleTon.h"

class CIniMgr :public CSingleTon<CIniMgr>
{
public:
	void GetValue(const char *file, const char* sect, const char *key, int& nValue, int defVal = 0);
	void GetString(const char *file, const char* sect, const char *key, char* pString, char *strdef = "");
	CIniMgr();
	virtual ~CIniMgr();
};

#define g_objIniMgr  CIniMgr::GetInstance()

#endif