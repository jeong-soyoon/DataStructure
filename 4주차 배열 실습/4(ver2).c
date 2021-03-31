#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//�Լ� ���
int moveleftright(int** arr, int *num, int *col, int *row, int move, int limit) { //�¿�� �̵�
	while (1) {
		arr[*row][*col] = (*num)++;
		if (*col == limit || arr[*row][*col + move] != 0) { // �� ��ȣ�� limit�� �����߰ų� ������� �ʴٸ�(0�� �ƴ϶��)
			*row += move;
			return 0;
		}
		*col += move; //�� ���� �Ǵ� ����
	}
}
int moveupdown(int** arr, int* num, int* col, int* row, int move, int limit) { //�Ʒ����� �̵�
	while (1) {
		arr[*row][*col] = (*num)++;
		if (*row == limit || arr[*row + move][*col] != 0) { //�� ��ȣ�� limit�� �����߰ų� ������� �ʴٸ�(0�� �ƴ϶��)
			*col -= move; 
			return 0;
		}
		*row += move; //�� ���� �Ǵ� ����
	}
}
int main()
{
	int n, m, ** arr, i, j, row = 0, col = 0, mode, num;
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			arr[i][j] = 0;
	}
	num = 1;
	mode = 0;
	while (num <= n * m) {
		if (mode % 4 == 0) //������ �̵�(�� ����)
			moveleftright(arr, &num, &col, &row, 1, m - 1);
		else if (mode % 4 == 1) //�Ʒ��� �̵�(�� ����)
			moveupdown(arr, &num, &col, &row, 1, n - 1);
		else if (mode % 4 == 2) //���� �̵�(�� ����)
			moveleftright(arr, &num, &col, &row, -1, 0);
		else //���� �̵�(�� ����)
			moveupdown(arr, &num, &col, &row, -1, 0);
		mode++;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
}
/* �Լ� ��� x
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main()
{
	int n, m, ** arr, i, j, row = 0, col = 0, mode = 0, move, limit_ud, limit_lr;
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			arr[i][j] = 0;
	}
	move = 1;
	limit_ud = n - 1;
	limit_lr = m - 1;
	for (i = 1; i <= n * m; i++) {
		arr[row][col] = i;
		if (mode%2== 0) { //�¿�� �̵�
			if (col == limit_lr || arr[row][col+move] != 0 ) {
				mode += 1; //���� �̵����� ��ȯ
				row += move; //�� ���� �Ǵ� ����
				limit_lr = m- 1 - limit_lr; //limit_lr ��ȯ
				continue;
			}
			col += move; //�� ���� �Ǵ� ����
		}
		else{ //�Ʒ����� �̵�
			if (row == limit_ud || arr[row+move][col] != 0) {
				mode += 1; //���� �̵����� ��ȯ
				move = -move; //����->���� �Ǵ� ����->����
				col += move; //�� ���� �Ǵ� ����
				limit_ud = n - 1 - limit_ud; //limit_ud ��ȯ
				continue;
			}
			row += move; //�� ���� �Ǵ� ����
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

	//        move  limit_lr limit_ud
	// right  +1      m-1       x
	// left   -1      0         x
	// up     +1      x         0
	// down   -1      x        n-1
}*/