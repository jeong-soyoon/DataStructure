#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//��ģ���� ������ ������鼭 ��Ծ��İ� �̫��İ�,, ����/���� == ���ΰ� ���� �𸣳ı�... 
//�Ʊ׸��� (int)(n+0.5)���� �ݿø��ϴ°� �������~!!

//ver2. 
void prefixAverages1(int [], int, int []);
void prefixAverages2(int [], int, int []);

int main()
{
	int n, * X, i, * p = NULL, * j;
	scanf("%d", &n);
	X = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", X + i);
	p = (int*)malloc(n * sizeof(int)); //p �����Ҵ�
	prefixAverages1(X, n, p); //p�� �����Ͽ� p�� ���� �־��ֱ�
	for (i = 0; i < n; i++)
		printf("%d ", p[i]); //�迭 p ���
	printf("\n");
	prefixAverages2(X, n, p);//p�� �����Ͽ� p�� ���� �־��ֱ�
	for (i = 0; i < n; i++)
		printf("%d ", p[i]); //�迭 p ���
	free(p); //�޸� ����
	free(X);

}
void prefixAverages1(int X[], int n, int p[]) {
	double sum;
	int i, j;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		p[i] = (int)(sum / (i + 1)+0.5); //�ݿø�..�̤̤�
	}
}
void prefixAverages2(int X[], int n, int p[]) {
	double sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += X[i];
		p[i] = (int)((sum / (i + 1))+0.5); //�ݿø�..�̤̤�
	}
}