#ifndef _SOCKET_H_
#define _SOCKET_H_
#include "qsystemdetection.h"

#ifdef Q_OS_WIN32
#pragma comment(lib, "ws2_32.lib")
#include <WINSOCK2.h>
#elif defined Q_OS_LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
typedef int SOCKET;
#define SOCKET_ERROR -1
#endif

namespace PUBLIC
{

	class Socket
	{
	private:
		// noncopyable
		Socket(const Socket& rhs);
		void operator=(const Socket& rhs);
	public:
		Socket();
		~Socket();
		void Create(bool tcp = true);

		static bool Startup();
		static void Cleanup();

		bool IsValid() const;

		bool Bind(const char* ip, unsigned short port);
		bool Listen(int backlog = SOMAXCONN);
		SOCKET Accept();
		bool Connect(const char* ip, unsigned short port);
		void Close();
		int Send(const char* buf, size_t len);
		int Recv(char* buf, size_t len);
		int SendN(const char* buf, size_t len);
		int RecvN(char* buf, size_t len);

		operator SOCKET() { return socket_; }

		SOCKET socket_;

	};

}

#endif // _SOCKET_H_
