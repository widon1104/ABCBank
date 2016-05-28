#ifndef _BALANCE_INQUIRY_H_
#define _BALANCE_INQUIRY_H_

#include "Transaction.h"
#include "../Public/qsystemdetection.h"

namespace CMD
{

// 查询余额

class BalanceInquiry : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};

}


#endif // _BALANCE_INQUIRY_H_
