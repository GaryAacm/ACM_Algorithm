#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("D:\\�㷨����\\�ַ���\\in.txt","r",stdin);
    char str[11];
    map<string,int> m;
    while(gets(str))
    {
        int len=strlen(str);
        if(!len) break;//����
        for(int i=len;i>0;i--)
        {
            str[i]='\0';//����պ����
            m[str]++;//ͳ��ǰ׺���ֵĴ���
        }
    }

    while(gets(str)) cout<<m[str]<<endl;

    return 0;
}
