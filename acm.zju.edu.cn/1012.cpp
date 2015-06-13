#include<stdio.h>
#include<stdlib.h>

int F,M,N,L;
int wait[10000],j=0;
int now=0;
int price=0;

struct work
{
	int cpu; 
	int mem;
	int t;
	int u;
	int pay;
	int enc;
	int ame;
};

int workwait(struct work *p,int wnow)
{
	int tem=p[wnow].t;
	for(int i=wnow;p[i].t==p[i+1].t;++i)
	{
		if(p[tem].pay>p[i+1].pay)
		{
			wait[j++]=i+1;
		}
		else
		{
			wait[j++]=tem;
			tem=i+1;	
		}
	}

	//��������İ���������
	
	return tem;
}

void work(struct work *p)
{
	int flag=0,csum=0,msum=0,time=0;
	time=p[0].t;
	while(1)
	{
		while(j!=0)                     //���������Ĺ���
		{
			if((M-p[wait[j]].cpu)!=0 && (N-p[wait[j]].mem)!=0)
			{
				M=M-p[wait[j]].cpu;
				N=N-p[wait[j]].mem;
				price+=p[wait[j]].pay;
				if(time+1<p[wait[j]].u)
					price+=p[wait[j]].enc*(p[wait[j]].u-time-1);
				else
				    price-=p[wait[j]].ame*(time+1-p[wait[j]].u);
				now++;
				csum+=p[wait[j]].cpu;
				msum+=p[wait[j]].mem;
				j--;
			}
			else
				break;
		}//while

    	if(!j)   //�������޵ȴ�����ʱ
		{
	    	flag=workwait(p,now);
	        if((M-p[flag].cpu)!=0 && (N-p[flag].mem)!=0)
			{
				now++;
			    if(now==L) //û����ʱ����ѭ������
					break;
			}
	    	else
			{
		    	time++;
			    if(time!=F)
	            	break; //��ʱ�޵�0�ǽ���ѭ��
			}
		}//if
		M+=csum;   //�ӻع������õ����ڴ��CPU
		N+=msum;
	}//while
}

int main()
{ 
	struct work *p;
	while(scanf("%d",&F)!=EOF && F && scanf("%d%d%d",&M,&N,&L)!=EOF)
	{
		p =(struct work *) malloc(sizeof(struct work)*L);
		for(int i=0;i<L;++i)
		scanf("%d%d%d%d%d%d%d",&p[i].cpu,&p[i].mem,&p[i].t,&p[i].u,&p[i].pay,&p[i].enc,&p[i].ame);

		free(p);
	}
	return 0;
}