#include<stdio.h>
#include<string.h>

char rotor[3][26];
int i=0;
int num;
char tager[26];

void read(char str[])
{
	int length=strlen(str);
	for(int j=0;j<length;j++)
	{
		rotor[i][j]=str[j];
	}
}

void turn(int i)
{
	int temp1=rotor[i][num-2];
	int temp2=rotor[i][num-1];
	for(int j=num-1;j>=2;j--)
		rotor[i][j]=rotor[i][j-2];
	rotor[i][0]=temp1;
	rotor[i][1]=temp2;
}

void test(int len,char *s)
{
	int r1=0,r2=0;
	for(int j=0;j<len;j++)
	{
		s[j]=rotor[0][s[j]-65];
		s[j]=rotor[1][s[j]-65];
		s[j]=rotor[2][s[j]-65]+32;
		turn(0);
		r1++;
		if(r1==num)
		{
			turn(1);
			r2++;
			r1=0;
			if(r2==num)
			{
				turn(2);
				r2=0;
			}
		}
	}
}

int main()
{
	char str[26];
    int n,len,l=0;
	char s[26];
	while(scanf("%d",&num) && num)
	{
		l=0;
		for(int k=0;k<3;k++)
		{
			scanf("%s",&str);
		    read(str);
			i++;
		}
				scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			test(len,s);
			printf("Enigma %d:\n",++l);
			printf("%s\n",s);
		}
		printf("\n");
	}
	return 0;
}