/**********************************************************
随意输入一串字符，统计字符串里大写字母 小写字母与数字的个数
***********************************************************
算法思想：
	随意输入，不能规定字符数上限，无法用数组。所以单个字符
进行判断，并定义3个变量，分别代表小写字母、大写字母、数字的
个数。逐个字符进行统计。
**********************************************************/
#include<stdio.h>
#include<malloc.h>
int Statistics()
{	//字符统计
	int lower = 0;		//小写字母数
	int capital = 0;	//大写字母数
	int number = 0;		//数字数
	char str;			//字符容器，接收输入
	while( (str=getchar())!='\n' )
	{
		if( str>='a' && str<='z' )
		{	//是小写字母，计数并进入下一次循环
			lower++;
			continue;
		}
		if( str>='A' && str<='Z' )
		{	//是大写字母，计数并进入下一次循环
			capital++;
			continue;
		}
		if( str>='0' && str<='9' )//是数字，计数
			number++;
	}
	printf("\n \n");
	printf("大写字母：\t %d \n",lower);
	printf("小写字母：\t %d \n",capital);
	printf("数    字：\t %d \n",number);
	return 1;
}
int main()
{
	Statistics();
	return 0;
}