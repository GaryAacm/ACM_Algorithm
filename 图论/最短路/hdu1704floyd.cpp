#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
//const int INF = 0x3f3f3f3f;
int n,m,a,b,c,t;
int grap[maxn][maxn];
int flag=0;
void floyd()
{
    for(int k=1;k<=n;k++)//ö�ٷָ��
    {
        for(int i=1;i<=n;i++)
        {
            if(grap[i][k]!=0x3f3f3f3f)//�Ż�
            {
                for(int j=1;j<=n;j++)
                {
                    if(grap[i][j]>grap[i][k]+grap[k][j])//����min����
                        grap[i][j]=grap[i][k]+grap[k][j];
                        //grap[i][j]=1;
                }

            }//һ�����ҵ����е����·


        }

    }
}

int main()
{
    //freopen("D:\\�㷨����\\ͼ��\\���·\\in.txt","r",stdin);
   scanf("%d",&t);
   while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                if(i==j)
                    grap[i][j]=0;
                else
                    grap[i][j]=0x3f3f3f3f;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            grap[a][b]=0;//�ֳ�ʤ��,ֻ��һ��

        }
        floyd();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)//�����ж��Լ�
            {
                if(grap[i][j]==0x3f3f3f3f&&grap[j][i]==0x3f3f3f3f) ans++;
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
