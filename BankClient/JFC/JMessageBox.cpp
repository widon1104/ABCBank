#include "JMessageBox.h"
#include "JForm.h"
#include "JButton.h"
#include "JApplication.h"
#ifdef Q_OS_WIN32
#include <conio.h>
#endif

using namespace JFC;

int JMessageBox::Show(const std::string& title,
					  const std::string& text,
					  std::vector<std::string>& buttons)
{
	short btn_distance = static_cast<short>(buttons.size()) - 1;

	for (int i=0; i<static_cast<int>(buttons.size()); ++i)
		btn_distance += buttons[i].length() + 4;		// 按钮宽度=文本长度+4

	short width = 4 + btn_distance;		// 最小左边距=2，最小右边距=2
	//short width = 4 + static_cast<short>(buttons.size()) - 1;	// 左边距2 + 右边距2 + 按钮间距（1*n)

	if (width < 40)
		width = 40;			// MessageBox最小宽度为40

	// 每行字符个数width-6;
	// 计算得出文本行数
	short lines = (text.length() + width-6 -1) / (width-6);
	//short lines =
	//	(text.length() % (width-6)) ? (text.length() / (width-6)+1) : (text.length() / (width-6));

	short height = lines + 9;

	short x = (CONSOLE_WIDTH - width) / 2;
	short y = (CONSOLE_HEIGHT - height) / 2;

	JMessageBoxImpl jmbl(x, y, width, height, title, text, buttons, btn_distance, lines);
	JWindow* w = jApp->GetCurrent();

	jmbl.Show();

	int ret = jmbl.Exec();

	w->SetCurrent();
	return ret;
}

JMessageBoxImpl::JMessageBoxImpl(SHORT x, SHORT y, SHORT w, SHORT h,
								 const std::string& title, const std::string& text,
								 std::vector<std::string>& buttons, SHORT btnDistance,
								 int lines, JWindow* parent)
	: JWindow(x, y, w, h),
	  title_(title),
	  text_(text),
	  btnDistance_(btnDistance),
	  lines_(lines)
{
	win = subwin (stdscr, h, w, y, x);

	short btnX = x + (width_ - btnDistance_) / 2;
	short btnY = y + h - 5;

	for (int i=0; i<static_cast<int>(buttons.size()); ++i)
	{
		JButton* btn = new JButton(btnX, btnY, buttons[i].length()+4, 3, buttons[i], this);
		btnX += buttons[i].length()+4+1;
	}

}

void JMessageBoxImpl::Draw()
{
	ClearWindow();
	
	SetTextColor(FCOLOR_YELLO);
	SetBkColor(BCOLOR_MAGENTA);

	DrawHLine(0, 0, Width(), '-');
	DrawHLine(Height()-1, 0, Width(), '-');

	DrawVLine(0, 0, Height()-1, ' ');
	DrawVLine(0, Width()-1, Height()-1, ' ');


	SetBkColor(BCOLOR_CYAN);
	JRECT rect = { 1, 1, Width()-1, Height()-1 };
	FillRect(rect);

	DrawText(2, 1, title_);
	if (lines_ == 1)
		DrawText(width_/2-text_.length()/2, 3, text_);
	else
	{
		for (int i=0; i<lines_; ++i)
		{
			std::string s;
			if (i == lines_ - 1)
				s = text_.substr(i*(width_-6));
			else
				s = text_.substr(i*(width_-6), width_-6);
			DrawText(3, 3+i, s);
		}
	}

	std::vector<JWindow*>::iterator it;
	for (it = childs_.begin(); it !=childs_.end(); ++it)
	{
		(*it)->Draw();
		(*it)->Refresh();
	}
}

int JMessageBoxImpl::Exec()
{
	int pos = 0;
	while (1)
	{
		int key = _getch();
#ifdef Q_OS_WIN32
		if(key == 224)
		{
			key = (key << 8) + _getch();
		}
#endif

		JWindow* p;
		JWindow* w = jApp->GetCurrent();
		switch (key)
		{
		case KEY_ESC:
			return -1;
		case KEY_ENTER:
			return pos;
		case KEY_LEFT:
		case KEY_UP:
			p = FindPrev(jApp->GetCurrent());
			p->SetCurrent();
			p->Draw();
			p->Refresh();

			w->Draw();
			w->Refresh();
			pos--;
			//pos += childs_.size();
			//pos %= childs_.size();
			if (pos < 0)
				pos = childs_.size() - 1;
			break;
		case KEY_RIGHT:
		case KEY_TAB:
		case KEY_DOWN:
			p = FindNext(jApp->GetCurrent());
			p->SetCurrent();
			p->Draw();
			p->Refresh();

			w->Draw();
			w->Refresh();
			pos++;
			//pos += childs_.size();
			//pos %= childs_.size();
			if (pos == childs_.size())
				pos = 0;
		default:
			break;
		}
	}
}
