#include <iostream>
#include "bankclient.h"
#include "../Public/Singleton.h"
#include "Client.h"
#include "../JFC/JForm.h"
#include "UI/FormManager.h"
#include "../JFC/JButton.h"
#include "UI/LoginForm.h"

using namespace std;
using namespace PUBLIC;
using namespace JFC;
using namespace UI;

int main()
{
    //Singleton<BankClient>::Instance().Login();
    //return 0;
#if 1
    JApplication app;

    JForm* form = Singleton<FormManager>::Instance().Get("LoginForm");
    form->Show();

    return app.Exec();	// 消息循环
#endif
#if 0
    JApplication app;

	printw("%d %d", CONSOLE_WIDTH, CONSOLE_HEIGHT);
	printw("%d %d", LINES, COLS);
	refresh();
    return app.Exec();	// 消息循环
#endif

#if 0
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    while (true) {
        int key = getch();
        printw("key: %d\n", key);
		printw("KEY_ENTER: %d", KEY_ENTER);

        if (key == KEY_ENTER) {
            printw("enter\n");
        } else if (key == KEY_1) {
            printw("one--\n");
        } else if (key == KEY_DOWN) {
            printw("down\n");
        } else if (key == KEY_UP) {
            printw("up\n");
        } else if (key == KEY_LEFT) {
            printw("LEFT\n");
        } else if (key == KEY_RIGHT) {
            printw("RIGHT\n");
        }
    }
#endif
#if 0
	JWindowBase jb(0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT);
	jb.DrawText("test");
	jb.Refresh();

	/*
	init_pair(1, COLOR_RED, COLOR_YELLOW);
	attron(COLOR_PAIR(1));
	mvaddstr(0, 0, "test");
	addstr("test");
	attroff(COLOR_PAIR(1));
	jb.Refresh();
	jb.SetBkColor(COLOR_RED);
	jb.SetTextColor(COLOR_YELLOW);
	JRECT rect = {10, 10, 20, 20};
    curs_set(1);
	jb.SetCursorPos(10, 10);
	init_pair(1, COLOR_RED, COLOR_YELLOW);
	WINDOW *scrwin = newwin(10, 10, 5, 5);
	wbkgd(scrwin, COLOR_PAIR(1));
	wrefresh(scrwin);
	*/
	//jb.Refresh();
	sleep(3);
#endif
#if 0
	JWindow jw(0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT, 0);
	jw.Draw();
	sleep(3);
#endif
#if 0
	JApplication app;
	char * filename = "scrdumpfile";

	JButton btn2(25, 2, 10, 3, "test2");
	btn2.SetCurrent();
	btn2.Draw();
	btn2.Refresh();

	JButton btn(11, 2, 10, 3, "test");
	//btn.SetCurrent();
	btn.Draw();
	btn.Refresh();

    return app.Exec();
#endif
}

