#include "JThread.h"

#ifdef Q_OS_WIN32
#include <process.h>
#elif defined Q_OS_LINUX
#include <pthread.h>
#endif

using namespace PUBLIC;

JThread::JThread(bool isAutoDel)
	: isAutoDel_(isAutoDel)
{
	hThread_ = NULL;
	threadId_ = 0;
}

JThread::~JThread()
{
	if (hThread_ != NULL)
	{
#ifdef Q_OS_WIN32
		CloseHandle(hThread_);
        hThread_ = NULL;
#elif defined Q_OS_LINUX
        close(hThread_);
        hThread_ = 0;
#endif
	}
}
bool JThread::Start()
{
#ifdef Q_OS_WIN32
    hThread_ = (HANDLE)_beginthreadex(NULL,0,ThreadFun,(void*)this,0,&threadId_);
    return (hThread_ != NULL);
#elif defined Q_OS_LINUX
    return pthread_create(&hThread_, 0, ThreadFun, (void*)this);
#endif
}

#ifdef Q_OS_WIN32
unsigned __stdcall JThread::ThreadFun(void *p)
#elif defined Q_OS_LINUX
void* __stdcall JThread::ThreadFun(void *p)
#endif
{
	JThread* jtp = (JThread*)p;
	jtp->Run();
	if (jtp->isAutoDel_)
	{
		delete jtp;
	}
	return 0;
}

void JThread::SetAutoDel(bool flag)
{
	isAutoDel_ = flag;
}

void JThread::Wait(DWORD timeout)
{
#ifdef Q_OS_WIN32
    WaitForSingleObject(hThread_,timeout);
#elif defined Q_OS_LINUX
    struct timespec ts;
    ts.tv_sec = timeout;
    ts.tv_nsec = 0;
    if (pthread_timedjoin_np(hThread_, NULL, &ts)) {
    }
#endif
}
