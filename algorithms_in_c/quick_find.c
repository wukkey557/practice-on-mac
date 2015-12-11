
/*
快速查找算法
连通性问题:
   
初始化[0, N)的数组id[N]为id[i] = i,
输入两个数p, q,若id[p] != id[q],则遍历整个数组,将所有等于id[p]的数组中元素赋值为id[q] (或反过来),且输出数组下标
若id[p] == id[q],则不输出,表示是连通的
*/


#include <stdio.h>

#define N 10000

int main() {
	int i, p, q, t, id[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
	}

	while (scanf("%d %d", &p, &q) == 2) {
		if (id[p] == id[q]) {
			continue;
		}

		t = id[p];
		for (i = 0; i < N; i++) {
			if (t == id[i]) {
				id[i] = id[q];
			}
		}

		printf("%d %d\n", p, q);
	}

	return 0;
}