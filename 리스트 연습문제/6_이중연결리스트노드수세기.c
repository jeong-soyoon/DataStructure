#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//��� �� Ʈ���Ϸ� ���߿��Ḯ��Ʈ

typedef struct node {
	int elem;
	struct node* next;
	struct node* prev;
}NODE;
int count(NODE* H, NODE* T) { //�����
	int i = 0;
	for (NODE* p = H->next; p != T; p = p->next)
		i += 1;
	return i;
}
int count(NODE* H, NODE* T) {
	return rcount(H->next, T);
}
int rcount(NODE* f, NODE* l) {
	if (f == l)
		return 0;
	else
		return 1 + rcount(f->next, l);
}