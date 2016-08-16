#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H
#include <iostream>
#include <assert.h>
using namespace std;

//linux 产品系列
class LinuxOS
{
public:
	LinuxOS(){};
	virtual ~LinuxOS(){};
	//linux产品的公共接口
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};

class AndroidOS : public LinuxOS
{
public:
	AndroidOS()
	{
		cout << "Create Android OS" << endl;
	}
	virtual ~AndroidOS()
	{

	}
	virtual void StartUp()
	{
		cout << "Androrid OS startup ..." << endl;
	}
	virtual void ShutDown()
	{
		cout << "Androrid OS shutdown ..." << endl;
	}
};

class CentosOS : public	LinuxOS
{
public:
	CentosOS()
	{
		cout << "Create Android OS" << endl;
	}
	virtual ~CentosOS()
	{

	}
	virtual void StartUp()
	{
		cout << "Centos OS startup ..." << endl;
	}
	virtual void ShutDown()
	{
		cout << "Centos OS shutdown ..." << endl;
	}
};

//windows产品系列
class Windows
{
public:
	Windows()
	{
		
	}
	virtual ~Windows()
	{

	}
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};

class WindowsPhone : public Windows
{
public:
	WindowsPhone()
	{
		cout << "Create Window Phone" << endl;
	}
	virtual void StartUp()
	{
		cout << "Windows Phone startup ..." << endl;
	}
	virtual void ShutDown()
	{
		cout << "Windows Phone shutdown ..." << endl;
	}
};

class Windows8 : public Windows
{
public:
	Windows8()
	{
		cout << "Create Window Phone" << endl;
	}
	virtual void StartUp()
	{
		cout << "Windows 8 startup ..." << endl;
	}
	virtual void ShutDown()
	{
		cout << "Windows 8 shutdown ..." << endl;
	}
};

class Factory
{
public:
	Factory()
	{

	}
	virtual ~Factory()
	{

	};
	//该工厂两个产品线
	virtual LinuxOS* CreateLinuxOS() = 0;
	virtual Windows* CreateWindows() = 0;
};

//移动厂商
class MobileFactory : public Factory
{
public:
	MobileFactory()
	{
		cout << "construct Mobile Factory" << endl;
	}
	virtual ~MobileFactory()
	{

	}
	virtual LinuxOS* CreateLinuxOS()
	{
		return new AndroidOS();
	}
	virtual Windows* CreateWindows()
	{
		return new WindowsPhone();
	}
};

//pc厂商
class PCFactory : public Factory
{
public:
	PCFactory()
	{
		cout << "construct Mobile Factory" << endl;
	}
	virtual ~PCFactory()
	{

	}
	virtual LinuxOS* CreateLinuxOS()
	{
		return new CentosOS();
	}
	virtual Windows* CreateWindows()
	{
		return new Windows8();
	}
};

void ProductLineTest(Factory* factory)
{
	LinuxOS* linux_os = NULL;
	Windows* windows = NULL;

	linux_os = factory->CreateLinuxOS();
	windows = factory->CreateWindows();
	//功能测试
	linux_os->StartUp();
	linux_os->ShutDown();
	windows->StartUp();
	windows->ShutDown();

	delete linux_os;
	delete windows;
}

void test_abs_factory()
{
	Factory* AFactory = NULL;
	Factory* BFactory = NULL;
	AFactory = new MobileFactory();
	assert(AFactory != NULL);
	ProductLineTest(AFactory);
	cout << endl;

	BFactory = new PCFactory();
	assert(BFactory != NULL);
	ProductLineTest(BFactory);

	delete AFactory;
	delete BFactory;
}

#endif