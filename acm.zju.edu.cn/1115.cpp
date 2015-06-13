#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char ch[1000];
    int sum,n[1000],m,i,t,s;
    while(cin>>ch&&*ch!='0')
    {   sum=0;s=0;
        m=strlen(ch);
        for(i=0;i<m;i++)
                n[i]=ch[i]-48;
        for(i=0;i<m;i++)
           sum=sum+n[i];
        t=sum;
        while(t>=10)
            {
                sum=t;
                s=0;
                while(sum){s+=sum%10;sum=sum/10;}
                t=s;
            }
            cout<<t<<endl;
    }
    return 0;
}

