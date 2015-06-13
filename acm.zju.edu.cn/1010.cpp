#include<stdio.h>
#define null 0

struct point
{
	float x;
	float y;
};

//设两条边的分别为 P1P2 和 Q1Q2，若其相交，则满足：
//  ( P1 - Q1 ) × ( Q2 - Q1 )  *  ( Q2 - Q1 ) × ( P2 - Q1 )  >  0
int flag_of_cut(struct point *p,int vcount)
{
	int j;float l,m;
	for(int i=0;i<vcount;++i)
	{
		for(j=(i+2)%vcount;;++j)
		{
			if(i==0 && j==vcount-1)
					break;
			else
			if(i!=0 && (j)%vcount==i-1)
				break;
			l=((p[i].x-p[j].x)*(p[(j+1)%vcount].y-p[j].y)-(p[(j+1)%vcount].x-p[j].x)*(p[i].y-p[j].y));
			m=((p[(j+1)%vcount].x-p[j].x)*(p[(i+1)%vcount].y-p[j].y)-(p[(i+1)%vcount].x-p[j].x)*(p[(j+1)%vcount].y-p[j].y));
			if(l*m>0)
				return 0;
		}
	}
	return 1;
}

float area_of_polygon(int vcount,struct point points[])
	{
	  int i;
	  float s;
	  if (vcount<3) return -1;
	  s=points[0].y*(points[vcount-1].x-points[1].x);
	  for (i=1;i<vcount;i++)
	     s+=points[i].y*(points[(i-1)].x-points[(i+1)%vcount].x);
	  return -s/2;
	 }

int main()
{
	int num;int i;int l=1;
	struct point p[10];
	while(scanf("%d",&num) && num)
	{
		for(i=0;i<num;i++)
		{
			scanf("%f%f",&p[i].x,&p[i].y);
		}
		printf("Figure %d: ",l++);
		if(flag_of_cut(p,num))
			printf("%f\n",area_of_polygon(num,p));
		else
			printf("Impossible\n");
	}
	return 0;
}