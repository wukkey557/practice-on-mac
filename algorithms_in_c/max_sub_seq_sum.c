/*
  求最大连续子序列之和
*/

#include <stdio.h>

//穷举(复杂度:O(n^3))
int seqSum1(int seq[], int N) {
	int i, j, k;
	int sumMax = 0;
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			int sumNow = 0;
			for (k = i; k <= j; k++) {
				sumNow += seq[k];
			}
			if (sumNow > sumMax) 
				sumMax = sumNow;
		}
	}

	return sumMax;
}

// 时间复杂度: O(n^2)
int seqSum2(int seq[], int N) {
	int i, j;
	int sumMax = 0;
	for (i = 0; i < N; i++) {
		int sumNow = 0;
		for (j = i; j < N; j++) {
			sumNow += seq[j];
			if (sumNow > sumMax) 
				sumMax = sumNow;
		}
	}

	return sumMax;
}



int main() {
	int array[] = {2, 3, -1, 8, -1};
	int sum = seqSum2(array, 5);

	printf("max sum is %d\n", sum);

	return 0;
}