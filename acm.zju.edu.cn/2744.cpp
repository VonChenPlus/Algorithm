/*1003   http://acm.zju.edu.cn/contests/show_problem.php?cid=154&pid=1003*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int n,sum,temp,k;
    while(cin>>str)
    {
        n=str.length();
        sum=0;
        sum+=n;
        for(int i=0;i<n-1;++i)
        {
            temp=i;
            k=1;

            while(str[temp+k]==str[temp-k]&&(temp+k)<n&&(temp-k)>=0)
            {
                ++k;
                ++sum;
            }
            k=0;
            if(str[temp]==str[temp+1])
            {
                while(str[temp+k+1]==str[temp-k]&&(temp+k+1)<n&&(temp-k)>=0)
                {
                    ++k;
                    ++sum;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

