TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpthread

SOURCES += main.cpp \
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
    ../Public/StringUtil.cpp \
    ../Public/Systemconfig.cpp \
    ../Public/Timestamp.cpp \
    BankSession.cpp \
    Client.cpp \
    bankclient.cpp \
    ../Public/Socket.cpp \
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
    TransactionManager.cpp

HEADERS += \
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
    ../Public/Singleton.h \
    ../Public/StringUtil.h \
    ../Public/SystemConfig.h \
    ../Public/Timestamp.h \
    BankSession.h \
    Client.h \
    bankclient.h \
    ../Public/qsystemdetection.h \
    ../Public/Socket.h \
    ../Public/WinToLinux.h \
    TransDetail.h \
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
    TransactionManager.h

