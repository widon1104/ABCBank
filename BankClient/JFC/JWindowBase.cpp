#include "JWindowBase.h"
#include <ncurses.h>

using namespace JFC;

#ifdef Q_OS_LINUX
int JFC::_getch()
{
	return getch();
}
#endif

JWindowBase::JWindowBase()
	: x_(0),
	  y_(0),
	  width_(0),
	  height_(0),
	  fColor_(FCOLOR_BLACK),
	  bColor_(BCOLOR_WHITE)
{

	SetColorPairNum();
}

JWindowBase::JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height)
	: x_(x),
	  y_(y),
	  width_(width),
	  height_(height),
	  fColor_(FCOLOR_BLACK),
	  bColor_(BCOLOR_WHITE)
{
	SetColorPairNum();
}

JWindowBase::~JWindowBase()
{
	if (win) {
		delwin(win);
	}
	endwin();
}


// 设置光标位置
void JWindowBase::SetCursorPos(SHORT x, SHORT y)
{
	//COORD pos = { x, y };
	(void*)win;
	move(y, x);
	curx_ = x;
	cury_ = y;
}

// 刷新窗口
void JWindowBase::Refresh()
{
	wbkgd(win, COLOR_PAIR(colorpairnum_));
	wrefresh(win);
}

// 清除矩形区域
void JWindowBase::FillRect(JRECT rect)
{
	WINDOW *scrwin = subwin(stdscr, rect.Bottom-rect.Top, rect.Right-rect.Left,
							y_+rect.Top, x_+rect.Left);
	wbkgd(scrwin, COLOR_PAIR(colorpairnum_));
	wrefresh(scrwin);
	delwin(scrwin);
}

// 绘制文本（x, y相对于本窗口的位置，并不是相对整个控制台窗口的位置）
void JWindowBase::DrawText(SHORT x, SHORT y, const std::string& text)
{
	attron(COLOR_PAIR(colorpairnum_));
	mvaddstr(y_+y, x_+x, text.c_str());
	attroff(COLOR_PAIR(colorpairnum_));
}

// 在窗口正中间绘制文本
void JWindowBase::DrawText(const std::string& text)
{
	SHORT x = (Width() - text.length()) / 2;
	SHORT y = (Height() - 1) / 2;
	DrawText(x, y, text);
}

// 在水平位置画线
void JWindowBase::DrawHLine(SHORT row, SHORT col, SHORT n, char ch)
{
	attron(COLOR_PAIR(colorpairnum_));
	mvhline(y_+row, x_+col, ch, n);
	attroff(COLOR_PAIR(colorpairnum_));
}

// 在垂直位置画线
void JWindowBase::DrawVLine(SHORT row, SHORT col, SHORT n, char ch)
{
	attron(COLOR_PAIR(colorpairnum_));
	mvvline(y_+row, x_+col, ch, n);
	attroff(COLOR_PAIR(colorpairnum_));
}


// 清除窗口
void JWindowBase::ClearWindow()
{
	//clear();
	werase(win);
}
