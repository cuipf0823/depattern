#ifndef FACADE_H
#define FACADE_H
/*
*	外观模式
*/
#include <iostream>
using namespace std;

namespace facade
{
/*
*  	 SyntaxParser,GenMidCode,GenAssemblyCode,LinkSystem用于实现一个复杂的
*	 编译器系统，下面使用最简单方法表示
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

//facade外观模式类
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

//其他系统
void test_facade()
{
	Compiler compiler;
	compiler.Compile();
}


}
#endif