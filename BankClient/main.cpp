#include <iostream>
#include "bankclient.h"
#include "../Public/Singleton.h"
#include "Client.h"

using namespace std;
using namespace PUBLIC;

int main()
{
    Singleton<BankClient>::Instance().Login();
    return 0;
}

