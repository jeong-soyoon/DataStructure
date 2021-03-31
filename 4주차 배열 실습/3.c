#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int n, ** arr, i, col = 0, row = 0, limit, j, move;
	scanf("%d", &n);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(n * sizeof(int));
	limit = n - 1;
	move = 1;
	for (i = 1; i <= n*n; i++) {
		arr[row][col] = i;
		if (col == limit) {
			row++; //���� ������ �̵�
			limit = n-1 - limit; //�� ��ȣ�� ¦���� ���� ������ �̵��ϴ� ���� limit�� n-1�̰�,
			                     //�� ��ȣ�� Ȧ���� ���� ������ �̵��ϴ� ���� limit�� 0�̴�.
			move = -move; //�� ��ȣ�� ¦���� ���������� �̵�(move==1)
			              //�� ��ȣ�� Ȧ���� �������� �̵�(move==-1)
		}
		else
			col += move; 
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

}