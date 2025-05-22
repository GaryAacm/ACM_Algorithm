#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
int a[50];
int suma[1<<21],sumb[1<<21];//存储分段的两部分
int cnta,cntb,mid;
//为了处理大数据，利用分段处理再进行合并，前一半的处理加上后一半的处理

//小数据爆搜
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

/*大一点的数据背包
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m<=1e6)
    {
        dp[0]=1;//花费i的方法数
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

    //难点在于合并
    sort(suma+1,suma+1+cnta);
     for(int i=1;i<=cntb;i++)
        ans+=upper_bound(suma+1,suma+1+cnta,m-sumb[i])-suma-1;//因为是按照顺序排序，所以m-sumb[i]在suma里面出现的前面的都可以组合
    printf("%lld\n",ans);
    return 0;
}

