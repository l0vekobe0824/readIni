#include "stdafx.h"
#include "ResStr.h"
#include <stdio.h>

#define  MAX_LINE_NUM  1024

CResStrReader::CResStrReader()
{
	LoadFile("cn_res.ini");
}

CResStrReader::~CResStrReader()
{
	m_mapStrRes.clear();
}

void CResStrReader::LoadFile(const char* pFileName)
{
	if (NULL == pFileName)
	{
		return;
	}
	
	FILE* pFile = fopen(pFileName, "r");
	if (!pFile)
	{
		return;
	}

	char szLine[MAX_LINE_NUM] = {0};

	while(true)
	{
		if (NULL == fgets(szLine, sizeof(szLine), pFile))
		{
			break;
		}
		
		ParserLine(szLine);
	}

}
void CResStrReader::ParserLine(char* pszLine)
{
	if (NULL == pszLine || pszLine[0] == 0 || pszLine[0] == ';')
	{
		return;
	}

	char TmpLine[MAX_LINE_NUM] = {0};

	strncpy(TmpLine, pszLine, MAX_LINE_NUM);
	TmpLine[sizeof(TmpLine) - 1] = 0;
	
	char* pEquaPos = strchr(TmpLine, '=');

	if (NULL == pEquaPos)
	{
		return;
	}
	
	*pEquaPos = 0;

	char* pszValue = pEquaPos + 1;

	m_mapStrRes[TmpLine] = std::string(pszValue);

}

const char* CResStrReader::GetStr(const std::string strID)
{
	std::map<std::string, std::string>::iterator iter = m_mapStrRes.find(strID);

	if (iter != m_mapStrRes.end())
	{
		return iter->second.c_str();
	}
	
	return "";
}