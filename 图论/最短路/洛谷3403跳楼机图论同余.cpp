#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=1e5+100;
long long n,a,b,c,ans,tot;
long long d[N],ver[N<<1],head[N],edge[N<<1],Next[N<<1];
bool v[N];
priority_queue< pair<long long,long long> > q;

inline void add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}

inline void dijkstra(){
	memset(d,0x3f3f,sizeof(d));
   //long long�µ����ֵ��0x3f3f3f3f3f3f3f3fȻ��memset��4λ4λ��ֵ�����Ծ���0x3f3f
	memset(v,false,sizeof(v));
	d[1]=1;//��ƽ�������·��ͬ����Ϊ��������¥��Ҳ��һ�����Ը�Ϊ1
	q.push(make_pair(-1,1));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x]) continue;
		v[x]=true;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}

int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	if(a==1 || b==1 || c==1){
		printf("%lld",n);//����д���һ�ֲ���Ϊ����1����Ȼ���ɵ���
		return 0;
	}
	for(int i=0;i<a;i++) add(i,(i+b)%a,b),add(i,(i+c)%a,c);//��ͼ
	dijkstra();
	for(int i=0;i<a;i++)
		if(d[i]<=n) ans+=(n-d[i])/a+1;//ͳ�ƴ�
	printf("%lld",ans);
	return 0;
}
