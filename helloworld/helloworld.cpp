#include <iostream>
#include <climits>
#include <limits>
#include <iomanip>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void swap(int num[], char ch[][3])
{
   int k, t;
   char temp[3] = { 0 };
   for (int i = 0; i < 9; i++) {
       k = i;
       for (int j = i + 1; j < 10; j++) {
           if (num[j] > num[k]) {
               k = j;
           }
       }
       t = num[k];
       num[k] = num[i];
       num[i] = t;

       // Fix: Use `strcpy` to copy strings between arrays
       strcpy_s(temp, ch[k]);
       strcpy_s(ch[k], ch[i]);
       strcpy_s(ch[i], temp);
   }
}

int main()
{
    int a[10] = { 0 };
    int* p1 = a;
    int* p2 = &a[1];
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p2-p1;
    return 0;
}