#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;

int t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x,y,z;
        for(int i=1;i<=n;i++)
    	{
    		int k;
    		cin>>k;
    		if(k==1) x=i;
    		if(k==2) y=i;
    		if(k==n) z=i;
		}

		if (x > y) swap(x, y); // 交换一下方便操作

        if (z > y) cout << y << ' ' << z; // 形如 2 1 n, 1 2 n
        else if (z < x) cout << z << ' ' << x; // 形如 n 1 2, n 2 1
        else cout << "1 1";
    }
}
