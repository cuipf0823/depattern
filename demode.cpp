#include <iostream>
#include <stdio.h>
#include "abstract_factory.h"
#include "builder.h"
using namespace std;

int main(int argc, char *argv[])
{
	test_abs_factory();
	cout << "*******************************" << endl;
	TestBuilder();
	getchar();
	return 0;
}