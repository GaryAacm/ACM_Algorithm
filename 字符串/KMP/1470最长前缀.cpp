#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;

int Next[maxn],cnt;
string s[205] ,ss="";
//char ss[maxn];
int dp[maxn];
void getFail(string p,int plen)//�õ�next����
{
    Next[0]=0;
    Next[1]=0;
    int j=0;
    for(int i=1;i<plen;i++)
    {
        j=Next[i];//�̳�ǰ���
        while(j&&p[i]!=p[j]) j=Next[j];
        Next[i+1]=(p[i]==p[j])?j+1:0;//�ܹ�������Ⱦͼ�һ
    }
}


bool kmp(string s,string p)
{
    int last=-1;
    int slen=s.length(),plen=p.length();
    getFail(p,plen);
    int j=0;

    for(int i=0;i<slen;i++)//��ʼƥ��
    {
        while(j&&p[j]!=s[i]) j=Next[j];//ʧ��
        if(s[i]==p[j]) j++;//����ƥ��
        if(j==plen)//ƥ��ɹ�
        {
            //printf("%d\n",i+2-plen);
            return true;
        }
    }
    /*for(int i=1;i<=strlen(p);i++)
    {
        printf("%d ",Next[i]);
    }*/
    return false;
}
string temp;
int main()
{
    //freopen("D:\\�㷨����\\�ַ���\\KMP\\in.txt","r",stdin);
    int order=0;
    for(string sa;cin>>sa,sa!=".";s[order++]=sa);
    for(string sa;cin>>sa;ss+=sa);

    int ans=0;
    //cout<<order<<endl;
    for(int i=0;ss[i];i++)
    {
        temp+=ss[i];
        //cout<<temp<<endl;
        for(int i=0;i<order;i++)
        {
            if(kmp(temp,s[i]))
            {

                ans+=temp.length();
                //cout<<ans<<endl;
                temp="";
                break;
                //cout<<ans<<endl;

            }
        }
    }
    printf("%d",ans);

    return 0;
}
