#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m;//���������ͻ�������
struct node
{
    int time;
    int id;
}task[maxn];
int ans[maxn];
bool cmp(node x,node y)
{
    return x.time>y.time;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>task[i].time;
        task[i].id=i;
    }
    sort(task+1,task+1+n,cmp);
    //����
    for(int i=1;i<=n;)//��������
    {
        for(int j=1;j<=m;j++)
        {
            if(i<=n)
            {
                ans[j]+=task[i++].time;
            }//�������
        }
        sort(ans+1,ans+1+m);//�����ҳ�ʱ����С�ģ�֮����ȼ���ʱ�䳤������
    }
    sort(ans+1,ans+1+m);
    cout<<ans[m]<<endl;//ʱ��������
    return 0;
}
