#include <stdio.h>
#pragma warning(disable:4996)

void swap(int* a, int* b);
int main()
{
	int n, arr[50], a, b, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", arr + i);
	scanf("%d %d", &a, &b);
	swap(arr + a, arr + b);
	for (i = 0; i < n; i++)
		printf(" %d", arr[i]);

}
void swap(int* a, int* b) { //�ش� �ּҿ� �Էµ��ִ� ���� ��ȯ
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}