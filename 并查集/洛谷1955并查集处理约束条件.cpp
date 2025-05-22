/*这里数据太大，要离散化*/
/*#include<bits/stdc++.h>
using namespace std;
#define long long int
const int maxn=1e6+10;

int n,t,a,b,op;
int fa[maxn];
struct node
{

};

int finded(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=finded(fa[x]);
}

void join(int x,int y)
{
    int c1=finded(x),c2=finded(y);
    if(c1!=c2)
        fa[c1]=c2;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n*2;i++) fa[i]=i;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>op;
            if(op==1)
                join(a,b);
            else
            {
                join(a,b+n);//表示a与b不等
            }
        }
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            int xx=finded(i),yy=finded(i+n);
            if(xx==yy)
            {
                cout<<"NO"<<endl;
                f=false;
                break;
            }
        }
        if(f)
            cout<<"YES"<<endl;
    }
}*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int t,n,fa[maxn],book[maxn*3];  //t表示t组数据，n表示有n个操作，f[]是我们并查集的数字，book[]是离散化的数组
struct node
{
    int x,y,e;
}a[1000001];
bool cmp(node a,node b)
{
    return a.e>b.e;
}//排 序将e==1的放在前面

inline void first(int n)
{
    for(int i=0;i<=n;i++)  fa[i]=i;
}//初 始 化
int finded(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=finded(fa[x]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
      int tot=-1;
      int flag=1;
      scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].e);
            book[++tot]=a[i].x;
            book[++tot]=a[i].y;
        }
        sort(book,book+tot);//排序
        int reu=unique(book,book+tot)-book;  //去重
        //离散化
        for(int i=1;i<=n;++i)
        {
           a[i].x=lower_bound(book,book+reu,a[i].x)-book;
           a[i].y=lower_bound(book,book+reu,a[i].y)-book;
        }
        first(reu); //初始化
        sort(a+1,a+n+1,cmp); //按e排序
        for(int i=1;i<=n;i++)
        {
            int r1=finded(a[i].x);
            int r2=finded(a[i].y);
            if(a[i].e)
            {
                fa[r1]=r2;//合并
            }
            else if(r1==r2)
            {
                printf("NO\n");
                flag=0;  //如果不满足条件，标记为否
                break;
            }
        }
        if(flag)    printf("YES\n");   //都满足条件了
    }
    return 0;
}
