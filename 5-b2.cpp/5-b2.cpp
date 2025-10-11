//2453805 Ã∆œ»‘Û µÁ–≈
#include<iostream>
using namespace std;
int main() 
{
	int a[100] = {0};
	for (int i = 1; i < 101; i++) {
		for (int j = 0; j < 100; j++) {
			if ((j + 1) % i == 0) {
				a[j] += 1;

			}
		}
	}
	for (int j = 0; j < 100; j++) {
		if (a[j] % 2 != 0) {
			cout << (j+1) << " ";
		}
	}
	cout << endl;
	return 0;
}