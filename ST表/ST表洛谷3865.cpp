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
//分割等长的区间再合并
int f[maxn][21];//21表示后面的区间长度，maxn表示起点的数
int ask(int l,int r)//查询区间
{
   int k=log2(r-l+1);//因为向下取整，所有会有重叠查询
   return max(f[l][k],f[r-(1<<k)+1][k]);//左右重叠查询,右端的r-(1<<k)+1是为了找到起点
}
int main()
{
    int n,m;
    n=read();
    m=read();
    //读入数据
    for(int i=1;i<=n;++i) f[i][0]=read();//初始化读入
    //预处理ST表
    for(int j=1;j<=21;++j)//枚举区间长度
    {
        for(int i=1;i+(1<<j)-1<=n;++i)//枚举起点，j表示后面的数
        {
            f[i][j]=max(f[i][j-1],f[(1<<(j-1))+i][j-1]);//第二位j是二的几次方表示
        }
    }
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        printf("%d\n",ask(l,r));
    }
    return 0;
}
