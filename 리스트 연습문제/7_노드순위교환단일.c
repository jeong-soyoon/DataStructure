#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	return ptr;
}
void swap1(NODE *H,NODE* p, NODE* q) {
	NODE* ptr, * pprev= NULL, * qprev=NULL, * pnext;
	for (ptr = H; ptr != NULL; ptr = ptr->next) { //���Ͽ��Ḯ��Ʈ���� p�� q�� �� ��忡 ������ ���� ��� pprev�� qprev�� �����ϱ�� �ߴ�!
		if (ptr->next == p) 
			pprev = ptr;
		if (ptr->next == q)
			qprev = ptr;
		if (pprev != NULL && qprev != NULL) //�Ѵ� ä������ Ż��
			break;
	}
	pprev->next = q; //p�� q�� ����Ű�� �ִ� ���� ��ũ���� ����
	qprev->next = p;
	pnext = p->next; //p->next�� �ٲ�� ������ ����� ���⿡ ����
	p->next = q->next; //p�� q�� ��ũ�� �ٲ���
	q->next = pnext;
}
void print(NODE* H) {
	for (NODE* ptr = H->next; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->elem);
}
int main() {
	NODE* H = getnode(), * last = H, * nn, * node1, * node2;
	for (int i = 0; i < 3; i++) {
		nn = getnode();
		nn->elem = i;
		last->next = nn;
		last = nn;
	}
	node1 = H->next;
	node2 = H->next->next->next;
	swap1(H, node1, node2);
	print(H);
}