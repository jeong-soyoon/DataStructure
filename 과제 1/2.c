#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

/* �Ʒ��� �ҽ��ڵ�� ASS,IND, EXP ���� �����۾��� ����Ǿ���,
   ���ӵǾ� �����Ƿ� �̵� �� �Է¹��ڿ��� ���� n�� ���Ͽ� �ִ������� ���� ���� �����Ͽ� Big-Oh�� ���ϰڴ�.
   �ҽ��ڵ� �� �ִ� ����ð��� �����ϴ� ���� ���ڿ��� ���� �ݺ����̴�.
   �־��� ���, for�� ���� 1��° if���� ����ġ�� ���ϰ� search �Լ��� ȣ���Ͽ�
   search���� �ݺ����� ���� ��ø�ݺ����� �����ϰ� �ȴ�.
   ����, �������� ���� �������� ���� Ż���ϸ� �� �ҽ��ڵ��� Big-Oh = O(n*n)�̴�.
*/
int search(char*, int start, int end, char);
int main()
{
	char str[101], end;
	int i, j;
	gets_s(str, 101);
	end = strlen(str) - 1;
	for (i = 0; str[i]; i++) {
		if (str[i] == ' ')
			continue;
		if (search(str, 0, i - 1, str[i]) == 0) {
			if (search(str, i + 1, end, str[i]) == 1)
				printf("%c ", str[i]);
		}
		else
			continue;
	}

}
int search(char*str, int start, int end,char ch) {
	int i;
	for (i = start; i <= end; i++) {
		if (str[i] == ch)
			return 1;
	}
	return 0;
}