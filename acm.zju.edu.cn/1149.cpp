#include<iostream>
int ok;
int arr[7];
void find(int now,int x){
    if(x==0)
        return;
    int i,s,t;
    s=now/x;
    t=s>arr[x]?arr[x]:s;
    if((now-x*t)!=0){
        for(i=t;i>=0;i--){
            find(now-x*i,x-1);
            if(ok)
                return;
        }
    }
    else{
        ok=1;
        return;
    }
}
int main(){
    int sum,p=1;
    while(scanf("%d%d%d%d%d%d",&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6])&&!(arr[1]==0&&arr[2]==0&&arr[3]==0&&arr[4]==0&&arr[5]==0&&arr[6]==0)){
        arr[1]%=24;arr[2]%=24;arr[3]%=24;arr[4]%=24;arr[5]%=24;arr[6]%=24;
       //这里尤其要注意，不取摸是会超时的。取摸的方法是对6的倍数取摸如（12，18，24，30，。。。）
        sum=1*arr[1]+2*arr[2]+3*arr[3]+4*arr[4]+5*arr[5]+6*arr[6];
        ok=0;
        if(sum%2){
            printf("Collection #%d:\n",p++);
            printf("Can't be divided.\n");
        }
        else{
            find(sum/2,6);
            if(ok){
                printf("Collection #%d:\n",p++);
                printf("Can be divided.\n");
            }
            else{
                printf("Collection #%d:\n",p++);
                printf("Can't be divided.\n");
            }
        }
        if(p!=1)
            printf("\n");
    }
} 