#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int k, n = 0;
	int sum = 0;
	printf("끝수를 입력하세요>>");
	scanf("%d", &n);
	for (k = 1; k <= n; k++)
	{
		sum += k;

	}
	printf("1에서 %d까지의 합은 %d입니다 \n", n, sum);
	return 0;


}