#include <stdio.h>
#include <string.h>

int last[501][501],now[501][501];

void convert()
{
    for(int i=0;i<501;i++)
      for(int j=0;j<501;j++){
            int t=last[i][j];
            last[i][j]=now[i][j];
            now[i][j]=t;
        }
}


int main()
{
    int temp=0,n,mma,mmb,ma,mb,i,j,k,j1,k1,w1,w2,w3,s1,s2,s3,d1,d2,d3,d4,c1,c2,c3;
    int ns1,ns2,nw1,nw2,ba,bb,bc,rs,best,w,s;
    while(scanf("%d",&n)!=EOF && n)
       {
        if(temp) printf("\\n");
        temp++;
        scanf("%d%d%d",&w1,&s1,&d1);
        scanf("%d%d%d",&w2,&s2,&d2);
        scanf("%d%d%d",&w3,&s3,&d3);
        scanf("%d%d%d%d",&c1,&c2,&c3,&d4);
        d4-=c1*d1+c2*d2+c3*d3;//将3个武器集合起来的力量与正常力量之差； 
        memset(last,-1,sizeof(last));
        last[0][0]=0;
        mma=mmb=0;
        for(i=0;i<n;i++)
           {
            scanf("%d%d",&w,&s);
            memset(now,-1,sizeof(now));
            ma=mma;
            mb=mmb;
            for(j=0;j<=mma;j++){
                for(k=0;k<=mmb;k++){
                    if(last[j][k]>=0){
                        //第1种武器的数量； 
                        for(j1=j,ns1=nw1=0;ns1<=s && nw1<=w ;ns1+=s1,nw1+=w1,j1++){
                            //第2种武器的数量
                            for(k1=k,ns2=ns1,nw2=nw1;ns2<=s && nw2<=w;ns2+=s2,nw2+=w2,k1++){
                                if(j1>ma) ma=j1;
                                if(k1>mb) mb=k1;
                                ba=(s-ns2)/s3; 
                                bb=(w-nw2)/w3;
                                if(ba>bb) ba=bb;//还能容纳的第3种武器的个数； 
                                ba+=last[j][k];//利用前i-1辆车的信息，将其加起来； 
                                if(now[j1][k1]<ba) now[j1][k1]=ba;//更新； 
                            }
                        }
                    }
                }
            }
            mma=ma;
            mmb=mb;
            convert();
        }
        best=0;//找出所有运输方案中最优的；注意 last[i][j]的含义； 
        for(i=0;i<=mma;i++){
            for(j=0;j<=mmb;j++){
                if(last[i][j]>=0){
                    rs=i*d1+j*d2+last[i][j]*d3;
                    ba=i/c1;
                    bb=j/c2;
                    bc=last[i][j]/c3;
                    if(ba>bb) ba=bb;
                    if(ba>bc) ba=bc;
                    if(d4>0) rs+=ba*d4;
                    if(rs>best) best=rs;
                }
            }
        }
        printf("Case %d: %d\\n",temp,best);
    }
    return 0;
}

