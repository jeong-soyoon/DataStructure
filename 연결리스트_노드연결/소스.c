#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct NODE {
	char name[21];
	int grade;
	struct NODE* next;
}NODE;

NODE* getnode() {
	NODE* ptr;
	ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	return ptr;
}
int main() {
	NODE* list = NULL, * last = NULL, * p = NULL, * pnext;
	NODE* newnode, input;
	scanf("%s %d", input.name, &input.grade); //ù ��� �Է¹ޱ�
	if (strcmp(input.name, "0") != 0) {
		newnode = getnode();
		strcpy(newnode->name, input.name); //�Է¹��� �� �� ����
		newnode->grade = input.grade;
		list = newnode; //ù ��� �ּҸ� list�� ����
		last = newnode; //������ ���� ù ��� ����
	}

	scanf("%s %d", input.name, &input.grade);
	while (strcmp(input.name, "0") != 0) {
		newnode = getnode();
		strcpy(newnode->name, input.name); //�Է¹��� �� �� ����
		newnode->grade = input.grade;

		last->next = newnode; //�� �������� ����
		last = last->next; //�� ������ ��� ����

		scanf("%s %d", input.name, &input.grade); //�ٽ� �Է¹ޱ�
	}

	p = list; //�� ù ���
	while (p) {
		printf("%s %d\n", p->name, p->grade); //Ȯ��
		p = p->next;
	}

	p = list; //�� ù ���
	while (p) {
		pnext = p->next; //p�� �޸𸮰� �����Ǳ� �� pnext�� ���� ��� �ּ� ����
		printf("%s\n", p->name);
		free(p); //p �޸� ����
		p = pnext; //���� ��带 �����ϱ� ���� p ����
	}



}