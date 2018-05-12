/******************************************************************
一个整数的"反置数"指的是把该整数的每一位数字的顺序颠倒过来所得到
的另一个整数。如果一个整数的末尾是以0为结尾，那么在他的反置数当中
，这些0就被省略掉了。比如说：1245的反置数是5421，而1200的反置
数就是21。请编写一个程序，输入两个整数，然后计算这两个整数的反置
数之和sum，然后再把sum的反置数打印出来。要求：由于在本题中需要多次
去计算一个整数的反置数，因此必须把这部分代码抽象为一个函数的形式
*******************************************************************
*******************************************************************
算法思想：
	先求出数据的数字位数length，再开辟一个长度为length的数组，将数据
的各个数字从低位到高位，存入数组中。再将数组的数字逐个逆序还原，将新
的值赋给函数的返回值。
	主函数，定义两个数，分别调用函数，最后将返回值相减，得到结果。
******************************************************************/
#include<stdio.h>
#include<malloc.h>
int length_of(int n)
{	//求数字的位数
	int length = 0;
	while( n )
	{
		n /= 10;
		length ++;
	}
	return length;
}
int pow(int m,int n)
{	//整数幂函数
	int f;
	if( n==0 )
		f = 1;
	else if( n==1 )
		f = m;
	else
		f = m * pow(m,n-1);
	return f;
}
int change(int num)
{
	int length;
	length = length_of(num);
	int *number;	//申请数组，元素个数等于数字位数
	number = (int *)malloc(sizeof(int)*length);


	int i;	//数字逐个存入数组中，低位到高位
	for( i=0;i<length;i++ )
	{
		number[i] = num%10;
		num /= 10;
	}		//存入结束，此时num==0

	int j = 0;
	for( i=length-1;i>=0;i-- )
	{		//逆序恢复数据
		if( !(number[i]==0 &&i==0) )
		{
			num += number[i] * pow(10,j);
			j++;
		}
	}
	free(number);
	return num;
}
int main()
{
	int m,n;
	printf("输入两个数(m n)：");
	scanf("%d %d",&m,&n);	//设置需要转换的数

				//转换为反置数
	m = change(m);
	n = change(n);

				//输出结果
	printf("%d - %d = %d \n",m,n,m - n);
	return 0;
}