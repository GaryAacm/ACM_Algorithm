#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;
//因为要存边，使用链式向前星存图
const int maxn = 10005;
struct edge{
	int from;
	int to;
	int next;
}e[maxn*20];
int head[maxn];
int dfn[maxn];
int low[maxn];
stack<int>st;
set<int>s;
int tot,cnt;
int res,sum;
void clear_set()
{
	tot = cnt = sum = res = 0;
	memset(head,-1,sizeof(head));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	while(!st.empty())	st.pop();
}
void addedge(int x,int y)
{
	e[tot].from = x;
	e[tot].to = y;
	e[tot].next = head[x];
	head[x] = tot++;
}
void tarjan(int x,int fx)
{
	dfn[x] = low[x] = ++cnt;
	int k = 0;
	for(int i = head[x];~i;i = e[i].next){
		int y = e[i].to;
		if(y == fx)		continue;
		if(!dfn[y]){
			st.push(i);
			tarjan(y,x);
			low[x] = min(low[x],low[y]);
			if(low[y] > dfn[x]){				//桥边
				res++;
			}
			if(low[y] >= dfn[x]){				//点双连通分量
				int num = 0;s.clear();
				while(true){
					int t = st.top();
					num++;
					st.pop();
					s.insert(e[t].from);
					s.insert(e[t].to);
					if(e[t].from == x && e[t].to == y)	break;
				}
				if(num > s.size())		sum += num;			//边数多于点数则冲突
			}
		}
		else if(dfn[y] < dfn[x]){
			st.push(i);
			low[x] = min(low[x],dfn[y]);//处理回退的边
		}
	}
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n == 0 && m == 0) 	break;
		clear_set();
		int x,y;
		for(int i = 0;i < m;i++){
			scanf("%d%d",&x,&y);
			addedge(x,y);		addedge(y,x);
		}
		for(int i = 0;i < n;i++){
			if(!dfn[i]){
				tarjan(i,-1);
			}
		}
		printf("%d %d\n",res,sum);
	}
	return 0;
}
