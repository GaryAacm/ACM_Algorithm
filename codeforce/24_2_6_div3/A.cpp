#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;


int n,t;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int pos1,pos2;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')
            {
                pos1=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='B')
            {
                pos2=i;
                break;
            }
        }
        cout<<pos2-pos1+1<<endl;
    }
}
