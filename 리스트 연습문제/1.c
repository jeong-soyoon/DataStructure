#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void rElements(int *A,int i, int n) {
	if (i < n) {
		printf("%d", A[i]);
		return rElements(A, i + 1, n); //���, ���̽����̽�(i>=n)�� ���ذ��� ����
	}
	//���̽����̽�(i>=n)
}