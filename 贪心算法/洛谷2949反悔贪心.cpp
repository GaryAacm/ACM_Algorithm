#include<bits/stdc++.h>
using namespace std;

struct node
{
    int time,val;
}a[100001];
bool cmp(node x,node y)
{
    return x.time<y.time;//���ҵ���ֹʱ��̵�����
}
int n;
long long ans;
priority_queue<int,vector<int>,greater<int> > Q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].time>>a[i].val;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].time<=Q.size())//����С�ڵ�ǰ��ɵ�������������Ϊһ��ֻ��һ�������ڷ�����������
        {
            if(a[i].val>Q.top())//�ҵ���ֵ����ģ�����
            {
                ans-=Q.top();//�����������
                Q.pop();
                ans+=a[i].val;
                Q.push(a[i].val);
            }
        }
        else//�����ҵ�һ��������
        {
            Q.push(a[i].val);
            ans+=a[i].val;
        }
    }
    cout<<ans<<endl;
    return 0;
}

