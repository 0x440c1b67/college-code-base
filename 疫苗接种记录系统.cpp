#include <stdio.h>
#include <string.h>
#define Maxsize 100
//����ڵ��������� 
typedef struct Node
{
	char name[10];
	char id[20];
	char jiatingdizhi[30];
	char number[20];
	float firsttime,secondtime;
	char dizhi1[30],dizhi2[30];
}List;
List p[Maxsize];
int length=0;
//������Ϣ¼�뺯��
void Create(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("������");
		scanf("%s",&p[i].name);
		printf("\n���֤����:");
		scanf("%s",&p[i].id);
		printf("\n��ͥסַ:");
		scanf("%s",&p[i].jiatingdizhi);
		printf("\n�绰���룺");
		scanf("%s",&p[i].number);
		printf("\n��һ�ν���ʱ�䣺"); 
		scanf("%f",&p[i].firsttime);
		length++;
		if(p[i].firsttime==0.0)
			continue;
		printf("\n��һ�ν��ֵ�ַ��");
		scanf("%s",&p[i].dizhi1);
		printf("\n�ڶ��ν���ʱ�䣺");
		scanf("%f",&p[i].secondtime);
		if(p[i].secondtime==0.0)
			continue;
		printf("\n�ڶ��ν��ֵ�ַ��");
		scanf("%s",&p[i].dizhi2);
	}
}
//��ð�����򽫵�һ�ν���ʱ������
void paixu()
{
	int i;
	for(i=0;i<length;i++)
	{
		int j;
		for(j=0;j<i;j++)
		{
			if(p[j].firsttime>p[j+1].firsttime);
			{
				List q;
				strcpy(q.name,p[j+1].name);
				strcpy(q.id,p[j+1].id);
				strcpy(q.jiatingdizhi,p[j+1].jiatingdizhi);
				strcpy(q.number,p[j+1].number);
				q.firsttime=p[j+1].firsttime;
				q.secondtime=p[j+1].secondtime;
				strcpy(q.dizhi1,p[j+1].dizhi1);
				strcpy(q.dizhi2,p[j+1].dizhi2);
				strcpy(p[j+1].name,p[j].name);
				strcpy(p[j+1].id,p[j].id);
				strcpy(p[j+1].jiatingdizhi,p[j].jiatingdizhi);
				strcpy(p[j+1].number,p[j].number);
				p[j+1].firsttime=p[j].firsttime;
				p[j+1].secondtime=p[j].secondtime;
				strcpy(p[j+1].dizhi1,p[j].dizhi1);
				strcpy(p[j+1].dizhi2,p[j].dizhi2);
				strcpy(p[j].name,q.name);
				strcpy(p[j].id,q.id);
				strcpy(p[j].jiatingdizhi,q.jiatingdizhi);
				strcpy(p[j].number,q.number);
				p[j].firsttime=q.firsttime;
				p[j].secondtime=q.secondtime;
				strcpy(p[j].dizhi1,q.dizhi1);
				strcpy(p[j].dizhi2,q.dizhi2);
			}
		}
	}
}
//�����������������Ա����Ϣ
void Insert(int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		printf("������"); 
		scanf("%s",&p[length].name);
		printf("\n���֤���룺"); 
		scanf("%s",&p[length].id);
		printf("\n��ͥסַ��");
		scanf("%s",&p[length].jiatingdizhi);
		printf("\n�绰���룺");
		scanf("%s",&p[length].number);
		printf("\n��һ�ν���ʱ�䣺"); 
		scanf("%f",&p[length].firsttime);
		if(p[length].firsttime==0.0)
		{
			length++;
			continue;
		}
		printf("\n��һ�ν��ֵ�ַ��");
		scanf("%s",&p[length].dizhi1);
		printf("\n�ڶ��ν���ʱ�䣺");
		scanf("%f",&p[length].secondtime);
		if(p[length].secondtime==0.0)
		{
			length++;
			continue;
		}
		printf("\n�ڶ��ν��ֵ�ַ��"); 
		scanf("%s",&p[length].dizhi2);
		length++;
	}
} 
//��ʾδ���ֵ��˵���Ϣ 
void Dis()
{
	int i;
	for(i=0;i<length;i++)
	{
		if(p[i].firsttime==0.0)
		{
			printf("������%s\n",p[i].name);
			printf("���֤���룺%s\n",p[i].id);
			printf("��ͥ��ַ��%s\n",p[i].jiatingdizhi);
			printf("�绰���룺%s\n",p[i].number);
		}
	}
	printf("\n");
}
void DispList()
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("������%s\n",p[i].name);
		printf("���֤���룺%s\n",p[i].id);
		printf("��ͥסַ��%s\n",p[i].jiatingdizhi);
		printf("�绰���룺%s\n",p[i].number);
		if(p[i].firsttime==0.0)
			continue;
		printf("��һ�ν���ʱ�䣺%.2f\n",p[i].firsttime);
		
		printf("��һ�ν��ֵ�ַ��%s\n",p[i].dizhi1);
		if(p[i].secondtime==0.0)
			continue;
		printf("�ڶ��ν���ʱ�䣺%.2f\n",p[i].secondtime);
		printf("�ڶ��ν��ֵ�ַ��%s\n",p[i].dizhi2);
	}
	printf("\n");
}
void mulu()
{
	while(1)
	{
		int n;
		printf("���ܣ�\n");
		printf("1.�������¹�������֡���������\n");
		printf("2.��������������Ա����Ϣ\n");
		printf("3.��ȫ����Ա������ʱ���ǰ�����������\n");
		printf("4.��ʾû�вμӽ�����Ա����Ϣ\n");
		printf("5.ͳ��������¹�������֡�����Ϣ��\n");
		printf("6.�˳�ϵͳ\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:int t;printf("�������ж����ˣ�");scanf("%d",&t);Create(t);break;
			case 2:int b;printf("�������ж����ˣ�");scanf("%d",&b);Insert(b);break;
			case 3:paixu();break;
			case 4:Dis();break;
			case 5:DispList();break;
		}
		if(n==6)	
			break;
	}
}
int main()
{
	mulu();
	return 0;
}
