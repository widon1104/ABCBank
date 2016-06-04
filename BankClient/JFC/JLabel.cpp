#include "JLabel.h"

using namespace JFC;

JLabel::JLabel()
	: JWindow(0, 0, 0, 0, 0)
{

}

JLabel::JLabel(SHORT x, SHORT y, SHORT width, SHORT height,
			   const std::string& text,
			   JWindow* parent)
	: JWindow(x, y, width, height, parent),
	  text_(text)
{
	win = subwin (stdscr, height, width, y, x);
}

JLabel::~JLabel()
{

}

void JLabel::Draw()
{
	SetTextColor(FCOLOR_BLUE);
	if (parent_)
	{
		SetBkColor(parent_->GetBkColor());
	}
	else
		SetBkColor(BCOLOR_WHITE);

	DrawText(0, 0, text_);
}
