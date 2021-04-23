#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* �Ʒ��� �ҽ��ڵ�� ASS,IND, EXP ���� �����۾��� ����Ǿ���,
   ���ӵǾ� �����Ƿ� �̵� �� �Է�ũ�� n�� ���Ͽ� �ִ������� ���� ���� �����Ͽ� Big-Oh�� ���ϰڴ�.
   �ҽ��ڵ� �� �ִ� ����ð��� �����ϴ� ���� 1���� n-1���� �迭�� ���鼭 max�� min�� ���ϴ� �ݺ����̴�.
   �������� ���� �������� ���� ��� Ż���ǰ� n-1�� �ݺ��ϱ� ������ �� �ҽ��ڵ��� Big-Oh = O(n) �̴�.
*/
int main() {
	int n, * arr, i, max, min;
	scanf("%d", &n); 
	arr = (int*)malloc(n * sizeof(int)); 
	for (i = 0; i < n; i++)  
		scanf("%d", arr + i); 
	max = arr[0];
	min = arr[0];
	for (i = 1; i < n; i++) { 
		if (max < arr[i]) 
			max = arr[i];
		else if (min > arr[i])
			min = arr[i];
	}
	printf("%d %d", max, min);
	free(arr);
	
}