#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;

bool dp[maxn]={1};//��ʾǰi��������Ϊ���ǰ׺
int n=0,ans=0;
string s[201],ss=" ";//��ʼ����һ��Ϊ�ո�����ռλ

bool Check(int p)
{
    for(int i=0;i<n;i++)//����ȫ������Ԫ��
    {
        int t=s[i].size();
        if(p>=t&&dp[p-t]&&s[i] ==ss.substr(p-t+1,t))//�ȶ��ϲ���ǰ��p-tҲƥ���ϣ�������������
        {
            ans=p;
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("D:\\�㷨����\\�ַ���\\KMP\\in.txt","r",stdin);
    for(string sa;cin>>sa,sa!=".";s[n++]=sa);
    for(string sa;cin>>sa;ss+=sa);
    for(int i=1;i<=ss.size();i++)
        dp[i]=Check(i);
    printf("%d\n",ans);
    //cout<<n<<endl;

    return 0;
}
