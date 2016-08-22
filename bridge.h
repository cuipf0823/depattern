#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>
using namespace std;
class Window
{
public:
	Window(){};
	virtual ~Window(){};
	virtual void DrawText() = 0;
	virtual void DrawRect() = 0;
};

class WindowImp
{
public:
	WindowImp(){};
	virtual ~WindowImp(){};
	virtual void DevDrawText() = 0;
	virtual void DevDrawRect() = 0;
};

class IconWindow: public Window
{
public:
	IconWindow(WindowImp* window_imp)
	{
		window_imp_ = window_imp;
	}
	virtual ~IconWindow()
	{

	}
	void DrawText()
	{
		window_imp_->DevDrawText();
	}

	void DrawRect()
	{
		window_imp_->DevDrawRect();
	}
private:
	WindowImp* window_imp_;
};

class XWindowImp : public WindowImp
{
public:
	XWindowImp(){};
	~XWindowImp(){};
	void DevDrawRect()
	{
		cout << "Dev draw rect ..." << endl;
	}
	void DevDrawText()
	{
		cout << "Dev draw text ..." << endl;
	}
};

void test_bridge()
{
	WindowImp* imp = new XWindowImp();
	IconWindow* window = new IconWindow(imp);
	window->DrawRect();
	window->DrawText();
}

#endif