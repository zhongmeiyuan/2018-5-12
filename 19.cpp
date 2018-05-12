/**********************************************************
���һ��˫��ѭ������ʵ�ֲ��룬ɾ�����滻�ȹ���
***********************************************************
�㷨˼�룺
	��ʵ�ֳ�ʼ���ͳ����Ĺ��ܣ������������ʵ�ֲ��빦�ܡ�
ȷ�ϲ���Ľ�����������Ĵ�δ�����Ը��ơ��ø��ƵĴ��룬
��ʵ��ȡԪ�ء��滻Ԫ�صĹ��ܡ�
**********************************************************/
#include<stdio.h>
#include<malloc.h>
struct DLnode
{		//˫��ѭ������
	int date;
	DLnode *next;
	DLnode *prior;
};


int Initiate(DLnode **head)
{		//��ʼ��
	(*head) = (DLnode *)malloc(sizeof(DLnode));
	(*head)->next  = *head;
	(*head)->prior = *head;
	return 1;
}


int Insert(DLnode *head,int pos,int d)
{		//����Ԫ��
	if( pos<0 )
	{
		printf("��������<0!\n");
		return 0;
	}
	int i = 0;
	DLnode *p1,*p2 = head;

	while( i<pos )
	{	//��ѭ������Ѱ�ҽ��
		if( p1==head )
		{
			printf("��������!\n");
			return 0;
		}
		p1 = p2->next;	//���ָ���ƺ�
		p2 = p1;
		
		i++;
	}
	DLnode *p = (DLnode *)malloc(sizeof(DLnode));
	p->date = d;		//�½�㸳ֵ

	//�������н��н������
	p->next = p2->next;
	p->next->prior = p2;
	p2->next = p;
	p->prior = p2;
	return 0;
}


int Destroy(DLnode *head)
{		//����ѭ������
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
{		//���Ԫ���滻
	if( pos<0 )
	{
		printf("��������<0!\n");
		return 0;
	}
	int i = 0;
	DLnode *p1,*p2 = head;
	while( i<pos )
	{
		if( p1==head )
		{
			printf("��������!\n");
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
{		//ȡԪ��
	if( pos<0 )
	{
		printf("��������<0!\n");
		return 0;
	}
	int i = 0;
	DLnode *p1,*p2 = head;

	while( i<pos )
	{	//��ѭ��Ѱ�ҽ��
		if( p1==head )
		{
			printf("��������!\n");
			return 0;
		}
		p1 = p2->next;
		p2 = p1;
		
		i++;
	}

	//���ý���Ԫ�ظ�ֵ��d
	*d = p2->next->date;
	return 1;
}
int main()
{
	//���岢��ʼ��
	DLnode *head;
	Initiate(&head);	//��ʼ��

	int i;
	int x;

	for( i=0;i<=5;i++ )
		Insert(head,i,i);	//Ԫ�ز���

	Replace(head,3,10);		//Ԫ��ֵ�滻

	for( i=0;i<=5;i++ )
	{				//ȡԪ�أ�������
		Get(head,i,&x);
		printf("%d ",x);
	}

	Destroy(head);		//��������
	return 0;
}