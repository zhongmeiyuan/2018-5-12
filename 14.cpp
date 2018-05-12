/***********************************************************
请编写一个程序，输入三个整数，要求实现对这三个整数进行排序
************************************************************
算法思想：
	由用户输入3个数，选择排序方式，0由小到大，1由大到小。
	排序函数先由小到大排序。
	若选择了由小到大，直接输出；选择了由大到小，首尾元素交换
***********************************************************/
#include<stdio.h>
int exchange(int *a,int *b)
{					//函数——两数交换
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
int rank(int num[],int way)
{	//三数排序,way==0表示由小到大，way==1表示由大到小

	//以下4句，进行由小到大排序
	if( num[0]>num[1] )
		exchange(&num[0],&num[1]);
	if( num[0]>num[2] )
		exchange(&num[0],&num[2]);
	if( num[1]>num[2] )
		exchange(&num[1],&num[2]);


	//若way==1,将首尾元素交换，实现由大到小
	if( way==1 )
		exchange(&num[0],&num[2]);


	return 0;
}
int main()
{
	int i;
	int way;
	int num[3];		//三个数的容器


	printf("请输入3个数：");
	for( i=0;i<3;i++ )			//设置3个数
		scanf("%d",&num[i]);

	printf("排序方式如下：\n");
	printf("\t 0.由小到大 \t 1.由大到小 \n");
	printf("请选择排序方式：");
	scanf("%d",&way);			//选择排序方式
	if( way!=0 && way!=1 )
	{
		printf("选择错误！\n");
		return 0;
	}

	rank(num,way);			//开始排序

	printf("排序结果：");
	for( i=0;i<3;i++ )			//输出排序结果
		printf("%d ",num[i]);
	printf("\n");

	return 0;
}