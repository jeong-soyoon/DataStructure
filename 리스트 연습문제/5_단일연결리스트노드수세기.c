#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//���Ͽ��Ḯ��Ʈ

typedef struct node {
	int elem;
	struct node* next;
}NODE;
int count(NODE* L) { //�����
	int i = 0;
	for (NODE* p = L; p != NULL; p=p->next)
		i += 1;
	return i;
}
int count(NODE* L) { //���
	if (L->next == NULL) //���̽����̽�(��尡 �ϳ��ۿ� ������)
		return 1;
	else
		return 1 + count(L->next); //��������ؼ� �Լ� ȣ��->���̽����̽��� ���� ���� ��

}
