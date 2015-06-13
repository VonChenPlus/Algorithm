//比较简单的一道题
#include<stdio.h>
#include<string.h>
char s[100]; 
int c[100]; 
int p[100]; 
int n,k;

void troms()  //解密函数
{
	int i=0,j,flag=0;
	for(i=0;i<n;++i)
	{
		flag=c[i]+i;
		while(flag<0 || flag>27)
		{	
		    flag=flag-28;
		}
		j=(k*i)%n;
		p[j]=flag;
	}
}

int main ()
{
   int i,x,j;
   scanf ("%d",&k);
   while (k>0)
    {
       scanf ("%s",&s); 
       n=strlen (s);
       for(i=0;i<n;i++)
       {
         if (s[i]=='_') c[i]=0;
         if (s[i]=='.') c[i]=27;
         if ((s[i]>='a')&&(s[i]<='z'))  c[i]=(int)s[i]-96;
       }
    troms();
    for (i=0;i<n;i++)
      {
        if (p[i]==0) printf ("%s","_");
        else 
          if (p[i]==27) printf ("%s",".");
          else 
            printf ("%c",(char)p[i]+96);
      }
    printf ("\n");
    scanf ("%d",&k); 
  }     
}