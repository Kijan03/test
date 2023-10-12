#include "MyBoolVector.h"
#include <iostream>

using namespace std;

int main()
{
	MyBoolVector a;
	a.push_back(true);
	a.push_back(false);
	
	a.push_back(true);
	a.push_back(false);

	a.push_back(true);
	a.push_back(false);

	/*
	MyBoolVector b;
	
	b.push_back(false);

	b.push_back(true);
	b.push_back(false);

	b.push_back(true);
	b.push_back(false);
	b.push_back(true);
	b.push_back(false);
	b.push_back(true);
	b.push_back(false);
	
	a += b;
	*/

	-a;
	

	cout << boolalpha;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	cout << a.is_empty() << endl;
	cout << a[6] << endl;
}