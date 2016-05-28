#ifndef _TRANS_DETAIL_H_
#define _TRANS_DETAIL_H_

#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

namespace DAL
{

// 交易明细
struct TransDetail
{
	string trans_id;
	string account_id;
	string other_account_id;
	string abstract_name;
	double money;
	double balance;
	string trans_date;
	unsigned int total;
};

}

#endif /* _TRANS_DETAIL_H_ */