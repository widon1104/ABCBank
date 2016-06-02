#include "JApplication.h"

#include "JEvent.h"
#include "JWindow.h"

#ifdef Q_OS_WIN32
#include <conio.h>
#elif defined Q_OS_LINUX
#include <ncurses.h>
#endif

using namespace JFC;

JApplication* JApplication::self_ = 0;

void JApplication::InitCurses()
{
	setlocale(LC_ALL,"");
	initscr();
	//raw();
	start_color();
	curs_set(0);
    noecho();
    keypad(stdscr,TRUE);
	HideCursor();

    init_pair(P_WHITE_RED, COLOR_WHITE, COLOR_RED);
	init_pair(P_BLUE_CYAN, COLOR_BLUE, COLOR_CYAN);
    init_pair(P_WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
    init_pair(P_YELLOW_MAGENTA, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(P_YELLOW_CYAN, COLOR_YELLOW, COLOR_CYAN);
    init_pair(P_BLACK_WHITE, COLOR_BLACK,  COLOR_WHITE);
    init_pair(P_BLUE_WHITE, COLOR_BLUE, COLOR_WHITE);
    init_pair(P_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(P_YELLOW_RED, COLOR_YELLOW, COLOR_RED);
	init_pair(P_WHITE_WHITE, COLOR_WHITE, COLOR_WHITE);
	init_pair(P_BLUE_RED, COLOR_BLUE, COLOR_RED);
	init_pair(P_WHITE_CYAN, COLOR_WHITE, COLOR_CYAN);
}

JApplication::JApplication()
{
	if (self_)
		return;

	self_ = this;
    //SetConsoleOutputCP(936);
	//COORD size = { CONSOLE_WIDTH, CONSOLE_HEIGH };
    //SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
	InitCurses();
	root_ = new JWindow(0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT, 0);

	//draw the whole backgroud
	wbkgd(stdscr, COLOR_PAIR(P_BLACK_WHITE));
	wrefresh(stdscr);

	root_->Show();
}

JApplication::~JApplication()
{
	delete root_;
}

void JApplication::ShowCursor() const
{
    curs_set(1);
}

void JApplication::HideCursor() const
{
    curs_set(0);
}

int JApplication::Exec()
{
	while (1)
	{
        int key = _getch();
		if (current_)
		{
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		} else {
			printw("no current_\n");
		}
	}
	return 0;
}

