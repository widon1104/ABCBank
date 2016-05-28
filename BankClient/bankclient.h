#ifndef BANKCLIENT_H
#define BANKCLIENT_H

#include "../Public/Singleton.h"

using namespace PUBLIC;

class BankClient
{
    friend class Singleton<BankClient>;
public:
    void Login();
private:
    BankClient();
};

#endif // BANKCLIENT_H
