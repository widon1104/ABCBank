#ifndef _JWINDOW_BASE_H_
#define _JWINDOW_BASE_H_

#include <string>
#include "../Public/qsystemdetection.h"
#ifdef Q_OS_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#elif defined Q_OS_LINUX
#include "../Public/WinToLinux.h"
#include "../Public/wincon.h"
#include <curses.h>
#endif

namespace JFC
{
typedef SMALL_RECT JRECT;
#ifdef Q_OS_LINUX
extern int _getch();
#endif

enum ColorPairEnum {
	P_WHITE_RED = 1,
	P_BLUE_CYAN,
	P_WHITE_BLUE,
	P_YELLOW_MAGENTA,
	P_YELLOW_CYAN,
	P_BLACK_WHITE,
	P_BLUE_WHITE,
	P_WHITE_BLACK,
	P_YELLOW_RED,
	P_WHITE_WHITE,
	P_BLUE_RED,
	P_WHITE_CYAN,
};

#define FCOLOR_BLACK COLOR_BLACK
#define FCOLOR_RED COLOR_RED
#define FCOLOR_GREEN COLOR_GREEN
#define FCOLOR_YELLO COLOR_YELLOW
#define FCOLOR_BLUE COLOR_BLUE
#define FCOLOR_MAGENTA COLOR_MAGENTA
#define FCOLOR_CYAN COLOR_CYAN
#define FCOLOR_WHITE COLOR_WHITE
#define BCOLOR_BLACK COLOR_BLACK
#define BCOLOR_RED COLOR_RED
#define BCOLOR_GREEN COLOR_GREEN
#define BCOLOR_YELLOW COLOR_YELLOW
#define BCOLOR_BLUE COLOR_BLUE
#define BCOLOR_MAGENTA COLOR_MAGENTA
#define BCOLOR_CYAN COLOR_CYAN
#define BCOLOR_WHITE COLOR_WHITE

#define BCOLOR_GRAY COLOR_YELLOW

#define KEY_DEL KEY_DL
#define KEY_BACK KEY_BACKSPACE
#define KEY_PGDN KEY_NPAGE
#define KEY_PGUP KEY_PPAGE
//assic
#define KEY_ESC 27
#define KEY_ENTER 10
#define KEY_TAB 9
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57

#define CONSOLE_WIDTH	COLS
#define CONSOLE_HEIGHT	LINES

class JWindowBase
{
public:
	JWindowBase();
	JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height);

	virtual ~JWindowBase();

	SHORT Width() const { return width_; }
	SHORT Height() const { return height_; }

	// 设置文本颜色
	void SetTextColor(WORD fColor)
	{
		fColor_ = fColor;
		SetColorPairNum();
	}

	// 获取文本颜色
	WORD GetTextColor() const { return fColor_; }

	void SetColorPairNum()
	{
		//P_WHITE_RED, COLOR_WHITE, COLOR_RED;
		if (fColor_ == COLOR_WHITE && bColor_ == COLOR_RED) {
			colorpairnum_ = P_WHITE_RED;
		} else if (fColor_ == COLOR_BLUE && bColor_ == COLOR_CYAN) {
			colorpairnum_ = P_BLUE_CYAN;
		} else if (fColor_ == COLOR_WHITE && bColor_ == COLOR_BLUE) {
			colorpairnum_ = P_WHITE_BLUE;
		} else if (fColor_ == COLOR_YELLOW && bColor_ == COLOR_MAGENTA) {
			colorpairnum_ = P_YELLOW_MAGENTA;
		} else if (fColor_ == COLOR_YELLOW && bColor_ == COLOR_CYAN) {
			colorpairnum_ = P_YELLOW_CYAN;
		} else if (fColor_ == COLOR_BLACK && bColor_ == COLOR_WHITE) {
			colorpairnum_ = P_BLACK_WHITE;
		} else if (fColor_ == COLOR_BLUE && bColor_ == COLOR_WHITE) {
			colorpairnum_ = P_BLUE_WHITE;
		} else if (fColor_ == COLOR_WHITE && bColor_ == COLOR_BLACK) {
			colorpairnum_ = P_WHITE_BLACK;
		} else if (fColor_ == COLOR_YELLOW && bColor_ == COLOR_RED){
			colorpairnum_ = P_YELLOW_RED;
		} else if (fColor_ == COLOR_WHITE && bColor_ == COLOR_WHITE){
			colorpairnum_ = P_WHITE_WHITE;
		} else if (fColor_ == COLOR_BLUE && bColor_ == COLOR_RED){
			colorpairnum_ = P_BLUE_RED;
		} else if (fColor_ == COLOR_WHITE && bColor_ == COLOR_CYAN){
			colorpairnum_ = P_WHITE_CYAN;
		} else {
			/*
			ClearWindow();
			printw("%d %d\n", fColor_, bColor_);
			refresh();
			*/
		}
	}

	// 设置背景色
	void SetBkColor(WORD bColor)
	{
		bColor_ = bColor;
		SetColorPairNum();
	}

	// 获取背景色
	WORD GetBkColor() const { return bColor_; }

	// 设置光标位置
	void SetCursorPos(SHORT x, SHORT y);

	// 刷新窗口
	void Refresh();

	// 清除矩形区域
	void FillRect(JRECT rect);

	// 绘制文本（x, y相对于本窗口的位置，并不是相对整个控制台窗口的位置）
	void DrawText(SHORT x, SHORT y, const std::string& text);

	// 在窗口正中间绘制文本
	void DrawText(const std::string& text);

	// 在水平位置画线
	void DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch);

	// 在垂直位置画线
	void DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch);

	// 清除窗口
	void ClearWindow();

protected:
	WINDOW *win = NULL;
	SHORT x_;			// x坐标
	SHORT y_;			// y坐标
	SHORT curx_ = 0;	// cur row
	SHORT cury_ = 0;	// cur col
	SHORT width_;		// 宽度
	SHORT height_;		// 高度
	SHORT colorpairnum_;		//
	WORD fColor_;		// 前景色（文本颜色）
	WORD bColor_;		// 背景色
};

// 用于保存与还原屏幕某一块区域数据
class ScreenSaver
{
public:
	ScreenSaver(JRECT rect)
		: rect_(rect)
	{
	}

	~ScreenSaver()
	{
	}

	void Dump()
	{
		scr_init(filename);
		scr_dump(filename);
	}

	void Restore()
	{
		scr_restore(filename);
		overwrite(curscr, stdscr);
		doupdate();
	}
private:
	char* filename = "scrdumpfile";
	JRECT rect_;
};

}

#endif // _JWINDOW_BASE_H_
