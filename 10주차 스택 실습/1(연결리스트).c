#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	char c;
	int idx;
	struct node* next;
}NODE;

void push(NODE** stack, int index, char ch) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->idx = index;
	nn->c = ch;
	nn->next = *stack;
	*stack = nn;
}
char pop(NODE** stack) {
	NODE* tmp = *stack;
	*stack = (*stack)->next;
	return tmp->c;
}
int check(int index, char* str) {
	char oper[11] = "*/+-><&|()";
	int rank[10] = { 5,5,4,4,3,3,2,1,0,0 };
	if (str[index] == '!' || str[index] == "+" || str[index] == '-') {
		if((index == 0 || str[index - 1] < 'A' || str[index - 1]>'Z') && str[index - 1] != ')')
			return 6;
	}
	int i;
	for (i = 0; i < 10; i++) {
		if (str[index] == oper[i])
			break;
	}
	return rank[i];
}
void convert(char* str) {
	NODE* stack = NULL;
	for (int i = 0; i<strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			printf("%c", str[i]);
		else if (str[i] == '(')
			push(&stack, i, str[i]);
		else if (str[i] == ')') {
			while (stack->c != '(') {
				printf("%c", pop(&stack));
				//printf("%c\n", stack->c);
			}

			pop(&stack);
		}
		else { //�������� ��
			while(stack!=NULL && check(i, str)<= check(stack->idx, str))
				printf("%c", pop(&stack));
			push(&stack, i, str[i]);
			if (str[i] == '&' || str[i] == '|')
				push(&stack,++i,str[i]);
		}
	}
	while (stack!=NULL)
		printf("%c", pop(&stack));

	printf("\n");
}
int main() {
	int N;
	char str[101];
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		convert(str);
	}
}