#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[1005][1005];
int b[1005][1005];

int main()
{
    freopen("D:\\�㷨����\\codeforce\\R912������\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int flag1=1,flag2=1,flag3=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(i!=j)
                {
                    if(a[i][j]==0) flag1=0;
                }
                if(i==j)
                {
                    if(a[i][j]!=0) flag3=0;
                }
            }
        }
         for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[i][j]!=a[j][i])
                {
                    flag2=0;
                    break;
                }
            }
        }
        if(!flag2)//���ǶԳƾ���
        {
            printf("NO\n");
        }
        else
        {
            if(!flag1)//���˶Խ������в�Ϊ0��
                printf("NO\n");
            else if(!flag3) //�Խ��߲�ȫΪ0
                printf("NO\n");
            else
            {
                printf("YES\n");

            }
        }
    }
}
