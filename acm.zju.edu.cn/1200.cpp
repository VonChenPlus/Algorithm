
/*zju1200模拟题
总思想：
挖每次的矿，都从机器人中选择到达矿区时间最短的机器。
然后更新每个机器人到矿区的时间，以备下一轮选择。
*/
#include<iostream>
using namespace std;

int S,W,C,K,M,m,sum,i,j,minlength,TIME;
int length[10001];

int main()
{

while(cin>>S)
{
cin>>W>>C>>K>>M;
/*机器人的数目的上限是10000/C+1,超过了剩下的机器人都没有用了*/
     int x;
x = 10000/C + 1;
if(K > x)K=x;
    /*-----------------------------------------------------------*/
    /*初始化length[i],表示第i个机器人从基地走到矿区要多少时间*/
length[0] = 0;
for(i=1; i<=K; i++)
{
length[i] = M + length[i-1];
}
         for(i=1; i<=K; i++)
{
length[i] = length[i] + S;
}
    /*----------------------------------------------------------*/     
TIME = 0;//运完10000所用总时间
sum = 0;//注意这是被挖走的矿量，而不是基地的矿量
         while(sum < 10000)
{
m = 1;//m表示目前机器人中，走到矿区时间最短的机器人
minlength = length[1];//走到矿区最短的时间
for(i=2; i<=K; i++)//找出时间最短的机器人
if(minlength > length[i])
{
minlength = length[i];
m = i;
}
TIME+=minlength+W;//机器人挖完矿后的总时间
for(i=1; i<=K ;i++)
{
length[i] = length[i] - minlength-W;//其他机器人到矿区的时间也要相应地减少
if(length[i] < 0)length[i] = 0;//如果少于0,则只能为0,表示等待中
}
sum += C;
length[m] = 2*S;//刚挖完矿的机器人给予初始值　
}
cout<<TIME+S<<endl;//加上S是因为当矿区空的时候循环就跳出了，而最后一个机器人还没回到基地
}
return 0;
}  
