/*˼�����ͨ�����鼯��������ɾ����̱ߣ��������ߣ�ע����ͨ���жϣ����ȿɴ������ͨ*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
struct node
{
    int u,v,w;
}e[maxn<<1];

bool cmp(node x,node y)
{
    return x.w>y.w;
}

int n,k,a,b,c,temp,f[maxn];
ll ans=0;
bool is[maxn];

int finded(int x)
{
    if(f[x]==x) return x;
    return f[x]=finded(f[x]);
}

void solve()
{
    for(int i=1;i<n;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        int w=e[i].w;
        int fu=finded(u),fv=finded(v);
        if(is[fu]&&is[fv]) continue;//���ȶ��ǵ���
        f[fu]=fv;//���ϵ�һ�����鼯����
        ans-=w;//��ȥ����������
        if(is[fu]) is[fv]=true;
        else if(is[fv]) is[fu]=true;
        //��ʾ�Ѿ��͵������ӣ�������������������


    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>temp;
        is[temp]=true;//�ж��ǵ���
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b>>c;
        e[i].u=a,e[i].v=b,e[i].w=c;
        ans+=c;
    }
    for(int i=0;i<=n;i++) f[i]=i;
    sort(e+1,e+1+n-1,cmp);
    solve();
    cout<<ans<<endl;
    return 0;
}
