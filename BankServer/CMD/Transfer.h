#ifndef _TRANSFER_H_
#define _TRANSFER_H_

#include "Transaction.h"

namespace CMD
{

// 转帐

class Transfer : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};

}


#endif // _TRANSFER_H_
