#include "JButton.h"

using namespace JFC;

JButton::JButton()
	: JWindow(0, 0, 0, 0, 0)
{
	SetCanFocus(true);
}

JButton::JButton(SHORT x, SHORT y, SHORT width, SHORT height,
				 const std::string& text,
				 JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{

	win = subwin (stdscr, height, width, y, x);
	/*
	win = newwin (height, width, y, x);
	box(win, COLOR_PAIR(1), 0);
	wrefresh(win);
	*/

	SetCanFocus(true);
}

JButton::~JButton()
{
}

void JButton::Draw()
{
	if (IsCurrent())
	{
        SetTextColor(COLOR_WHITE);
        SetBkColor(COLOR_RED);
		jApp->HideCursor();
	}
	else
	{
        SetTextColor(COLOR_BLUE);
        SetBkColor(COLOR_CYAN);
	}

	DrawText(text_);
}
