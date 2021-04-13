#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//�迭 ũ�⸦ ���ϱ� ���� ���Ḯ��Ʈ�� �����غôµ� �ƴ�
//��� ���Ͽ��Ḯ��Ʈ�� �����ߴ�.
//���� �߰��� ���ԶǴ� ���� �� �ʿ�� ��� ���Ϸ� �ߵ�
//�Լ��������� ���� �����ͷ� �ϴ°� �����ؾ߰ڴ� �򰥷���
typedef struct node {
	int num;
	struct node* next;
}NODE;
NODE* getnode()
{
	NODE* str = (NODE*)malloc(sizeof(NODE));
	str->next = NULL;
	return str;
}
void print(NODE* H) {
	for (NODE* p = H->next; p != NULL; p = p->next)
		printf("%d ", p->num);
	printf("\n");
}
void appendTerm(NODE** last, int n) {
	NODE* newnode = getnode();
	newnode->num = n;
	(*last)->next = newnode;
	*last = newnode;
}
void change10to2(NODE *H, NODE **last, int n) {
	if (n == 1) //���̽����̽�
		appendTerm(last, 1);
	else {
		change10to2(H, last, n / 2); //���� �۾��� ���̽����̽��� ����
		appendTerm(last, n % 2);
	}
	//����� ���� : 
	//1. ���̽����̽�(��;��� �ذ� ����)
	//2. ���̽����̽��� ���ϴ� ����
}
int main()
{
	int n;
	NODE* H = getnode(), * p, * last = H;
	scanf("%d", &n);
	change10to2(H, &last, n);
	for (p = H->next; p != NULL; p = p->next)
		printf("%d ", p->num);

}