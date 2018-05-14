/******************************************************************
给一个整数数组，写一个函数实现在数组中找到第 k 大的元素。

注意事项：

你可以交换数组中的元素的位置。

格式：

输入依次输入一个整数数组和一个整数 k ，最后输出数组中第 k 大的元素。

样例输入

[ 9，3，2，6，11 ]
k = 1

样例输出

11
*******************************************************************
算法思想：
	只要将数组进行有序排列，输出num[n-1]即可。
	设计rank函数，将数组由大到小排序，再输出num[n-1]
******************************************************************/
#include<stdio.h>


int rank(int num[],int n)
{	//排序——由大到小
	int i,j;
	int temp;
	for( i=0;i<n;i++ )
	{
		for( j=i+1;j<n;j++ )
		{
			if( num[i]<num[j] )
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	return 0;
}


int input(int num[])
{	//输入数组元素的值
	int count = 0;
	char ch;
	do
	{
		scanf("%d",&num[count]);
		count ++;
	}while( (ch = getchar())!='\n' );
	return count;
}


int num_output(int num[],int n)
{	//输出第n大的值
	printf("%d \n",num[n-1]);
	return 0;
}


int main()
{
	int num[20] = {0};
	int count;
	int n;

	printf("设置数组元素：\n");
	count = input(num);	//输入数组的值

	rank(num,count);	//由大到小排序

	printf("即将输出第n大的值,请设置n的值:");

	scanf("%d",&n);		//设置n的值

	num_output(num,n);	//输出第n大值

	return 0;
}