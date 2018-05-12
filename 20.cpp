/*************************************************************
�����˶�Ա�μӱ�������Ҫ��3�����Ԥ����
����Щ����ķ����أ�
���Ǳ���˶�ԱΪ A,B,C,... I
����ĳ����г������еķ��鷽����


�ó�����������Ϊ��
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

..... (����ʡ�ԣ��ܹ�560��)��
**************************************************************
�㷨˼�룺
	���ֻ�Ƿ��飬Ӧ����280�֣����������������.
	���ȣ������һ�ӳ�Ա�Ѿ�ȷ�ϣ������ӵ������10�֣���������
��20�֣����һ������behind()ʵ����һ���֡�
	��ʵ�ֵ�һ�ӳ�Ա��ȷ�ϣ�C93/A32������ֻ����ϣ�����Ҫ���У�
�����һ�Ӻ���A������ȷ��һ����Ա��ȷ������֮��ĵ�������Ա��
�����е��ú���behind()���ɡ�
*************************************************************/
#include<stdio.h>
int count = 0;		//��������
char group[3][4] = {{'A','B','C',' '},{'D','E','F',' '},{'G','H','I',' '}};


int exchange(char *a,char *b)
{	//����
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}


int line_exchange(int m,int n)
{	//���齻��(�����ӵ�����)
	int i;
	for( i=0;i<3;i++ )
		exchange(&group[m][i],&group[n][i]);
	return 0;
}
int behind(int m,int n)
{	//����������(�����һ�ӳ�Ա�Ѿ�ȷ����)
	printf("%s %4d\n",group,count+1);
	count++;	//�����ǰ����,������

	line_exchange(1,2);	//�������飬�ٴ����������
	printf("%s %4d\n",group,count+1);
	line_exchange(1,2);
	count++;
	
	int i,j;
	for( i=2;i>=0;i-- )
	{
		for( j=0;j<3;j++ )
		{
			//�����к͵ڶ��У���������
			//���������(��ǰѭ������ǰ���ύ������)
			exchange(&group[m][i],&group[n][j]);
			printf("%s %4d\n",group,count+1);
			count++;


			line_exchange(1,2);	//���齻�������������
			printf("%s %4d\n",group,count+1);
			line_exchange(1,2);
			count++;
			
			//������֮ǰ��״̬
			exchange(&group[m][i],&group[n][j]);
		}
	}
	return 0;
}
int before(int m,int n)	
	//m��n�����һ�ӵڶ�����Ա�������ʼ�����е�λ��
{	//��һ�ӳ�Ա�ĸı�(��������У�ֻ�ı��������Ա)
	int i,j;

	behind(1,2);	//�ı�֮ǰ������ǰ�ĺ������������
	printf("\n");


	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{	
			//�����ڵڶ���Ա������Ϊ������Ա
			//(��Ŀֻ��Ҫ��ϣ���Ϊ���ų����е�Ӱ��)
			if( (i!=m || j!=n) && group[i][j]>group[0][1] )
			{
				//�����ϵĶ�Ա����Ϊ��һ�ӳ�Ա���ٽ��к���������
				//��ǰѭ����ĩβ���ύ������
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
{	//����ѡ�ֵ�����,�˺�����Ҫ���õ�һ�ӵĵڶ���Ա

	before(-1,-1);	//���ı�֮ǰ��״̬���


	int i,j = 0;	//�ٽ��иı�
	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{
			//����������Ա�������Ϊ��һ�ӳ�Ա��������
			exchange(&group[0][1],&group[i][j]);
			before(i,j);
			exchange(&group[0][1],&group[i][j]);
		}
	}
	return 0;
}
int main()
{	
	rank();		//��ʼ����
	printf("%d \n",count);	//�������
	return 0;
}