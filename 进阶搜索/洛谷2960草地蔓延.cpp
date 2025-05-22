#include<bits/stdc++.h>
using namespace std;
int vis[105][105],tot=1,n,m,sx,sy,Time=1,sum;
char Map[105][105];

int l[8][2]={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}};
int main()
{
	memset(vis,-1,sizeof(vis));
	cin>>m>>n>>sy>>sx;
	for(int i=n;i>0;i--)
	 for(int j=1;j<=m;j++)
	   {
	   	  cin>>Map[i][j];
	   	  if(Map[i][j]=='.') sum++;
	   }
	vis[sx][sy]=0;
	while(tot!=sum)
	{
	    for(int i=1;i<=n;i++)
	       for(int j=1;j<=m;j++)
	          {
	             bool flag=0;
                 if(vis[i][j]>0) continue;
	    	     if(Map[i][j]=='*') continue;
	    	     for(int q=0;q<8;q++)
	             {
	   	         int tx=i+l[q][0];
	   	         int ty=j+l[q][1];
	   	         if(tx<1||tx>n||ty<1||ty>m) continue;
	   	         if(Map[tx][ty]=='*') continue;
	   	         if(vis[tx][ty]!=Time-1) continue;//…œ¥Œ¿©’π
	   	         vis[i][j]=Time;
	   	         flag=1;
	             }
	             if(flag) tot++;
		   }
	    Time++;
	}
	cout<<Time<<endl;
	return 0;
}

