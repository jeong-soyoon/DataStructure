#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//3���� ��� �ǽ����� 4��
int arrayMax(int* arr, int n) {
	int max;
	if (n == 1)
		return *arr;
	else {
		max = arrayMax(arr + 1, n - 1);
		if (*arr > max)
			return *arr;
		else
			return max;
	}

}
int main() {
	int n, * arr;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d", arrayMax(arr,n));
}