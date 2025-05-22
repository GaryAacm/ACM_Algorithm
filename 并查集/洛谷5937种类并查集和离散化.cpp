#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;

ll n,m,fa[maxn<<1],book[maxn],tot=0;
struct node
{
    ll x,y;
    string s;
}a[maxn];

ll finded(ll x)
{
    if(x==fa[x]) return x;
    return fa[x]=finded(fa[x]);
}

void join(ll x,ll y)
{
    ll c1=finded(x),c2=finded(y);
    if(c1!=c2) fa[c1]=c2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].s;
        book[++tot]=a[i].x;
        book[++tot]=a[i].y;
    }
    sort(book+1,book+tot+1);
    ll reu=unique(book+1,book+1+tot)-book-1;

    for(int i=1;i<=m;++i)
    {
        a[i].x=lower_bound(book+1,book+reu+1,a[i].x)-book;
        a[i].y=lower_bound(book+1,book+reu+1,a[i].y)-book;
    }
    for(int i=1;i<=reu*2;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(a[i].s=="even")//偶数
        {
            if(finded(a[i].x)==finded(a[i].y+reu)||finded(a[i].x+reu)==finded(a[i].y))
            {
                cout<<i-1;
                return 0;
            }

            else
            {
                join(a[i].x,a[i].y);
                join(a[i].x+reu,a[i].y+reu);
            }
        }
        else//奇数
        {
            if(finded(a[i].x)==finded(a[i].y)||finded(a[i].x+reu)==finded(a[i].y+reu))
            {
                cout<<i-1;
                return 0;
            }
            else
            {
                join(a[i].x,a[i].y+reu);
                join(a[i].x+reu,a[i].y);
            }
        }
    }
    cout<<m;
    return 0;
}
