#include <iostream>
#include <stdio.h>
#include "abstract_factory.h"
#include "builder.h"
#include "factory_method.h"
using namespace std;

int main(int argc, char *argv[])
{
	test_abs_factory();
	cout << "*******************************" << endl;
	TestBuilder();
	cout << "*******************************" << endl;
	TestFactoryMethod();
	getchar();
	return 0;
}