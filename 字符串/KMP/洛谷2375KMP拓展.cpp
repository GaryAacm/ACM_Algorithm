#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int mod=1e9+7;
typedef long long ll;
ll n,ans,nxt[maxn],t;
char s[maxn];
ll num[maxn];//��ʾ����ǰ׺���Ǻ�׺���Ӵ�����(ǰ��׺�����ص�)�����濿j��λλ��

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("D:\\�㷨����\\�ַ���\\KMP\\in.txt","r",stdin);
	cin>>t;
	while(t--)
    {
        cin>>(s+1);
        n=strlen(s+1);

        memset(nxt,0,sizeof(nxt));
        int j=0;
        num[1]=1;//һ���ַ�Ҳ��ǰ��׺���ַ�������Ҳ��ǰ��׺
        for(int i=2;i<=n;++i)
        {
            while(j&&s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1])  ++j;
            //����ƥ����ǰ׺�ͺ�׺����


            num[i]=num[j]+1;//�����Լ������ַ�������󹫹�ǰ׺�ͺ�׺�ĳ���
        }//����next����

        /*for(int i=1;i<=n;i++)
            cout<<num[i]<<" "<<nxt[i]<<endl;*/

        ans=1;

        for(int i=2,j=0;i<=n;i++)
        {
            while(j&&s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1]) ++j;
            //����ƥ����ǰ׺�ͺ�׺������ͬʱ�̳��ϴε�j���ᳬʱ
            //nxt[i]=j;//��T������ѭ��

            while((j<<1)>i) j=nxt[j];

            ans=(ans*(long long)(num[j]+1))%mod;

            //��������������ֱ����
            //j=i;

            /*while(nxt[j]*2>i)
            {

                //cout<<"��ʱ��i��"<<i<<endl;
                //cout<<"��ʱ��nxt[j]��"<<nxt[j]<<endl;
                j=nxt[j];
                //cout<<"�仯���j��"<<j<<endl;
                //cout<<"�仯���nxt[j]��"<<nxt[j]<<endl;

            }
            //cout<<"����nxt[j]��"<<nxt[j]<<endl;
            num[order++]=nxt[j];
            //cout<<num[j]<<endl;
            //ans=(ans*(j+1))%mod;
            //nxt[i]=j;*/
        }

        cout<<ans<<endl;

    }

    return 0;
}
