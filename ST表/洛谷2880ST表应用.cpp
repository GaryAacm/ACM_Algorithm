#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
//�ָ�ȳ��������ٺϲ�
int f[maxn][21];//21��ʾ��������䳤�ȣ�maxn��ʾ������
int ff[maxn][21];
int ask(int l,int r)//��ѯ����
{
   int k=log2(r-l+1);//��Ϊ����ȡ�������л����ص���ѯ
   return max(f[l][k],f[r-(1<<k)+1][k]);//�����ص���ѯ,�Ҷ˵�r-(1<<k)+1��Ϊ���ҵ����
}

int askk(int l,int r)//��ѯ����
{
   int k=log2(r-l+1);//��Ϊ����ȡ�������л����ص���ѯ
   return min(ff[l][k],ff[r-(1<<k)+1][k]);//�����ص���ѯ,�Ҷ˵�r-(1<<k)+1��Ϊ���ҵ����
}

int main()
{
    int n,m;
    //freopen("D:\\�㷨����\\ST��\\in.txt","r",stdin);
    n=read();
    m=read();
    //��������
    for(int i=1;i<=n;++i)
    {
        f[i][0]=read();//��ʼ������
        ff[i][0]=f[i][0];
    }
    //Ԥ����ST��
    for(int j=1;j<=21;++j)//ö�����䳤��
    {
        for(int i=1;i+(1<<j)-1<=n;++i)//ö����㣬j��ʾ�������
        {
            f[i][j]=max(f[i][j-1],f[(1<<(j-1))+i][j-1]);//�ڶ�λj�Ƕ��ļ��η���ʾ
        }
    }

    for(int j=1;j<=21;++j)//ö�����䳤��
    {
        for(int i=1;i+(1<<j)-1<=n;++i)//ö����㣬j��ʾ�������
        {
            ff[i][j]=min(ff[i][j-1],ff[(1<<(j-1))+i][j-1]);//�ڶ�λj�Ƕ��ļ��η���ʾ
        }
    }

    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        printf("%d\n",ask(l,r)-askk(l,r));
    }
    return 0;
}
