#include <stdio.h>
#include <string.h>
#define Maxsize 100
//定义节点数据类型 
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
//构建信息录入函数
void Create(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("姓名：");
		scanf("%s",&p[i].name);
		printf("\n身份证号码:");
		scanf("%s",&p[i].id);
		printf("\n家庭住址:");
		scanf("%s",&p[i].jiatingdizhi);
		printf("\n电话号码：");
		scanf("%s",&p[i].number);
		printf("\n第一次接种时间："); 
		scanf("%f",&p[i].firsttime);
		length++;
		if(p[i].firsttime==0.0)
			continue;
		printf("\n第一次接种地址：");
		scanf("%s",&p[i].dizhi1);
		printf("\n第二次接种时间：");
		scanf("%f",&p[i].secondtime);
		if(p[i].secondtime==0.0)
			continue;
		printf("\n第二次接种地址：");
		scanf("%s",&p[i].dizhi2);
	}
}
//用冒泡排序将第一次接种时间排序
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
//插入插入后接种疫苗人员的信息
void Insert(int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		printf("姓名："); 
		scanf("%s",&p[length].name);
		printf("\n身份证号码："); 
		scanf("%s",&p[length].id);
		printf("\n家庭住址：");
		scanf("%s",&p[length].jiatingdizhi);
		printf("\n电话号码：");
		scanf("%s",&p[length].number);
		printf("\n第一次接种时间："); 
		scanf("%f",&p[length].firsttime);
		if(p[length].firsttime==0.0)
		{
			length++;
			continue;
		}
		printf("\n第一次接种地址：");
		scanf("%s",&p[length].dizhi1);
		printf("\n第二次接种时间：");
		scanf("%f",&p[length].secondtime);
		if(p[length].secondtime==0.0)
		{
			length++;
			continue;
		}
		printf("\n第二次接种地址："); 
		scanf("%s",&p[length].dizhi2);
		length++;
	}
} 
//显示未接种的人的信息 
void Dis()
{
	int i;
	for(i=0;i<length;i++)
	{
		if(p[i].firsttime==0.0)
		{
			printf("姓名：%s\n",p[i].name);
			printf("身份证号码：%s\n",p[i].id);
			printf("家庭地址：%s\n",p[i].jiatingdizhi);
			printf("电话号码：%s\n",p[i].number);
		}
	}
	printf("\n");
}
void DispList()
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("姓名：%s\n",p[i].name);
		printf("身份证号码：%s\n",p[i].id);
		printf("家庭住址：%s\n",p[i].jiatingdizhi);
		printf("电话号码：%s\n",p[i].number);
		if(p[i].firsttime==0.0)
			continue;
		printf("第一次接种时间：%.2f\n",p[i].firsttime);
		
		printf("第一次接种地址：%s\n",p[i].dizhi1);
		if(p[i].secondtime==0.0)
			continue;
		printf("第二次接种时间：%.2f\n",p[i].secondtime);
		printf("第二次接种地址：%s\n",p[i].dizhi2);
	}
	printf("\n");
}
void mulu()
{
	while(1)
	{
		int n;
		printf("功能：\n");
		printf("1.建立《新冠疫苗接种》档案数组\n");
		printf("2.插入后接种疫苗人员的信息\n");
		printf("3.对全体人员按接种时间从前到后进行排序\n");
		printf("4.显示没有参加接种人员的信息\n");
		printf("5.统计输出《新冠疫苗接种》的信息表\n");
		printf("6.退出系统\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:int t;printf("请输入有多少人：");scanf("%d",&t);Create(t);break;
			case 2:int b;printf("请输入有多少人：");scanf("%d",&b);Insert(b);break;
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
