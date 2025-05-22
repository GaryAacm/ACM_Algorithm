#include<bits/stdc++.h>
using namespace std;
int n,x_1,x_2,y_1,y_2,ans[65][65][65][65],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
string s;
bool a[65][65];
pair<pair<int,int>,pair<int,int> > u,v;
queue<pair<pair<int,int>,pair<int,int> > > q;

void bfs()
{
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0;i<4;i++)
        {
			v=u;
			v.first.first+=dx[i];
			v.first.second+=dy[i];
			v.second.first+=dx[i];
			v.second.second+=dy[i];//同时走
			if(a[v.first.first][v.first.second])//遇到边界或者障碍物，减去，相当于不走
			{
				v.first.first-=dx[i];
				v.first.second-=dy[i];
			}
			if(a[v.second.first][v.second.second]){
				v.second.first-=dx[i];
				v.second.second-=dy[i];
			}
			if(!ans[v.first.first][v.first.second][v.second.first][v.second.second])//不重复
			{
				if(v.first.first==v.second.first&&v.first.second==v.second.second)//到达相同处
				{
					cout<<ans[u.first.first][u.first.second][u.second.first][u.second.second];
					return ;
				}
				ans[v.first.first][v.first.second][v.second.first][v.second.second]=ans[u.first.first][u.first.second][u.second.first][u.second.second]+1;//增加步数
				q.push(v);
			}
		}
	}
	cout<<"-1";
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
		a[0][i]=a[n+1][i]=a[i][0]=a[i][n+1]=1;
		cin>>s;
		for(int j=1;j<=n;j++){
			if(s[j-1]=='P')
			{
				if(!x_1){
					x_1=i,y_1=j;
				}
				else{
					x_2=i,y_2=j;
				}
			}
			else if(s[j-1]=='#'){
				a[i][j]=1;
			}
		}
	}
	ans[x_1][y_1][x_2][y_2]=1;
	q.push(make_pair(make_pair(x_1,y_1),make_pair(x_2,y_2)));
	bfs();
	return 0;
}
