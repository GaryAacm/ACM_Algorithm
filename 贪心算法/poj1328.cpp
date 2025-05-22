#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

//转化为区间问题，在区间内选点

struct node
{
    double left,right;
}s[1010];

bool cmp(node x,node y)
{
    return x.left<y.left;
}

int n,d,t=0;

int solve()
{
    int ans;
    double now;//记录当前的右端点
    ans=1;
    //选取一个点
    sort(s+1,s+1+n,cmp);
    now=s[1].right;
    for(int i=2;i<=n;i++)
    {
        if(s[i].left>now)
        {
            ans++;//新建节点
            now=s[i].right;//更新
        }
        else
        {
            now=min(now,s[i].right);//这里要取到小的那个右端点，保证区间覆盖
        }
    }
    return ans;
}

int main()
{

    while(cin>>n>>d)
    {
        ++t;
        if(n==0&&d==0)
            break;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(y>d) flag=false;//不成立的标记
            else
            {
                s[i].left=x - sqrt((double)d*d-y*y);//转化为区间问题
                s[i].right=x + sqrt((double)d*d-y*y);//把岛屿看成点，作圆交与x轴

            }

        }
        if(flag) printf("Case %d：%d\n",t,solve());
        else
            printf("Case %d：-1\n",t);
    }
    return 0;
}
