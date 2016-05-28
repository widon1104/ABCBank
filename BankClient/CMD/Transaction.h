#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "../BankSession.h"

namespace CMD
{

// 命令基类
class Transaction
{
public:
	virtual void Execute(BankSession& session) = 0;
	virtual ~Transaction() {};
};

}

#endif // _TRANSACTION_H_
