#include <stdio.h>

void insertion_sort(int* array, int size) {
	int key, i, j;
	for (i = 1; i < size; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			j -= 1;
			array[j+1] = key;
		}
	}
}

int main() {
	int array[] = {5, 2, 8, 10, 6};
	insertion_sort(array, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d", array[i]);
		if (i == 4) 
			printf("\n");
		else
			printf(" ");
	}
}