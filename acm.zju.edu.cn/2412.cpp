#include <stdio.h>
#define N 51
#define id(i,j) (i*m+j+1)

int dir[][2]={{-1,0},{0,-1}}; 
int link[][4]={  {1,0,1,0},{1,1,0,0}  
                ,{0,0,1,1},{0,1,0,1}  
                ,{1,0,0,1},{0,1,1,0}  
                ,{1,1,1,0},{1,0,1,1}  
                ,{0,1,1,1},{1,1,0,1}  
                ,{1,1,1,1}};          

int f[N*N],m,n;
char map[N][N],ch;
int x,y,u,v,p,q,t; 

int connect(int u,int v,int e){
    if(!e){ 
        if(link[u][0]&&link[v][3]) return 1;
        else return 0;
    }
    else{
        if(link[u][2]&&link[v][1]) return 1;
        else return 0;
    }
}

int root(int p){
    q=p;
    while(f[q]) q=f[q];
    while(f[p]){
        t=f[p];
        f[p]=q;
        p=t;
    }
    return q;
}

void work(int i,int j,int e){
    x=i+dir[e][0];
    y=j+dir[e][1];
    u=map[i][j];
    v=map[x][y];
    if(connect(u,v,e)){
        p=root(id(i,j));
        q=root(id(x,y));
        if(p!=q) f[p]=q;
    }
}

int main()
{
    int i,j,k,ans;
    
    while(scanf("%d%d",&n,&m),m!=-1||n!=-1)
    {

        getchar();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%c",&ch);
                map[i][j]=ch-'A';
            }
            getchar();
        }
        

        for(i=0;i<=n*m;i++) f[i]=0;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i) work(i,j,0);  
                if(j) work(i,j,1);  
            }
        }
        ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                k=id(i,j);
                if(root(k)==k) ans++;
            }
        printf("%d\n",ans);
    }
    
    return 0;
}

