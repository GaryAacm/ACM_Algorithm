#include<bits/stdc++.h>
using namespace std;
struct p
{
    int l,r;
}a[1000001];
int finish=0;
int  n,ans=0;
bool cmp(p a,p b)
{
    return a.r<b.r;//���ر����������
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i)
    {
        if(finish<=a[i].l)
        {
            ans++;
            finish=a[i].r;//�趨��ֹʱ��Ϊ�Ƚ϶���
        }
    }
    cout<<ans;
    return 0;
}
