#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H
#include <iostream>
#include <assert.h>
using namespace std;

//linux ��Ʒϵ��
class LinuxOS
{
public:
	LinuxOS(){};
	virtual ~LinuxOS(){};
	//linux��Ʒ�Ĺ����ӿ�
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

//windows��Ʒϵ��
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
	//�ù���������Ʒ��
	virtual LinuxOS* CreateLinuxOS() = 0;
	virtual Windows* CreateWindows() = 0;
};

//�ƶ�����
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

//pc����
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
	//���ܲ���
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