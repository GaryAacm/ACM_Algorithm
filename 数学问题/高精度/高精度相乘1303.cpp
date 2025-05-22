#include<bits/stdc++.h>
using namespace std;
const int maxn=5100;
int a[maxn],b[maxn],c[maxn];
int main()
{
    string A,B;
    cin>>A>>B;
    for(int i=A.length()-1,j=1;i>=0;i--,j++)
    {
        a[j]=A[i]-'0';
    }
    for(int i=B.length()-1,j=1;i>=0;i--,j++)
    {
        b[j]=B[i]-'0';
    }//反转数据储存起来
    int lena=A.length();
    int lenb=B.length();
    for(int i=1;i<=lena;i++)
    {
        for(int j=1;j<=lenb;j++)
            c[i+j-1]+=a[i]*b[j];
    }//计算贡献
    int len=lena+lenb;
    for(int i=1;i<=len;i++)//模拟进位的过程
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }
    for(;!c[len];) len--;//去除首位的0
    for(int i=max(1,len);i>=1;i--)
    {
        cout<<c[i];
    }
    return 0;
}
