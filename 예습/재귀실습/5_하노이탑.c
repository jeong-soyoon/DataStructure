#include <stdio.h>
#pragma warning(disable:4996)
//�ϳ���ž
void hanoi(int n, int start, int end);
int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 3);
}
void hanoi(int n, int start, int end) {
	if (n == 1)
		printf("%c %c\n", 'A' - 1 + start, 'A' - 1 + end); //������ �ϳ��� ���̷�Ʈ
	else {
		hanoi(n - 1, start, 6 - start - end); //�� �����̸� �������� ���������� �ƴ� B(6-start-end)�� �����ٳ�
		hanoi(1, start, end); //�� �Ʒ� ������ ������ ���� �����ٳ�
		hanoi(n - 1, 6 - start - end, end); //�� �����̵��� ������ ���� �����ٳ�
	}
}