#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N =  5e5+7;
LL n,k;
LL s[N],a[N],Max[N*64],trie[N*64][3],tot=0,rot[N];
struct node
{
	LL pos,l,r,ans;
};
node Make(LL a,LL b,LL c,LL d)
{
	node T;
	T.pos=a;
	T.l=b;
	T.r=c;
	T.ans=d;
	return T;
}
priority_queue<node> q;
bool operator < (const node &x,const node &y)
{
	LL a=s[x.ans]^s[x.pos];
	LL b=s[y.ans]^s[y.pos];
	return a<b;
}

//递归版本建树
void Insert(LL t,LL len,LL pre,LL pos)//建立可持久化字典树
{
	if(len<0)//其中t表示现在正在插入第t个字符串，len表示现在到了第len个字符
	{
		Max[pos]=t;//代表叶子节点的位置，就是这是第几个字符串的
		return;
	}
	LL ch=(s[t]>>len)&1;
	if(pre) trie[pos][ch^1]=trie[pre][ch^1];
	trie[pos][ch]=++tot;
	Insert(t,len-1,trie[pre][ch],trie[pos][ch]);//跨路径指向
	Max[pos]=max(Max[trie[pos][ch]],Max[trie[pos][ch^1]]);//更新max值
}

//递归版本查询
LL query(LL pos,LL val,LL len,LL L)//找到序列的一个位置异或val最大
{

	if(len<0) return Max[pos];

	LL ch=(val>>len)&1;//提取当前值

	if(Max[trie[pos][ch^1]]>=L) return query(trie[pos][ch^1],val,len-1,L);
	else return query(trie[pos][ch],val,len-1,L);
}
LL sum=0;

int main()
{
	Max[0]=-1;
	rot[0]=++tot;
	Insert(0,33,0,rot[0]);
	scanf("%lld%lld",&n,&k);
	for(LL i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(LL i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
		rot[i]=++tot;//开启新的根节点
		Insert(i,33,rot[i-1],rot[i]);//和上次的连接起来
	}
	for(LL i=1;i<=n;i++)
	{
		LL ans=query(rot[i],s[i],33,0);
		q.push(Make(i,0,i,ans));//加入大根堆，一个四元组（pos,l,r,ans）放进堆里，其中pos代表右端点位置，l代表左端点的最小范围，r代表左端点的最大范围，ans表示在（l~r）中和pos异或最大的位置
	}
	while(k--)
	{
		node tmp=q.top();
		q.pop();
		sum+=s[tmp.ans]^s[tmp.pos];
		if(tmp.l<tmp.ans) q.push(Make(tmp.pos,tmp.l,tmp.ans-1,query(rot[tmp.ans-1],s[tmp.pos],33,tmp.l)));
		if(tmp.r>tmp.ans) q.push(Make(tmp.pos,tmp.ans+1,tmp.r,query(rot[tmp.r],s[tmp.pos],33,tmp.ans+1)));
	}
	cout<<sum;
	return 0;
}

