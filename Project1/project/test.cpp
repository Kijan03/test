#include "MyBoolVector.h"
#include <iostream>

using namespace std;

int main()
{
	MyBoolVector a;
	a.push_back(true);
	a.push_back(false);

	MyBoolVector b;
	b.push_back(false);
	b.push_back(true);
	b.push_back(true);

	a + b;

	cout << boolalpha;
	cout << a[1] << endl;
}