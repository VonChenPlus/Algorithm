/*±È½ÏÇÉÃîµÄµİ¹é*/
#include<iostream>
#include<string>
using namespace std;

bool op[20];
char strbefore[11];
char sc[11];
char strafter[11];
int len;

void go(int sp,int idx,int idxop,int start)
{
	if(idx==len)
	{
		for(int i=0;i<len*2;i++)
		{
			if(op[i]) cout<<"i ";
			else cout<<"o ";
		}
		cout<<endl;
		return;
	}
	int opbak=idxop;int spbak=sp;
	int i=len-1;
	while(i>=start)
	{
		if(strafter[idx]==strbefore[i])
		{
			for(int j=start;j<=i;++j)
			{
				op[idxop++]=1;
				sc[sp++]=strbefore[j];
			}
			op[idxop++]=0;
			--sp;
			go(sp,idx+1,idxop,i+1);
			idxop=opbak;
			sp=spbak;
		}
		--i;
	}
	if(sp!=0 && sc[sp-1]==strafter[idx])
	{
		op[idxop++]=false;
		--sp;
		go(sp,idx+1,idxop,start);
	}
	else
		return;
}

int main()
{
	while(cin>>strbefore>>strafter)
	{
		cout<<"[\n";
		if(strlen(strbefore)==strlen(strafter))
		{
			len=strlen(strbefore);
			go(0,0,0,0);
		}
		cout<<"]\n";
	}
	return 0;
}