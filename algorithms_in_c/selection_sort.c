#include <stdio.h>

void selection_sort(int array[], int N) {
	int i, value;
	int key = 0;
	int count = 0;
	int tArray[5] = {};

	while (count < N) {		
		for (i = 1; i < N - count; i++) {
			printf("key = %d, i = %d\n", key, i);
			if (array[key] > array[i]) {
				key = i;
			}
		}
		
		value = array[key];
		for (i = key; i < N - count; i++) {
			if (i != N - count - 1) {
				printf("%d\n", i);
				array[i] = array[i+1];
			}
		}

		tArray[count] = value;
		key = 0;

		count++;
	}

	for (i = 0; i < N; i++) {
		array[i] = tArray[i];
	}
}

int main() {
	int array[] = {2, 3, 1, 8, 5};
	selection_sort(array, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d", array[i]);
		if (i == 4)
			printf("\n");
		else
			printf(" ");
	}

	return 0;
}