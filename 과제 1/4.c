#include <stdio.h>
#pragma warning(disable:4996)
/* ����������� �ۼ��� �Լ��� �ݺ������� ���๮�� a/b�� �ݺ��ϰ�,
* ��������� �ۼ��� �Լ��� �ڱ� �ڽ� ȣ���� a/b�� �ݺ��մϴ�.
* ���� Ƚ��������, ���� ����� �� ���길 �ݺ��Ͽ� ���� �޸𸮸� ������� �ʴ� ������� �Լ��� �޸�
* ����� �Լ��� �ݺ������� �ڱ��ڽ��� ȣ���ϱ� ������
* ����Ӹ� �ƴ϶� ���ÿ� ���Ӱ� �Ű����� a,b�� ȣ�� ��ġ�� �����մϴ�.
* ����, ��������� �ۼ��� modulo �Լ��� ����������� �ۼ��� modulo �Լ����� �� �����մϴ�.
*/
int modulo(int a, int b) {
	if (a < b)
		return a;
	else if (b == 0)
		return -1;
	else
		modulo(a - b, b);
}
int main()
{
	int a, b, result;
	scanf("%d %d", &a, &b);
	result = modulo(a, b);
	printf("%d\n", result);
	return 0;
}