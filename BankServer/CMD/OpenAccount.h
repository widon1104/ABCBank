#ifndef _OPEN_ACCOUNT_H_
#define _OPEN_ACCOUNT_H_

#include "Transaction.h"

namespace CMD
{

// 开户
class OpenAccount : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};

}

#endif // _OPEN_ACCOUNT_H_
