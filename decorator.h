#ifndef DECORATOR_H
#define DECORATOR_H
/*
*	装饰模式
*/
#include <iostream>
using namespace std;

namespace decorator
{

class VisualComponent
{
public:
	VisualComponent(){};
	virtual ~VisualComponent(){};
	virtual void Draw() = 0;
};

class Decorator : public VisualComponent
{
public:
	Decorator(VisualComponent* component)
	{
		component_ = component;
	}
	~Decorator()
	{

	}
	virtual void Draw()
	{
		component_->Draw();
	}
protected:
	VisualComponent* component_;
};
//窗口添加边框
class BorderDecorator : public Decorator
{
public:
	BorderDecorator(VisualComponent* component, int borderwidth) :
		Decorator(component),
		border_width_(borderwidth)
	{

	}
	~BorderDecorator()
	{

	}
	void Draw()
	{
		Decorator::Draw();
		DrawBorder();
	}
	void DrawBorder()
	{
		cout << "Draw Border " << border_width_ << endl;
	}
private:
	int border_width_;
};

//窗口的显示滚动条
class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(VisualComponent* component) : Decorator(component)
	{

	}
	~ScrollDecorator()
	{

	}
	void Draw()
	{
		Decorator::Draw();
		ScrollTo();
	}
	void ScrollTo()
	{
		cout << "scorll to " << endl;
	}
};

//window窗口中用于显示正文
class TextView :public VisualComponent
{
public:
	TextView()
	{
	};
	~TextView()
	{

	}
	void Draw()
	{
		cout << "Text view Draw " << endl;
	}
};

//window实例
class Window
{
public:
	Window(){}
	~Window(){}

	void SetContents(VisualComponent* contents)
	{
		cout << "Window Set Contents" << endl;
		contents->Draw();
	}
};

void test_decorator()
{
	Window* window = new Window();
	TextView* text_view = new TextView;
	ScrollDecorator* scroll = new ScrollDecorator(text_view);
	BorderDecorator* border = new BorderDecorator(scroll, 10);
	window->SetContents(border);
	delete border;
	delete scroll;
	delete text_view;
	delete window;
}

}
#endif