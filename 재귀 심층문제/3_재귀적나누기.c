#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* divide(int a, int b) { //������ ��ȯ->�迭 �ּ� ��ȯ
	//int* result = (int*)malloc(2 * sizeof(int)); �̷������� �޸� �Ҵ��ص� �ǰ�
	int result[2]; //�׳� �̷��� �����ص� ��
	if (a < b) {
		result[0] = 0;
		result[1] = a;
	}
	else {
		result[0] = 1 + divide(a - b, b)[0]; //��
		result[1] = divide(a - b, b)[1]; //������
	}
	return result;
}
int main()
{
	int a, b, * arr;
	scanf("%d %d", &a, &b);
	arr = divide(a, b);
	printf("%d %d", arr[0], arr[1]);
}