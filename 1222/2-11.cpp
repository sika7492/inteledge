#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int k, n = 0;
	int sum = 0;
	printf("������ �Է��ϼ���>>");
	scanf("%d", &n);
	for (k = 1; k <= n; k++)
	{
		sum += k;

	}
	printf("1���� %d������ ���� %d�Դϴ� \n", n, sum);
	return 0;


}