﻿/*
 *  BaseThread.h
 *  ThreadDemo
 *
 *  Created by ws wondershare on 07-5-17.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
 
#pragma once

#include "SyncEvent.h"
#include "GetTime.h"
#include "../../../interface/c++/common/WSLog.h"

#ifndef WIN32
#include "Linux32_Typedef.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/times.h>

#define Sleep(a) usleep((a) * 1000)
#define THREAD_PRIORITY_TIME_CRITICAL 15

__inline HANDLE _beginthreadex( 
   void *security,
   unsigned stack_size,
   void* (*start_address)(void*),
   void *arglist,
   unsigned initflag,
   unsigned *thrdaddr 
   )
{
	pthread_t		* pThread;
	pThread = new pthread_t;
	memset(pThread, 0, sizeof(pthread_t));

	pthread_attr_t attr = { 0 };

    pthread_attr_init(&attr);
 
    int error = pthread_create(pThread,
                                           &attr,
                                           (void* (*)(void*))start_address,
                                           (void*)arglist);
    pthread_attr_destroy(&attr);

	if (error)
	{
		delete pThread;
	}

	return pThread;
}

__inline void release_thread(HANDLE hThread)
{
	delete (pthread_t *)hThread;
}

__inline void wait_thread(HANDLE hThread)
{
	if (hThread)
		pthread_join(*(pthread_t *)hThread, 0);
}

#if 0 // conflict with GetTime.h
__inline DWORD timeGetTime()
{
	tms tm;
	return (times(&tm) * 10);
}
#endif

#define WaitThread(a) wait_thread(a)
#define CloseThread release_thread

#else

#include <process.h> 
#include <Mmsystem.h> 
#include <objbase.h> 

#define WaitThread(a) WaitForSingleObject(a, INFINITE)
#define CloseThread CloseHandle

#pragma warning(disable: 4313)

#endif

#ifdef _DEBUG
#ifndef DEBUG
#define DEBUG
#endif
#endif

#define WAITABORTEVENT(a) SyncWaitForSingleObject(m_hStopEvent, a)

#define IFABORTEVENT_BREAK(a) \
	if (EWS_OK == WAITABORTEVENT(a)) \
	{ \
		break; \
	}
	
#define IFPAUSESTATE_WAIT \
	{ \
		while(TS_PAUSE == m_uThreadState) \
		{ \
			Sleep(10); \
		} \
	}


enum THREAD_STATE
{
	TS_INACTIVE,
	TS_RUNNING,
	TS_PAUSE,
	TS_FINISH,
};
	
#ifndef EVENT_WAIT_STATE
#define EVENT_WAIT_STATE

#define EWS_OK			(0)
#define EWS_TIMEOUT		(0x0102L)
#define EWS_ERROR		(-1)

#endif // EVENT_WAIT_STATE

#ifndef WAIT_OBJECT_0
	#define WAIT_OBJECT_0	0
#endif // WAIT_OBJECT_0

#ifdef DEBUG
#define PRINTF_LOG printf_log 
static void printf_log(const char* format, ...)
{
#define LOG_BUF_SIZE 512
    va_list vl;
    char szBuf[LOG_BUF_SIZE] = { 0 };
    va_start(vl, format);
    vsnprintf(szBuf, LOG_BUF_SIZE, format, vl); 
    va_end(vl);
    printf(szBuf);
}
#else
#define PRINTF_LOG 
#endif

class BaseThread
{
public:
	BaseThread()
	: m_uThreadState(TS_INACTIVE)
	, m_nOnPause(0)
	, m_hStopEvent(0)
	, m_hThreadEvent(0)
	, m_hThread(0)
    , m_isWaitpthread(1)
	{
		PRINTF_LOG("BaseThread::BaseThread() [0x%x]...\r\n", this);
				
		m_hStopEvent = SyncCreateEvent(0, TRUE, TRUE, 0);
		m_hThreadEvent = SyncCreateEvent(0, TRUE, TRUE, 0);
	}
	
	virtual ~BaseThread()
	{
		Abort();
		Wait();
        if (!m_isWaitpthread)
        {
            WaitThread(m_hThread);
        }
		
		m_nOnPause = 0;
		m_uThreadState = TS_INACTIVE;

		PRINTF_LOG("BaseThread::~BaseThread() [0x%x]\r\n", this);
		
		SyncCloseEvent(m_hStopEvent); m_hStopEvent = 0;
		SyncCloseEvent(m_hThreadEvent); m_hThreadEvent = 0;
        #ifdef WIN32
        // windows thread�����ر�
		SyncCloseEvent(m_hThread); m_hThread = 0;
        #endif
	}
	
	BOOL Start()
	{
		if (IsActive())
		{
			PRINTF_LOG("BaseThread::Start Failed:IsActive.\r\n");
			return FALSE;
		}
		
		SyncResetEvent(m_hStopEvent);
		SyncResetEvent(m_hThreadEvent);
        #ifdef WIN32
        // windows thread�����ر�
		SyncCloseEvent(m_hThread); m_hThread = 0;
        #endif
		
		PRINTF_LOG("BaseThread::Start() [0x%x]...\r\n", this);

		UINT thread_id;
		m_hThread = (HANDLE)_beginthreadex (NULL, 0, thread_func, this, 0, &thread_id);

		if (0 == m_hThread)
		{
			SyncSetEvent(m_hStopEvent);
			SyncSetEvent(m_hThreadEvent);

			PRINTF_LOG("BaseThread::Start() Failed.\r\n");

            return FALSE;
		}
        m_isWaitpthread = 0;
		m_nOnPause = 0;
		m_uThreadState = TS_RUNNING;
		Sleep(1);
		return TRUE;
	}

	BOOL SetThreadPriority(int nPriority)
	{
#ifdef WIN32
		return ::SetThreadPriority(m_hThread, nPriority);
#else
		return FALSE;
#endif
	}
	
	int Pause()
	{
		if (IsActive())
		{
			m_nOnPause ++;
			if (1 == m_nOnPause)
				m_uThreadState = TS_PAUSE;
		}
		return m_nOnPause;
	}
	
	int Resume()
	{
		if (IsActive())
		{
			if (m_nOnPause)
				m_nOnPause --;
			if (0 == m_nOnPause)
				m_uThreadState = TS_RUNNING;
		}

		return m_nOnPause;
	}
	
	THREAD_STATE State() const
	{
		return m_uThreadState;
	}
	
	BOOL IsRunning() const
	{
		return (TS_RUNNING == m_uThreadState); 
	}
	
	BOOL IsPause() const
	{
		return (TS_PAUSE == m_uThreadState); 
	}
	
	BOOL IsActive() const
	{
		return ((TS_RUNNING == m_uThreadState) || (TS_PAUSE == m_uThreadState)); 
	}
	
	BOOL Stop()
	{
		if (!IsActive())
			return FALSE;
		
		Abort();
		Wait();
		PRINTF_LOG("BaseThread::Stop() OK\r\n");
		
		return TRUE;
	}
	
	BOOL Abort() // Post Abort Message
	{
		if (!IsActive())
			return FALSE;
		
		PRINTF_LOG("BaseThread::Abort() SyncSetEvent ...\r\n");

		SyncSetEvent(m_hStopEvent);

		if (m_nOnPause > 0)
		{
			while(Resume() && IsActive());
			m_nOnPause = 0;
		}
		
		return TRUE;
	}
	
	DWORD Wait(UINT uMilliSecondsTimeOut = 0xFFFFFFFF)
	{	
		if (!IsActive())
		{
			PRINTF_LOG("BaseThread::Wait() OK no active\r\n");
			return EWS_OK;
		}
	
		PRINTF_LOG("BaseThread::Wait() ...\r\n");
		
		DWORD dwRet = SyncWaitForSingleObject(m_hThreadEvent, uMilliSecondsTimeOut);
		if (EWS_OK == dwRet)
		{
			WaitThread(m_hThread);
            m_isWaitpthread = 1;
		}
		
		PRINTF_LOG("BaseThread::Wait() OK\r\n");
	
		return dwRet;
	}
	
protected:
	virtual void svc()
	{
		for (;;)
		{
			IFPAUSESTATE_WAIT;
			IFABORTEVENT_BREAK(0);
			// do somthing
		} 
	}
	
protected:
	HANDLE			m_hThread;
    int             m_isWaitpthread;

	HSYNCEVENT		m_hStopEvent;
	HSYNCEVENT		m_hThreadEvent;
	
	int				m_nOnPause;
	THREAD_STATE	m_uThreadState;

#ifdef WIN32
	static UINT _stdcall thread_func (LPVOID pParam)
	{
		::CoInitialize(0);
		BaseThread* pProcess = static_cast<BaseThread*>(pParam);
		if (pProcess)
		{
			pProcess->svc();
	
			SyncSetEvent(pProcess->m_hThreadEvent);
			pProcess->m_uThreadState = TS_FINISH;

			PRINTF_LOG("BaseThread::thread_func() exit.\r\n");
		}

		::CoUninitialize();
		return 0;
	}
#else
	
	static void* __stdcall thread_func(void* pParam)
	{
		BaseThread* pProcess = static_cast<BaseThread*>(pParam);
		if (pProcess)
		{
			pProcess->svc();
	
			SyncSetEvent(pProcess->m_hThreadEvent);
			pProcess->m_uThreadState = TS_FINISH;

#ifdef DEBUG			
			PRINTF_LOG("BaseThread::thread_func() exit.\r\n");
#endif		
		}

		return 0;
	}  
#endif

	
};
