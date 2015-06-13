/*1392*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int print()
{
    char str[101][201],str1[10],str2[3],ch;
    int i=0,n,j=0,len[101];
    scanf("%s",str1);getchar();
   while(strcmp(str1,"ENDOFINPUT")!=0)
        {
            ch=getchar();
            while(ch!='\n')
             {
                str[j][i]=ch;
                i++;
                ch=getchar();
             }

            len[j]=i;
            cin>>str2;
        j++;
        i=0;
        scanf("%s",str1);getchar();
     }
    n=j;
    for(j=0;j<n;j++)
    {for(i=0;i<len[j];i++)
                {
                    if(str[j][i]>=65&&str[j][i]<=90)
                        {
                            str[j][i]=str[j][i]-5;
                            if(str[j][i]<65)
                                 str[j][i]=str[j][i]+26;
                            else
                                continue;
                        }
                    else
                        continue;
                }
    }
    for(j=0;j<n;j++)
        {
            for(i=0;i<len[j];i++)
                cout<<str[j][i];
            cout<<endl;
        }
        return 0;
}
int main()
{
    print();
    return 0;
}
