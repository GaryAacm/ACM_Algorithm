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
                if((sum^a[i])<=a[i])//�����һ�����еķ��������ܴӲ�ͬ��ʯ������ȡ��һ��,
                    //�������������ʣ��ܵ���������Լ������H�����Ǽ��ٵ�H�ķ���,�������n-1���������
                    //�Ƚϵ�ʱ��һ��Ҫ��������
                    ans++;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
