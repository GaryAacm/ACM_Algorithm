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

//�ݹ�汾����
void Insert(LL t,LL len,LL pre,LL pos)//�����ɳ־û��ֵ���
{
	if(len<0)//����t��ʾ�������ڲ����t���ַ�����len��ʾ���ڵ��˵�len���ַ�
	{
		Max[pos]=t;//����Ҷ�ӽڵ��λ�ã��������ǵڼ����ַ�����
		return;
	}
	LL ch=(s[t]>>len)&1;
	if(pre) trie[pos][ch^1]=trie[pre][ch^1];
	trie[pos][ch]=++tot;
	Insert(t,len-1,trie[pre][ch],trie[pos][ch]);//��·��ָ��
	Max[pos]=max(Max[trie[pos][ch]],Max[trie[pos][ch^1]]);//����maxֵ
}

//�ݹ�汾��ѯ
LL query(LL pos,LL val,LL len,LL L)//�ҵ����е�һ��λ�����val���
{

	if(len<0) return Max[pos];

	LL ch=(val>>len)&1;//��ȡ��ǰֵ

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
		rot[i]=++tot;//�����µĸ��ڵ�
		Insert(i,33,rot[i-1],rot[i]);//���ϴε���������
	}
	for(LL i=1;i<=n;i++)
	{
		LL ans=query(rot[i],s[i],33,0);
		q.push(Make(i,0,i,ans));//�������ѣ�һ����Ԫ�飨pos,l,r,ans���Ž��������pos�����Ҷ˵�λ�ã�l������˵����С��Χ��r������˵�����Χ��ans��ʾ�ڣ�l~r���к�pos�������λ��
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

