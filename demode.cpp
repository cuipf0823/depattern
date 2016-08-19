#include <iostream>
#include <stdio.h>
#include "abstract_factory.h"
#include "builder.h"
#include "factory_method.h"
#include "prototype.h"
using namespace std;

int main(int argc, char *argv[])
{
	test_abs_factory();
	cout << "*******************************" << endl;
	TestBuilder();
	cout << "*******************************" << endl;
	TestFactoryMethod();
	cout << "*******************************" << endl;
	test_prototype();
	test_prototype_manager();
	getchar();
	return 0;
}