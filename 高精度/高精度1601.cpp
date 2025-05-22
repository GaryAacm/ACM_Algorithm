#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int a[maxn],b[maxn],c[maxn];
int main()
{
    string A,B;
    cin>>A>>B;
    int len=max(A.length(),B.length());
    for(int i=A.length()-1,j=1;i>=0;i--,j++)
    {
        a[j]=A[i]-'0';
    }
    for(int i=B.length()-1,j=1;i>=0;i--,j++)
    {
        b[j]=B[i]-'0';
    }//反转数据储存起来
    for(int i=1;i<=len;i++)//模拟进位的过程
    {
        c[i]+=a[i]+b[i];
        c[i+1]=c[i]/10;
        c[i]=c[i]%10;
    }
    if(c[len+1]) len++;//最高位有进位
    for(int i=len;i>=1;i--)
    {
        cout<<c[i];
    }
    return 0;
}
