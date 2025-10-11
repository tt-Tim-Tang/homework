//2453805 唐先泽 电信
#include<iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */

	int n_1, n_2, n_3;
	int c1, c2, c3, c4, c5, c6, c7, c8, c9;
	int sum = 0;
	for (c1 = 1; c1 <= 9; c1++) {
		for (c2 = 1; c2 <= 9; c2++) {
			if (c2 == c1) {
				continue;
			}
			for (c3 = 1; c3 <= 9; c3++) {
				if (c3 == c1 || c3 == c2) {
					continue;
				}
				n_1 = c1 * 100 + c2 * 10 + c3 * 1;
				for (c4 = 1; c4 <= 9; c4++) {
					if (c4 == c1 || c4 == c2 || c4 == c3) {
						continue;
					}
					for (c5 = 1; c5 <= 9; c5++) {
						if (c5 == c1 || c5 == c2 || c5 == c3 || c5==c4) {
							continue;
						}
						for (c6 = 1; c6 <= 9; c6++) {
							if (c6 == c1 || c6 == c2 || c6 == c3 || c6 == c4 || c6 == c5) {
								continue;
							}
							n_2 = c4 * 100 + c5 * 10 + c6 * 1;
							for (c7 = 9; c7 >= 1; c7--) {
								if (c7 == c1 || c7 == c2 || c7 == c3 || c7 == c4 || c7 == c5 || c7 == c6) {
									continue;
								}
								for (c8 = 9; c8 >= 1; c8--) {
									if (c8 == c1 || c8 == c2 || c8 == c3 || c8 == c4 || c8 == c5 || c8 == c6 || c8 == c7) {
										continue;
									}
								    for (c9 = 9; c9 >= 1; c9--) {
										if (c9 == c1 || c9 == c2 || c9 == c3 || c9 == c4 || c9 == c5 || c9 == c6 || c9 == c7 || c9 == c8) {
											continue;
										}
										n_3 = c7 * 100 + c8 * 10 + c9 * 1;

										if ((n_1 + n_2 + n_3) == 1953) {
											if ((n_1 < n_2)&& (n_2< n_3)) {
												sum = sum + 1;
												cout << "No." << setw(3) << setiosflags(ios::right) << sum;
												cout << resetiosflags(ios::right) << " : ";
												cout << n_1 << "+" << n_2 << "+" << n_3 << "=" << "1953" << endl;

											}
											else if (n_1 > n_2) {
												break;
											}
											else {
												continue;
											}

										}
						

									}

								}


							}
						}

					}
				}
			}


		}
	}
	



	cout << "total=" << sum << endl;




	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}