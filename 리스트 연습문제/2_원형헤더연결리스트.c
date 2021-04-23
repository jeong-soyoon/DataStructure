#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* initialize() {
	NODE* H = (NODE*)malloc(sizeof(NODE));
	H->next = H; 
	return H;
}
void traverse(NODE* H) {
	NODE* p = H->next; //�ݺ��� Ż�� ������ H��� ���� ���� ������Ḯ��Ʈ�� �ٽ�
	while (p != H) { //while ����
		visit(p);
		p = p->next;
	}
	for (p = H->next; p != H; p = p->next) //for����
		visit(p);
}
int main() {
	NODE* H = initialize();

}