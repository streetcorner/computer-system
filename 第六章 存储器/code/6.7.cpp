// 6.7.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

const int N = 400;

int sumarray3d(int ***a) {
	int i, j, k, sum = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				sum += a[k][i][j];
			}
		}
	}
	return sum;
}

int main()
{
	int i, j, k;
	int ***array3d = new int **[N];
	for (i = 0; i < N; i++) {
		array3d[i] = new int *[N];
		for (j = 0; j < N; j++) {
			array3d[i][j] = new int [N];
			for (k = 0; k < N; k++) {
				array3d[i][j][k] = 1;
			}
		}
	}

	double total_time = 0;
	for (int count = 0; count < 10; count++) {
		cout << "---------- begin " << count + 1 << " ----------" << endl;

		clock_t start, end;  //精确到毫秒
		start = clock();
		sumarray3d(array3d);
		end = clock();   //精确到毫秒
		total_time += end - start;
	}

	cout << "cost time: " << total_time / 1000 << endl;

    return 0;
}
