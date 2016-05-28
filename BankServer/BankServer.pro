TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpthread
LIBS += -L/usr/lib/x86_64-linux-gnu -lmysqlclient

SOURCES += main.cpp \
    DAL/BankService.cpp \
    DAL/MysqlDB.cpp \
    BankSession.cpp \
    BankThread.cpp \
    Server.cpp \
    TransactionManager.cpp \
    CMD/BalanceInquiry.cpp \
    CMD/ChangePassword.cpp \
    CMD/CloseAccount.cpp \
    CMD/Deposit.cpp \
    CMD/OpenAccount.cpp \
    CMD/QueryAccountHistoryBill.cpp \
    CMD/QueryDayBill.cpp \
    CMD/QueryHistoryBill.cpp \
    CMD/Transfer.cpp \
    CMD/UserLogin.cpp \
    CMD/Withdrawal.cpp \
    ../Public/Date.cpp \
    ../Public/Exception.cpp \
    ../Public/Idea.cpp \
    ../Public/JInStream.cpp \
    ../Public/JOutStream.cpp \
    ../Public/JThread.cpp \
    ../Public/JUtil.cpp \
    ../Public/Logging.cpp \
    ../Public/LogStream.cpp \
    ../Public/MD5.cpp \
    ../Public/Socket.cpp \
    ../Public/StringUtil.cpp \
    ../Public/Systemconfig.cpp \
    ../Public/Timestamp.cpp

HEADERS += \
    DAL/Account.h \
    DAL/BankService.h \
    DAL/IBankService.h \
    DAL/MysqlDB.h \
    DAL/TransDetail.h \
    BankSession.h \
    BankThread.h \
    Server.h \
    TransactionManager.h \
    CMD/BalanceInquiry.h \
    CMD/ChangePassword.h \
    CMD/CloseAccount.h \
    CMD/Deposit.h \
    CMD/OpenAccount.h \
    CMD/QueryAccountHistoryBill.h \
    CMD/QueryDayBill.h \
    CMD/QueryHistoryBill.h \
    CMD/Transaction.h \
    CMD/Transfer.h \
    CMD/UserLogin.h \
    CMD/Withdrawal.h \
    ../Public/Date.h \
    ../Public/Exception.h \
    ../Public/Idea.h \
    ../Public/JInStream.h \
    ../Public/JOutStream.h \
    ../Public/JThread.h \
    ../Public/JUtil.h \
    ../Public/Logging.h \
    ../Public/LogStream.h \
    ../Public/MD5.h \
    ../Public/qsystemdetection.h \
    ../Public/Singleton.h \
    ../Public/Socket.h \
    ../Public/StringUtil.h \
    ../Public/SystemConfig.h \
    ../Public/Timestamp.h \
    ../Public/WinToLinux.h

