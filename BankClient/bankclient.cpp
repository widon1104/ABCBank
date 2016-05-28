#include "bankclient.h"
#include "BankSession.h"
#include "Client.h"
#include "TransactionManager.h"
#include "../Public/Singleton.h"

using namespace PUBLIC;

BankClient::BankClient()
{

}

void BankClient::Login()
{
#if 1
    BankSession*bs = Singleton<Client>::Instance().GetBankSession();
    bs->Connect();
    bs->Clear();
    bs->SetCmd(CMD_LOGIN);
    bs->SetAttribute("name", "root");
    bs->SetAttribute("pass", "999");
    Singleton<TransactionManager>::Instance().DoAction(*bs);
    if (bs->GetErrorCode() == 0) {
        printf("ok\n");
    } else {
        printf("fail\n");
        printf("%s\n", bs->GetErrorMsg().c_str());
    }


#else
    char buffer[1024] = {0};
    Socket sock;
    sock.Create();
    int connstatus = sock.Connect("127.0.0.1", 8888);
    printf("conn: %d\n", connstatus);
    std::string str;
    str.append("admin");
    str.append("#");
    str.append("123456");
    sock.Send(str.c_str(), str.length());
    sock.Recv(buffer, sizeof(buffer));
    printf("buffer: %s\n", buffer);

#endif
}

