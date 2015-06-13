#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char digits[10];

int N_length_num(int n)
{
	int length=1;
	while(n!=0)
	{
		length=length*10;
		n=n/10;
	}
	return length;
}

void judge(int n,int m)
{
	int num=N_length_num(n)+1;
	double sum=0.00;
	char *str;
	int length;
	int decpt,sign;
	int k,i,j;
	for(k=1;k<num;k++)
	{
		sum+=n;
		str=fcvt(sum,0,&decpt,&sign);
		length=strlen(str);
		for(i=0;i<length;i++)
		{
			for(j=0;j<m;j++)
				if(str[i]==digits[j])
					break;
			if(j==m)
				break;
		}
		if(i==length)
		{
			printf("%s\n",str);
			break;
		}
	}
	if(k==num)
		printf("0\n");
}

int main()
{
	int n,m;
	int num;
	int i;
	while(1)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&num);
			digits[i]=num+48;
		}
		judge(n,m);
	}
	return 0;
}