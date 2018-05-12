/**********************************************************
设计一个双向循环链表，实现插入，删除，替换等功能
***********************************************************
算法思想：
	先实现初始化和撤销的功能，调试无误后，再实现插入功能。
确认插入的结果无误，则函数的大段代码可以复制。用复制的代码，
再实现取元素、替换元素的功能。
**********************************************************/
#include<stdio.h>
#include<malloc.h>
struct DLnode
{		//双向循环链表
	int date;
	DLnode *next;
	DLnode *prior;
};


int Initiate(DLnode **head)
{		//初始化
	(*head) = (DLnode *)malloc(sizeof(DLnode));
	(*head)->next  = *head;
	(*head)->prior = *head;
	return 1;
}


int Insert(DLnode *head,int pos,int d)
{		//插入元素
	if( pos<0 )
	{
		printf("参数错误<0!\n");
		return 0;
	}
	int i = 0;
	DLnode *p1,*p2 = head;

	while( i<pos )
	{	//此循环进行寻找结点
		if( p1==head )
		{
			printf("参数错误!\n");
			return 0;
		}
		p1 = p2->next;	//结点指针推后
		p2 = p1;
		
		i++;
	}
	DLnode *p = (DLnode *)malloc(sizeof(DLnode));
	p->date = d;		//新结点赋值

	//以下四行进行结点连接
	p->next = p2->next;
	p->next->prior = p2;
	p2->next = p;
	p->prior = p2;
	return 0;
}


int Destroy(DLnode *head)
{		//撤销循环链表
	DLnode *p = head->next;

	while( p!=head )
	{
		head->next = p->next;
		free(p);
		p = head->next;
	}
	free(head);
	return 1;
}


int Replace(DLnode *head,int pos,int d)
{		//结点元素替换
	if( pos<0 )
	{
		printf("参数错误<0!\n");
		return 0;
	}
	int i = 0;
	DLnode *p1,*p2 = head;
	while( i<pos )
	{
		if( p1==head )
		{
			printf("参数错误!\n");
			return 0;
		}
		p1 = p2->next;
		p2 = p1;
		
		i++;
	}
	p2->next->date = d;
	return 0;
}
int Get(DLnode *head,int pos,int *d)
{		//取元素
	if( pos<0 )
	{
		printf("参数错误<0!\n");
		return 0;
	}
	int i = 0;
	DLnode *p1,*p2 = head;

	while( i<pos )
	{	//此循环寻找结点
		if( p1==head )
		{
			printf("参数错误!\n");
			return 0;
		}
		p1 = p2->next;
		p2 = p1;
		
		i++;
	}

	//将该结点的元素赋值给d
	*d = p2->next->date;
	return 1;
}
int main()
{
	//定义并初始化
	DLnode *head;
	Initiate(&head);	//初始化

	int i;
	int x;

	for( i=0;i<=5;i++ )
		Insert(head,i,i);	//元素插入

	Replace(head,3,10);		//元素值替换

	for( i=0;i<=5;i++ )
	{				//取元素，逐个输出
		Get(head,i,&x);
		printf("%d ",x);
	}

	Destroy(head);		//撤销链表
	return 0;
}