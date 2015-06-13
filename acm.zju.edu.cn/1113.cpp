#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{   int i,m;

   double e=2.5,n=2;
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    cout<<"0 1"<<endl;
    cout<<"1 2"<<endl;
    cout<<"2 2.5"<<endl;
    for(i=3;i<=9;i++)
        {
           if(i==0)
                m=1;
           else
                m=i;
           n=n*m;
           e=1/n+e;

           printf("%d %.9f\n",i,e);
        }
    return 0;
}
