#include <stdio.h>
#pragma warning(disable:4996)
//��Ŭ���� ȣ������ �̿��� �� ������ �ִ����� ���ϱ�
int gcd(int, int);
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
}
int gcd(int a, int b) {
	int big = (a > b) ? a : b;
	int small = (a > b) ? b : a;
	if (a == 0 || b == 0)
		return big;
	else
		gcd(small, big % small);
}