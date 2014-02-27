#pragma once

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template <typename T>
class CSingleTon
{
public:
	static T& GetInstance()
	{
		if (NULL == s_pInstance)
		{
			s_pInstance = new T();
		}
		return *s_pInstance;
	}
protected:
	CSingleTon()
	{
	}
	virtual ~CSingleTon()
	{
		destroy();
	}
	void destroy()
	{
		if (NULL != s_pInstance)
		{
			delete s_pInstance; s_pInstance = NULL;
		}
		
	}
private:
	static T* s_pInstance;
};

template <typename T>
T	*CSingleTon<T>::s_pInstance = NULL;

#endif