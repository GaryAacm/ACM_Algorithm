#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;

//�ַ����й�ͬ���㹱�ף���ͬ��Ԥ����ö���·ֳ����Ķ೤
//mapö�ٲ�Ʊǰ��ĳ��ȣ��Լ�������Ҫ�ģ�ǰ����һ��
string s[maxn];
map<pair<int,int>,int>mapp;
int n;
signed main()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        int len=s[i].size();
        sum=0;
        for(int j=0;j<len;j++)
        {
            sum+=s[i][j]-'0';
        }
        mapp[{len,sum}]++;//��¼��Ӧ�ĳ�����ͳ��ֵĴ���
    }

    //ö��ǰ׺�ͺ�׺�������
    int ans=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        int len=s[i].size();
        int all=0;
        for(int j=0;j<len;j++)
        {
            all+=s[i][j]-'0';
        }

        sum=0,sum2=0;
        int tmp=0;//��¼��ǰ�ĳ���
        for(int j=0;j<len;j++)
        {
            tmp++;
            sum+=s[i][j]-'0';
            sum2+=s[i][len-1-j]-'0';
            ans+=mapp[{2*tmp-len,2*sum-all}];
            if(!(j==len-1))//�ܵ�ԭ����ʱ��ֻ��һ�ι���
                ans+=mapp[{2*tmp-len,2*sum2-all}];
        }
    }
    cout<<ans<<endl;

}

