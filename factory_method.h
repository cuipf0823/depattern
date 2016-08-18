#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H
/*
*	工厂方法模式
*/
#include <iostream>
using namespace std;

//类工厂方法所创建的对象的接口
class Document
{
public:
	Document(){};
	virtual ~Document(){};
	virtual void open() = 0;
	virtual void save() = 0;
};

class Application
{
public:
	Application() {};
	virtual ~Application(){};
	virtual Document* CreateDocument() = 0;
	virtual void OpenDocument() = 0;
	virtual void SaveDocument() = 0;
};

class DrawingDocument: public Document
{
public:
	DrawingDocument(){};
	~DrawingDocument(){};
	virtual void open()
	{
		cout << "Drawing Docment open ..." << endl;
	}
	virtual void save()
	{
		cout << "Drawing Docment save ..." << endl;
	}
};

class DrawingApplication : public Application
{
public:
	DrawingApplication(){};
	~DrawingApplication(){};
	virtual Document* CreateDocument()
	{
		return new DrawingDocument();
	}
	virtual void OpenDocument()
	{
		cout << "open document ..." << endl;
	}
	virtual void SaveDocument()
	{
		cout << "Save document ..." << endl;
	}
};

void TestFactoryMethod()
{
	Application* app = new DrawingApplication();
	Document* doc = app->CreateDocument();
	app->OpenDocument();
	app->SaveDocument();
	delete doc;
}


#endif