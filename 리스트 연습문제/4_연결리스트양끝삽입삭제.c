#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//��� �� Ʈ���Ϸ� ���߿��Ḯ��Ʈ
typedef struct node {
	int elem;
	struct node* next;
	struct node* prev;
}NODE;
NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}
NODE* addFirst(NODE* H, int e) {
	NODE* newnode = getnode();
	newnode->elem = e;
	newnode->prev = H; //���� newnode�� ��ũ ����
	newnode->next = H->next;
	H->next->prev = newnode; //H->next�� ���� �ǵ帮�� H->next->prev�� �ǵ帮�� �������
	H->next = newnode;
	return newnode;
}
NODE* addLast(NODE* T, int e) { //���� ���� 4���� ��ũ ����
	NODE* newnode = getnode();
	newnode->elem = e;
	newnode->prev = T->prev; //���� newnode�� ��ũ ����
	newnode->next = T;
	T->prev->next = newnode; //T->prev�� ���� �ǵ帮�� H->next->prev�� �ǵ帮�� �������
	T->prev = newnode;
	return newnode;
}
int removeFirst(NODE* H) {
	NODE* p = H->next; //��ǥ ��� �ּ� ����
	int e = p->elem;
	p->prev->next = p->next; //��ũ ����
	p->next->prev = p->prev;
	/*
	H->next = p->next;
	p->next->prev = H; �̷��� p->prev�� H�� ��ü�ص� ����*/
	free(p); //�޸� ����
	return e;
}
int removeLast(NODE* T) {
	NODE* p = T->prev; //��ǥ ��� �ּ� ����
	int e = p->elem; 
	p->prev->next = p->next; //��ũ ����
	p->next->prev = p->prev;
	/*
	p->prev->next = T;
	T->prev = p->prev; �̷��� p->next�� T�� ��ü�ص� ����*/
	free(p); //�޸� ����
	return e;
}
