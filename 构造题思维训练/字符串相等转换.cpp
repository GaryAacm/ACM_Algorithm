/* https://codeforces.com/problemset/problem/1861/B */

/*˼·������ߵ�һ����0���ұ����һ����1����ô���������ľͻ�����ͬλ�ó���01���������ȫ���0���ұ�ȫΪ1*/
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
