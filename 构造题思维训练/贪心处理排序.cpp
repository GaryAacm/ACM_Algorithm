/*���Ų������⣬����������b��С�ĺ�a����ƥ�䣬��ȷ���ܹ�ƥ����
����a��������������С�ĺ�b���������Ա�
����һζ���������ģ���ҵ���ͬλ�õĽ��н��������翼��̰�ĵ�˼�����ƥ��*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,k;
struct node
{
    int id,val;
}e[maxn];

int b[maxn];
bool cmp1(node x,node y)
{
    return x.val>y.val;
}

bool cmp2(node x,node y)
{
    return x.val<y.val;
}
int ans[maxn];
int solve()
{
    sort(e + 1, e + n + 1, cmp1);
    sort(b + 1, b + n + 1);
    sort(e + 1, e + k + 1, cmp2);//ǰ��������������С��ƥ����ȷ��
    for(int i=1;i<=k;i++)
    {
        if(e[i].val<=b[i])
            return 0;
        ans[e[i].id]=b[i];
    }
    sort(e+k+1,e+n+1,cmp2);
    for(int i=k+1;i<=n;i++)
    {
        if(e[i].val>b[i])
            return 0;
        ans[e[i].id]=b[i];
    }
    return 1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for (int i = 1; i <= n; i++)
            e[i].id = i, cin >> e[i].val;

        for (int i = 1; i <= n; i++)
            cin >> b[i];

        if (!solve())
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';

        cout << '\n';

    }
}

