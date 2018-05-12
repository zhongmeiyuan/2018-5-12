/*******************************************************
要求键盘随便输入一个十进制数然后转换成十六进制数打印出来
********************************************************
算法思想：
	如同平常计算，逐步取余，最后逆序输出。代码实现，可以
用堆栈，在这只需写初始化、入栈、出栈、非空否、撤销空间，
这几个函数。
*******************************************************/
struct node
{	//堆栈的结构体
	char date;
	node* next;
};


#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>


int Initiate(node **head)
{	//初始化
	if( ((*head) = (node *)malloc(sizeof(node)))==NULL )
		exit(0);

	(*head)->next = NULL;

	return 1;
}


int NotEmpty(node *head)
{	//堆栈非空否
	
	if( head->next==NULL )
		return 0;

	return 1;
}


int Push(node *head,int x)
{	//入栈
	node *p;
	if( (p = (node *)malloc(sizeof(node)))==NULL )
	{
		printf("入栈失败!\n");
		return 0;
	}


	p->next = head->next;
	p->date = x;
	head->next = p;
	
	
	return 1;
}


int Pop(node *head,int *x)
{	//出栈
	if( NotEmpty(head)==0 )
	{	//printf作为调试语句
		printf("堆栈已空！\n");
		return 0;
	}


	node *p = head->next;
	*x = p->date;
	head->next = p->next;


	free(p);
	return 1;
}


int Destroy(node *head)
{	//撤销堆栈链表
	node *p = head->next;


	while( NotEmpty(head) )
	{
		head->next = p->next;
		free(p);
		p = head->next;
	}


	free(p);
	free(head);
	return 1;
}


int main()
{
	int num;
	int x;		//出栈,作为数字的容器
	node *head;
	Initiate(&head);


	printf("请输入一个十进制数: \t");
	scanf("%d",&num);	//输入十进制数
	printf("即将转换为十六进制数:\n \t \t\t");


	while( num )	//计算，并按顺序入栈
	{
		x = num%16;
		Push(head,x);
		num /= 16;
	}


	while( NotEmpty(head) )
	{	//逆序出栈
		Pop(head,&x);
		printf("%X",x);
	}
	printf("\n");


	Destroy(head);	//撤销堆栈链表
	return 0;
}