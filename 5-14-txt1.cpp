/**********************************************************
写一个函数计算数字 k 在 0 到 n 中的出现的次数，k 可能是 0 ~ 9
 的一个值。

格式：

输入依次输入一个数字 n，和一个数字 k，最后计算出数字 k 在 0 
到 n 中出现的次数。

样例输入

n=12
k=1

样例输出

5
***********************************************************
算法思想：
	设计一个函数num，统计一个数中含有数字k的个数，再设计一个
函数num_count，n+1次调用num，统计总数
**********************************************************/
#include<stdio.h>
int num(int m,int k)
{	//统计单个数中,出现k的次数
	int count = 0;
	do
	{
		if( m%10==k )
			count ++;
		m /= 10;
	}while( m );
	return count;
}
int num_count(int n,int k)
{	//统计n次,对每个0-n的数统计数字
	int count = 0;
	int i;
	for( i=0;i<=n;i++ )
		count += num(i,k);
	return count;
}
int main()
{
	int k;
	int n;
	printf("输入n的值：");
	scanf("%d",&n);
	printf("输入k的值(0~9)：");
	scanf("%d",&k);
	printf("0到n 数字k出现的次数为:\n");
	printf("%d \n",num_count(n,k));
	return 0;
}