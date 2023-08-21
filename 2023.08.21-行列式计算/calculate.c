#define  _CRT_SECURE_NO_WARNINGS  1
#pragma  warning(disable:6031)

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main()
{
	int n;
	int** p = NULL;
	int i, j;
	int x;
	printf("输入阶数");
	scanf("%d", &n);
	p = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * n);
		memset(p[i], 0, sizeof(int) * n);
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &p[i][j]);
	x = det(p, n);
	printf("%d", x);
	for (i - 0; i < n; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
	return 0;
}

int det(int** p, int n)
{
	int i, j, k;
	int cons = 0;
	int** c = (int**)malloc(sizeof(int) * (n - 1));
	if (!c)
	{
		printf(strerror(errno));
		return 114514;
	}
	for (i = 0; i < n - 1; i++)
	{
		c[i] = (int*)malloc(sizeof(int) * (n - 1));
		if (!c[i])
		{
			printf(strerror(errno));
			return 114514;
		}
		memset(c[i], 0, sizeof(int) * (n - 1));
	}
	if (n == 1)
		return p[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
			for (k = 0; k < n - 1; k++)
			{
				c[j][k] = (k < i ? p[j + 1][k] : p[j + 1][k + 1]);
				cons += pow(-1, i) * p[0][i] * det(c, n - 1);
			}
	}
	for (i = 0; i < n - 1; i++)
	{
		free(c[i]);
		c[i] = NULL;
	}//这里本应free(c)，但是这个语句无论如何也跑不过去，不知道为什么
	return cons;
}