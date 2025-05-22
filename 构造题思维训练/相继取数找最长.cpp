#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,a[N],b[N],f[2*N];
void solve()
{
    scanf("%d",&n); int ans=0;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) scanf("%d",b+i);

    for(int i=1;i<=2*n;i++) f[i]=0;//初始全为0
    a[0]=b[0]=a[n+1]=b[n+1]=0;//处理边界，方便最后处理

    for(int i=1,run=0;i<=n+1;i++)
    {
        if(a[i]!=a[i-1])
        {
            f[a[i-1]]=max(f[a[i-1]],run);
            //可能有些 a 中出现的值 b 中不会出现但是还是最大结果
            ans=max(ans,run);
            run=0;
        }
        run++;
    }

    for(int i=1,run=0;i<=n+1;i++)
    {
        if(b[i]!=b[i-1])
        {
            //注意这里的实现会导致用 x=0 更新答案，上面同理
            ans=max(ans,run+f[b[i-1]]);//编程技巧
            run=0;
        }
        run++;
    }
    printf("%d\n",ans);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
