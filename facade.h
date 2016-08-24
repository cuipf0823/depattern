#ifndef FACADE_H
#define FACADE_H
/*
*	���ģʽ
*/
#include <iostream>
using namespace std;

namespace facade
{
/*
*  	 SyntaxParser,GenMidCode,GenAssemblyCode,LinkSystem����ʵ��һ�����ӵ�
*	 ������ϵͳ������ʹ����򵥷�����ʾ
*/
class SyntaxParser
{
public:
	void Parser()
	{
		cout << "Syntax parser" << endl;
	}
};

class GenMidCode
{
public:
	void Generate()
	{
		cout << "Generate Mid code" << endl;
	}
};

class GenAssemblyCode
{
public:
	void Generate()
	{
		cout << "Generate Assembly code" << endl;
	}
};

class LinkSystem
{
public:
	void Link()
	{
		cout << "link ..." << endl;
	}
};

//facade���ģʽ��
class Compiler
{
public:
	void Compile()
	{
		SyntaxParser parser;
		GenMidCode midcode;
		GenAssemblyCode ass_code;
		LinkSystem linker;
		parser.Parser();
		midcode.Generate();
		ass_code.Generate();
		linker.Link();
	}
};

//����ϵͳ
void test_facade()
{
	Compiler compiler;
	compiler.Compile();
}


}
#endif