#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N =  5e5+7;
LL n,k,m;
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


// 在[l, r]区间中，找一值与C异或最大
LL query(LL l, LL r, LL C) {
    int p = rot[r];

    // C是s[n] ^ x, 从高位到低位逐位检索二进制每一位上能跟C异或结果最大的数
    for (int i = 33; i >= 0; i--) {
        int v = C >> i & 1;

        // 0是空节点，默认max_id[0] = 0的话，当l==0，就会令p跳到空节点上来
        // 由于每个节点至少有一条s[i]的完整路径
        // 那么tr[p][v ^ 1]是空，则tr[p][v]一定存在路
        // 那必不能 满足if，去走一条没路的路
        // 所以max_id[0] = -1，能判除这类情况
        if (Max[trie[p][v ^ 1]] >= l) p = trie[p][v ^ 1];//在范围内
        else p = trie[p][v]; // 退而求其次
    }
    return C ^ s[Max[p]];
}

LL sum=0;

int main()
{

    Max[0]=-1;
	rot[0]=++tot;
	Insert(0,33,0,rot[0]);
	//freopen("D:\\算法进阶\\可持久化\\in.txt","r",stdin);
    scanf("%lld%lld",&n,&m);
    char op[2];
    for(LL i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(LL i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
		rot[i]=++tot;//开启新的根节点
		Insert(i,33,rot[i-1],rot[i]);//和上次的连接起来
	}
	//建好可持续化字典树
    while(m--)
    {
        scanf("%s",op);
        if(op[0]=='A')
        {
            LL temp;
            scanf("%lld",&temp);
            n++;
            s[n]=s[n-1]^temp;
            rot[n]=++tot;
            Insert(n,33,rot[n-1],rot[n]);
        }

        else
        {
            LL s1,s2,s3;
            scanf("%lld%lld%lld",&s1,&s2,&s3);
            printf("%lld\n",query(s1-1,s2-1,s[n]^s3));
        }
    }

    return 0;

}
