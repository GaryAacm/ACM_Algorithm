#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
int a[50];
int suma[1<<21],sumb[1<<21];//�洢�ֶε�������
int cnta,cntb,mid;
//Ϊ�˴�������ݣ����÷ֶδ����ٽ��кϲ���ǰһ��Ĵ�����Ϻ�һ��Ĵ���

//С���ݱ���
/*void dfs(int dep.int sum)
{
    if(sum>m) return ;
    if(dep==n+1)
    {
        ans++;
        return ;
    }

    dfs(dep+1,sum+a[dep]);
    dfs(dep+1,sum);
}*/

/*��һ������ݱ���
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m<=1e6)
    {
        dp[0]=1;//����i�ķ�����
        for(R int i=1;i<=n;i++)
            for(int j=m;j>=a[i];j--)
                dp[j]+=dp[j-a[i]];
        for(int i=0;i<=m;i++) ans+=dp[i];
        printf("%lld\n",ans);
    }
    return 0;
}*/

void dfs(int l,int r,int sum,int temp[],int &cnt)
{
    if(sum>m) return ;
    if(l>r)
    {
        temp[++cnt]=sum;
        return ;
    }

    dfs(l+1,r,sum+a[l],temp,cnt);
    dfs(l+1,r,sum,temp,cnt);
}

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int mid=n>>1;
    dfs(1,mid,0,suma,cnta);
    dfs(mid+1,n,0,sumb,cntb);

    //�ѵ����ںϲ�
    sort(suma+1,suma+1+cnta);
     for(int i=1;i<=cntb;i++)
        ans+=upper_bound(suma+1,suma+1+cnta,m-sumb[i])-suma-1;//��Ϊ�ǰ���˳����������m-sumb[i]��suma������ֵ�ǰ��Ķ��������
    printf("%lld\n",ans);
    return 0;
}

