/*******************************************************
Ҫ������������һ��ʮ������Ȼ��ת����ʮ����������ӡ����
********************************************************
�㷨˼�룺
	��ͬƽ�����㣬��ȡ�࣬����������������ʵ�֣�����
�ö�ջ������ֻ��д��ʼ������ջ����ջ���ǿշ񡢳����ռ䣬
�⼸��������
*******************************************************/
struct node
{	//��ջ�Ľṹ��
	char date;
	node* next;
};


#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>


int Initiate(node **head)
{	//��ʼ��
	if( ((*head) = (node *)malloc(sizeof(node)))==NULL )
		exit(0);

	(*head)->next = NULL;

	return 1;
}


int NotEmpty(node *head)
{	//��ջ�ǿշ�
	
	if( head->next==NULL )
		return 0;

	return 1;
}


int Push(node *head,int x)
{	//��ջ
	node *p;
	if( (p = (node *)malloc(sizeof(node)))==NULL )
	{
		printf("��ջʧ��!\n");
		return 0;
	}


	p->next = head->next;
	p->date = x;
	head->next = p;
	
	
	return 1;
}


int Pop(node *head,int *x)
{	//��ջ
	if( NotEmpty(head)==0 )
	{	//printf��Ϊ�������
		printf("��ջ�ѿգ�\n");
		return 0;
	}


	node *p = head->next;
	*x = p->date;
	head->next = p->next;


	free(p);
	return 1;
}


int Destroy(node *head)
{	//������ջ����
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
	int x;		//��ջ,��Ϊ���ֵ�����
	node *head;
	Initiate(&head);


	printf("������һ��ʮ������: \t");
	scanf("%d",&num);	//����ʮ������
	printf("����ת��Ϊʮ��������:\n \t \t\t");


	while( num )	//���㣬����˳����ջ
	{
		x = num%16;
		Push(head,x);
		num /= 16;
	}


	while( NotEmpty(head) )
	{	//�����ջ
		Pop(head,&x);
		printf("%X",x);
	}
	printf("\n");


	Destroy(head);	//������ջ����
	return 0;
}