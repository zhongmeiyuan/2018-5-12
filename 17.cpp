/*******************************************************
请编写一个程序，输入一个M行N列的二维数组，要求打印出该
二维数组的转置
********************************************************
算法思想：
	将每列数据当做一行输出，总共输出N行数据
*******************************************************/
#include<stdio.h>
#include<malloc.h>
int transposition_output(int **num,int m,int n)
{	//以转置的形式输出
	int i,j;
	for( i=0;i<n;i++ )
	{		//先输出列，每列换行，每行输出一列
		for( j=0;j<m;j++ )
		{
			printf("%4d ",num[j][i]);
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	int m,n;
	int **num;
	int i,j;
	
	
	printf("即将设置一个m行，n列的数组,\n");
	printf("请设置m,n的值(空格隔开):");
	scanf("%d %d",&m,&n);	//输入m,n，确认行列数


	num = (int **)malloc(sizeof(int)*m);
	for( i=0;i<m;i++ )		//申请数组空间m*n
		num[i] = (int *)malloc(sizeof(int)*n);


	printf("接下来确定矩阵元素：\n");
	for( i=0;i<m;i++ )
	{						//设置数据元素
		for( j=0;j<n;j++ )
			scanf("%d",&num[i][j]);
	}


	transposition_output(num,m,n);	//转置输出


	for( i=0;i<m;i++ )		//撤销申请空间
		free(num[i]);
	return 0;
}