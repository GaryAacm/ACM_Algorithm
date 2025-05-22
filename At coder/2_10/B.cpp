#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n,op,a;
int s[maxn];
int main()
{
    cin>>n;
    int num=0;
    while(n--)
    {
        cin>>op>>a;

        if(op==1)
        {
            s[++num]=a;
            //cout<<"´ËÊ±£º"<<s[num]<<endl;
        }
        else
        {
            cout<<s[num-a+1]<<endl;
            //cout<<num<<' '<<num-a+1<<endl;
        }
    }
}
