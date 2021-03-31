#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int n, m, ** arr, i, num, row = 0, col = 0, startrow = 0, startcol = 0, j;
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int)); 
	num = 1;
	while (num<=n*m) {
		row = startrow; //�밢�� ���� �� ��ȣ���� ����
		col = startcol; //�밢�� ���� �� ��ȣ���� ����
		while (0 <= row && row < n && 0 <= col && col < m) //���� �ȿ� ������
			arr[row++][col--] = num++; //�밢������ �̵��ϸ� ���� ä��
		if (startcol == m - 1) //�밢�� ���� ��, �� ��ȣ ����
			startrow++;
		else
			startcol++;
	}
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++)
			printf(" %d", arr[i][j]); //���
		printf("\n");
		free(arr[i]); //�޸� ����
	}
	free(arr); //�޸� ����
}