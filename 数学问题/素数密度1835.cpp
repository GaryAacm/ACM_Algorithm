#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000001;
int prime[maxn];
bool vis[maxn];
int cnt=0;
int l,r;
bool ans[maxn];
void make_prime()
{
    //memset(prime,1,sizeof(prime));
    //prime[0]=prime[1]=0;
    for(int i=2;i<=50000;++i)
    {
        if(!vis[i])
        {
            prime[++cnt]=i;
            for(int j=i+i;j<=50000;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&l,&r);
    make_prime();
    for(int i=1;i<=cnt;++i)//ö��С���������
    {
        for(int j=max(2,(l-1)/prime[i]+1)*prime[i];j<=r;j+=prime[i])//�ӵ�һ������l�Ŀ��Ա������Ŀ�ʼ������ö��
        {
            if(j-l>=0) ans[j-l]=1;
        }
    }
    int tot=0;
    for(int i=0;i<=r-l;i++)
        if(!ans[i]) tot++;

    cout<<tot<<endl;

    return 0;
}


