#ifndef _JTHREAD_H_
#define _JTHREAD_H_

#include "qsystemdetection.h"
#include <pthread.h>

#ifdef Q_OS_WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif defined Q_OS_LINUX
#include "WinToLinux.h"
#include <unistd.h>
#endif

namespace PUBLIC
{

class JThread
{
public:
	JThread(bool isAutoDel = false);
	virtual ~JThread();
	bool Start();
	virtual void Run() = 0;
#ifdef Q_OS_WIN32
    static unsigned __stdcall ThreadFun(void *p);
#elif defined Q_OS_LINUX
    static void* __stdcall ThreadFun(void *p);
#endif

	void SetAutoDel(bool flag);
private:
#ifdef Q_OS_WIN32
	HANDLE hThread_;
#elif defined Q_OS_LINUX
    pthread_t hThread_;
#endif
    unsigned threadId_;
protected:
	void Wait(DWORD timeout=INFINITE);
	bool isAutoDel_;
};

}


#endif // _JTHREAD_H_
