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

int t,l,r,f[maxn][30],n,q;
int ans[maxn],cnt;
int Logn[maxn + 1];

void pre() {
	Logn[1] = 0;
	Logn[2] = 1;
	for (int i = 3; i < maxn; i++) {
		Logn[i] = Logn[i / 2] + 1;
	}
}

int main()
{
    //freopen("D:\\�㷨����\\codeforce\\Round900 div3\\in.txt","r",stdin);
    pre();
    t=read();
    while(t--)
    {
        n=read();

        for(int i=1;i<=n;i++) f[i][0]=read();
        //Ԥ����ST��
        for(int j=1;j<=30;++j)//ö�����䳤��
        {
            for(int i=1;i+(1<<j)-1<=n;++i)//ö����㣬j��ʾ�������
            {
            f[i][j]=f[i][j-1]&f[(1<<(j-1))+i][j-1];
            }
        }
        q=read();
        while(q--)
        {

            l=read(),r=read();
            if(f[l][0]<r) ans[++cnt]=-1;//�����㵥����������
            else
            {
                int L = l, R = n;
				while (L < R) {
					int mid = (L + R + 1) / 2;
					int s = Logn[mid - l + 1];
					int tmp = f[l][s] & f[mid - (1 << s) + 1][s];
					if (tmp >= r) L = mid;
					else R = mid - 1;
				}
				ans[++cnt] = L;
            }
        }


    }
    for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
    return 0;
}

