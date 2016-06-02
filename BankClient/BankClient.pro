TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpthread -lncursesw
QMAKE_CXXFLAGS += -g -O0


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
    TransactionManager.cpp \
    JFC/JApplication.cpp \
    JFC/JButton.cpp \
    JFC/JEdit.cpp \
    JFC/JForm.cpp \
    JFC/JLabel.cpp \
    JFC/JLinkText.cpp \
    JFC/JMessageBox.cpp \
    JFC/JWindow.cpp \
    JFC/JWindowBase.cpp \
    UI/BalanceInquiryForm.cpp \
    UI/ChangePasswordForm.cpp \
    UI/CloseAccountForm.cpp \
    UI/DepositForm.cpp \
    UI/DetailStatementForm.cpp \
    UI/FormManager.cpp \
    UI/LoginForm.cpp \
    UI/MainMenuForm.cpp \
    UI/OpenAccountForm.cpp \
    UI/QueryAccountHistoryBillForm.cpp \
    UI/QueryDayBillForm.cpp \
    UI/QueryHistoryBillForm.cpp \
    UI/ReceiptForm.cpp \
    UI/ReportForm.cpp \
    UI/TransferForm.cpp \
    UI/Validator.cpp \
    UI/WithdrawalForm.cpp

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
    TransactionManager.h \
    JFC/JApplication.h \
    JFC/JButton.h \
    JFC/JEdit.h \
    JFC/JEvent.h \
    JFC/JForm.h \
    JFC/JLabel.h \
    JFC/JLinkText.h \
    JFC/JMessageBox.h \
    JFC/JWindow.h \
    JFC/JWindowBase.h \
    ../Public/wincon.h \
    UI/BalanceInquiryForm.h \
    UI/ChangePasswordForm.h \
    UI/CloseAccountForm.h \
    UI/DepositForm.h \
    UI/DetailStatementForm.h \
    UI/FormManager.h \
    UI/LoginForm.h \
    UI/MainMenuForm.h \
    UI/OpenAccountForm.h \
    UI/QueryAccountHistoryBillForm.h \
    UI/QueryDayBillForm.h \
    UI/QueryHistoryBillForm.h \
    UI/ReceiptForm.h \
    UI/ReportForm.h \
    UI/TransferForm.h \
    UI/Validator.h \
    UI/WithdrawalForm.h

