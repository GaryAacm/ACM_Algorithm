#include<bits/stdc++.h>
using namespace std;
#define mod 233
#define base 150
const int maxn=2e5+10;
vector<string> linker[mod+2];

char a[maxn];
int n,ans;
int main()
{
    //freopen("D:\\�㷨����\\At coder\\2023_11.18\\in.txt","r",stdin);
    //cin>>n;
    scanf("%d",&n);
    /*for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }*/
    scanf("%s",a);
    ans=1;
    int hashs=1;
    hashs=(hashs*base*111+a[0])%mod;//�����ϣֵ
    string ss="";
    ss+=a[0];
    linker[hashs].push_back(ss);
    for(int i=1;i<n;i++)
    {
        if(a[i]==ss[0])//�ϲ�,�µ��Ӵ�
        {
            ss=ss+a[i];

            hashs=(hashs*base*111+a[i])%mod;//�����ϣֵ
            int flag=1;
            for(int i=0;i<(int)(linker[hashs].size());i++)
           {

              if(linker[hashs][i]==ss)
               {
                   flag=0;
                   break;//���ظ��ĳ���
               }

           }
           if(flag)
           {
               linker[hashs].push_back(ss);
               ans++;//�µ��Ӵ�
           }

        }
        else
        {
            ss="";//�ÿ�
            ss+=a[i];
            hashs=1;
            hashs=(hashs*base*111+a[i])%mod;//�����ϣֵ
            int flag=1;
            for(int i=0;i<(int)(linker[hashs].size());i++)
           {

              if(linker[hashs][i]==ss)
               {
                   flag=0;
                   break;//���ظ��ĳ���
               }

           }
           if(flag)
           {
               linker[hashs].push_back(ss);
               ans++;//�µ��Ӵ�
           }
        }


    }
    printf("%d",ans);

    return 0;

}
