#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char op[100];
int flag=1;

char * select (int n)
{
	switch (n)
	{
	case 1:return "op[i]=='+' || op[i]=='-'";
	case 2:return "op[i]=='*' || op[i]=='/'";
	case 3:return "op[i]=='^'";
	}
}

char* oper(char op[],int len,int r)  //核心
{
	char ** result=(char **) malloc (sizeof(char *) * 50);
	int rand=0,sign=0;
	int min=4;
	for(int i=1;i<len;++i)   //检测运算符中的最低优先符
	{
		if(op[i]<'a' && op[i]>'z')
		{
			if(op[i]=='^')
			{flag=3;continue;}
			if(op[i]=='*' || op[i]=='/')
			{flag=2;continue;}
			if(op[i]=='+' || op[i]=='-')
			{flag=1;min=flag;break;}
		}
		if(flag<min)
			min=flag;
	}
	flag=0;
    for(i=0;i<len;i++)
	 {
    	 if(op[i]=='(')
			 flag++;
		 else if(op[i]==')')
			 flag--;
		 if(flag)
		 {
		    result[rand][sign]=op[i];
		 }
		 else
		 if(select(min))
		 {rand++;sign=0;}
		 else
		 result[rand][sign++]=op[i];
	}
sign=strlen(result[r]);
if(result[r][0]=='(' && result[r][sign-1]==')')
for(i=1;i<sign-1;++i)
{
	result[r][i-1]=result[r][i];
}
return result[r];
}

int main()
{
	char * str;int len;int num;int n;
	while(scanf("%s",&str) && str!="*")//要对(x+y)之类做特殊处理
	{
		len=strlen(str);
		for(int i=3;i<len;i++)
			op[i-3]=str[i];
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			while(scnaf("%d",&n)!='\n')
		}

	}
	return 0;
}