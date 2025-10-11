#include <iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	short s = 0,*p2=&s;
	char d = 'A', * p1 = &d;
	cout << p2 << endl;
	cout << *p1 << endl;
	return 0;
}
