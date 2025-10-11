#include <iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	int arr[4] = { 1,2,3,4 };
	int (*p)[4] = &arr; // p是指向含4个整数的一维数组的指针
	cout << *p << endl;
	cout << *(*p+1) << endl;

	int matrix[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int(*q)[4] = matrix; // q是指向含4个整数的一维数组的指针
	cout << (*(q + 1)[1]) << endl;
	cout << ((*(q + 1))[1]) << endl;
	cout << *(*q + 1) << endl;

	return 0;
}
