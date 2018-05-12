/*************************************************************
九名运动员参加比赛，需要分3组进行预赛。
有哪些分组的方案呢？
我们标记运动员为 A,B,C,... I
下面的程序列出了所有的分组方法。


该程序的正常输出为：
ABC DEF GHI
ABC DEG FHI	
ABC DEH FGI
ABC DEI FGH
ABC DFG EHI
ABC DFH EGI
ABC DFI EGH
ABC DGH EFI
ABC DGI EFH
ABC DHI EFG
ABC EFG DHI
ABC EFH DGI
ABC EFI DGH
ABC EGH DFI
ABC EGI DFH
ABC EHI DFG
ABC FGH DEI
ABC FGI DEH
ABC FHI DEG
ABC GHI DEF
ABD CEF GHI
ABD CEG FHI
ABD CEH FGI
ABD CEI FGH
ABD CFG EHI
ABD CFH EGI
ABD CFI EGH
ABD CGH EFI
ABD CGI EFH
ABD CHI EFG
ABD EFG CHI

..... (以下省略，总共560行)。
**************************************************************
算法思想：
	如果只是分组，应该是280种，而这里包含了排列.
	首先，如果第一队成员已经确认，后两队的组合有10种，加上排列
有20种，设计一个函数behind()实现这一部分。
	再实现第一队成员的确认，C93/A32，由于只有组合，不需要排列，
假设第一队含有A，则再确定一个成员、确定除此之外的第三个成员，
代码中调用函数behind()即可。
*************************************************************/
#include<stdio.h>
int count = 0;		//计数变量
char group[3][4] = {{'A','B','C',' '},{'D','E','F',' '},{'G','H','I',' '}};


int exchange(char *a,char *b)
{	//交换
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}


int line_exchange(int m,int n)
{	//队伍交换(后两队的排列)
	int i;
	for( i=0;i<3;i++ )
		exchange(&group[m][i],&group[n][i]);
	return 0;
}
int behind(int m,int n)
{	//后两队排序(假设第一队成员已经确定了)
	printf("%s %4d\n",group,count+1);
	count++;	//输出当前队列,并计数

	line_exchange(1,2);	//交换队伍，再次输出、计数
	printf("%s %4d\n",group,count+1);
	line_exchange(1,2);
	count++;
	
	int i,j;
	for( i=2;i>=0;i-- )
	{
		for( j=0;j<3;j++ )
		{
			//第三行和第二行，单个交换
			//输出并计数(当前循环结束前，会交换回来)
			exchange(&group[m][i],&group[n][j]);
			printf("%s %4d\n",group,count+1);
			count++;


			line_exchange(1,2);	//队伍交换，输出并计数
			printf("%s %4d\n",group,count+1);
			line_exchange(1,2);
			count++;
			
			//交换回之前的状态
			exchange(&group[m][i],&group[n][j]);
		}
	}
	return 0;
}
int before(int m,int n)	
	//m、n代表第一队第二个成员，在最初始数组中的位置
{	//第一队成员的改变(这个函数中，只改变第三个成员)
	int i,j;

	behind(1,2);	//改变之前，将当前的后两队排列输出
	printf("\n");


	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{	
			//若大于第二成员，则作为第三成员
			//(题目只需要组合，是为了排除排列的影响)
			if( (i!=m || j!=n) && group[i][j]>group[0][1] )
			{
				//将符合的队员，作为第一队成员，再进行后两队排列
				//当前循环的末尾，会交换回来
				exchange(&group[0][2],&group[i][j]);
				behind(1,2);
				printf("\n");
				exchange(&group[0][2],&group[i][j]);
			}
		}
	}
	return 0;
}
int rank()
{	//所有选手的排列,此函数主要设置第一队的第二成员

	before(-1,-1);	//将改变之前的状态输出


	int i,j = 0;	//再进行改变
	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{
			//将后六个队员，逐个作为第一队成员进行排列
			exchange(&group[0][1],&group[i][j]);
			before(i,j);
			exchange(&group[0][1],&group[i][j]);
		}
	}
	return 0;
}
int main()
{	
	rank();		//开始排序
	printf("%d \n",count);	//输出总数
	return 0;
}