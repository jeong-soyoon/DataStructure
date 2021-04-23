#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//4���� ��� �ǽ����� 5��
void hanoi(int n, char from, char aux, char to) {
	if (n == 1)
		printf("%c %c\n", from, to);
	else {
		hanoi(n - 1, from, to, aux);
		printf("%c %c\n", from, to);
		hanoi(n - 1, aux, from, to);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}