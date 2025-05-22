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


// ��[l, r]�����У���һֵ��C������
LL query(LL l, LL r, LL C) {
    int p = rot[r];

    // C��s[n] ^ x, �Ӹ�λ����λ��λ����������ÿһλ���ܸ�C�����������
    for (int i = 33; i >= 0; i--) {
        int v = C >> i & 1;

        // 0�ǿսڵ㣬Ĭ��max_id[0] = 0�Ļ�����l==0���ͻ���p�����սڵ�����
        // ����ÿ���ڵ�������һ��s[i]������·��
        // ��ôtr[p][v ^ 1]�ǿգ���tr[p][v]һ������·
        // �Ǳز��� ����if��ȥ��һ��û·��·
        // ����max_id[0] = -1�����г��������
        if (Max[trie[p][v ^ 1]] >= l) p = trie[p][v ^ 1];//�ڷ�Χ��
        else p = trie[p][v]; // �˶������
    }
    return C ^ s[Max[p]];
}

LL sum=0;

int main()
{

    Max[0]=-1;
	rot[0]=++tot;
	Insert(0,33,0,rot[0]);
	//freopen("D:\\�㷨����\\�ɳ־û�\\in.txt","r",stdin);
    scanf("%lld%lld",&n,&m);
    char op[2];
    for(LL i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(LL i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
		rot[i]=++tot;//�����µĸ��ڵ�
		Insert(i,33,rot[i-1],rot[i]);//���ϴε���������
	}
	//���ÿɳ������ֵ���
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
