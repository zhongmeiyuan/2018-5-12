/***************************************************************
625 这个数字很特别，625 的平方等于390625,刚好其末3 位是625 本身。
除了625,还有其它的3 位数有这个特征吗?请编写程序，寻找所有这样的
3 位数:它的平方的末3 位是这个数字本身。输出结果中，从小到大，每
个找到的数字占- 一行。比如那个625就输出为: 625
****************************************************************
算法思想：
	平方的末3位是本身。首先，个位数必须是1,5,6或0。
	再看末2位，经过for循环运算，个位数为1或0时，末2位必定不同；
个位数为5时，25符合；个位数为6时，76符合。接下来就好玩了，只有末
尾2位为25或76时，才可能符合答案。
***************************************************************/
#include<stdio.h>
int main()
{
	int a = 125;
	while( a<1000 )
	{	//检测末2位为25的数
		if( a*a%1000==a )
			printf("%d \n",a);
		a += 100;
	}
	a = 176;
	while( a<1000 )
	{	//检测末2位为76的数
		if( a*a%1000==a )
			printf("%d \n",a);
		a += 100;
	}
	return 0;
}