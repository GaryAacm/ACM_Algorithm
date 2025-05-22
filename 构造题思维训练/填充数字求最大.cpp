#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int n,t,a[3][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        a[1][1]=n*2;
        a[2][n]=n*2-1;
        int k=0;
        int p=n;
        //把大的数填充在第一行奇数位置和第二行偶数位置
        for(int i=2;i<=n;i+=2)
        {
            k++;
            a[1][i]=k;
            k++;
            a[2][i-1]=k;
        }
        for (int i = 3; i <= n; i += 2 )
        {
			p ++;
			a[1][i] = p;
			p ++;
			a[2][i - 1] = p;
		}
		for (int i = 1; i <= 2; ++ i )
		{
			for (int j = 1; j <= n; ++ j )
				cout << a[i][j] << " ";
			cout << endl;
		}
    }
}
