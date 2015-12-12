#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	fgets(a, sizeof(a), stdin);
	printf("strlen of a is %lu\n", strlen(a));

	*a = '9';
	for (int i = 0; i <= strlen(a) - 1; i++)
		printf("%d\n", (int)(a[i]));
}