#ifndef _CHANGE_PASSWORD_H_
#define _CHANGE_PASSWORD_H_

#include "Transaction.h"

namespace CMD
{

// 修改密码

class ChangePassword : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};

}

#endif // _CHANGE_PASSWORD_H_
