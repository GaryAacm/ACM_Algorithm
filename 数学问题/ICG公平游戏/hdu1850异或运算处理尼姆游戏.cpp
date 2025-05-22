#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n,sum,ans,a[maxn];

int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        int sum=0,ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            sum^=a[i];

        if(sum==0) printf("0\n");
        else
        {
            for(int i=1;i<=n;i++)
            {
                if((sum^a[i])<=a[i])//求出第一步可行的方案，可能从不同堆石子里面取第一次,
                    //这里就是异或性质，总的数异或上自己，求出H，就是减少到H的方案,求出其他n-1个数的异或
                    //比较的时候一定要加上括号
                    ans++;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
