/*不一定要建树，就是搞好遍历的顺序*/
#include<bits/stdc++.h>
using namespace std;

int n;
char a[1005][3];

void solve(char x)
{
    if(x!='*')
    {
        //cout<<x; //先序
        for(int i=1;i<=n;i++)
        {
            if(a[i][0]==x)
            {
                solve(a[i][1]);
                cout<<x;//中序
                solve(a[i][2]);
                //cout<<x;//后序
            }
        }
    }
    return ;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    solve(a[1][0]);
    return 0;
}
