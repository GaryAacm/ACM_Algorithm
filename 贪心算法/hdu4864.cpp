#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct Task
{
    int time,val;
}task[maxn];

struct Machine
{
    int t,v;
}machine[maxn];

bool cmp1(Task a,Task b)
{
    if(a.time!=b.time)
        return a.time>b.time;
    return a.val>b.val;
}


bool cmp2(Machine x,Machine y)
{
    if(x.t!=y.t)
        return x.t>y.t;
    return x.v>y.v;
}

int n,m,cnt;
long long ans;
int vis[maxn];

//����ؼ�����������ʱ��Ҫ�����������ȿ��ǵȼ��͵��ǿ����������Ļ���
int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)//��������
           cin>>machine[i].t>>machine[i].v;
    for(int i=1;i<=m;i++)//��������
        cin>>task[i].time>>task[i].val;
    cnt=0;
    ans=0;
    sort(machine+1,machine+1+n,cmp2);
    sort(task+1,task+1+m,cmp1);
    memset(vis,0,sizeof(vis));
    int j=1;
    for(int i=1;i<=m;++i)//��������
    {

        while(j<=n&&machine[j].t>=task[i].time)//����ʱ��Ҫ��,������Ϊ�Ź���ǰ���ʱ��Ҫ�󣬺����ʱ��С��ǰ���ʱ�������������ʱ��
        {
            vis[machine[j].v]++;
            j++;//ͳ������ʱ����Ҫ��Ļ����ĵȼ�����
        }
        for(int k=task[i].val;k<=100;k++)
        {
            if(vis[k])//�ж�Ӧ�ĵ͵ȼ�����
            {
                cnt++;
                vis[k]--;//�õ�һ̨
                ans+=500*task[i].time+2*task[i].val;
                break;
            }
        }
    }
    cout<<cnt<<' '<<ans<<endl;
    }

    return 0;
}
