/*******************************************************
���дһ����������һ��M��N�еĶ�ά���飬Ҫ���ӡ����
��ά�����ת��
********************************************************
�㷨˼�룺
	��ÿ�����ݵ���һ��������ܹ����N������
*******************************************************/
#include<stdio.h>
#include<malloc.h>
int transposition_output(int **num,int m,int n)
{	//��ת�õ���ʽ���
	int i,j;
	for( i=0;i<n;i++ )
	{		//������У�ÿ�л��У�ÿ�����һ��
		for( j=0;j<m;j++ )
		{
			printf("%4d ",num[j][i]);
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	int m,n;
	int **num;
	int i,j;
	
	
	printf("��������һ��m�У�n�е�����,\n");
	printf("������m,n��ֵ(�ո����):");
	scanf("%d %d",&m,&n);	//����m,n��ȷ��������


	num = (int **)malloc(sizeof(int)*m);
	for( i=0;i<m;i++ )		//��������ռ�m*n
		num[i] = (int *)malloc(sizeof(int)*n);


	printf("������ȷ������Ԫ�أ�\n");
	for( i=0;i<m;i++ )
	{						//��������Ԫ��
		for( j=0;j<n;j++ )
			scanf("%d",&num[i][j]);
	}


	transposition_output(num,m,n);	//ת�����


	for( i=0;i<m;i++ )		//��������ռ�
		free(num[i]);
	return 0;
}