/* https://codeforces.com/problemset/problem/1861/B */

/*思路在于左边第一个是0，右边最后一个是1，那么满足条件的就会在相同位置出现01，即把左边全变成0，右边全为1*/
#include<bits/stdc++.h>
using namespace std;

int t;
string a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int n=a.length();
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(a[i]=='0'&&a[i+1]=='1'&&b[i]=='0'&&b[i+1]=='1')
            {
                cout<<"Yes"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<"No"<<endl;
    }
}
