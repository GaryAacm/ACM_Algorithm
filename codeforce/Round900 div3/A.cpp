#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn=105;
int n,k,t;
int num[maxn];
int a[maxn];

int main()
{
    //freopen("D:\\算法进阶\\codeforce\\Round900 div3\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int pos=-1;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==k)
                pos=i;//记录位置
        }
        if(pos==-1) cout<<"NO"<<endl;
        else if(pos==n) cout<<"YES"<<endl;

        else
        {
            num[k]++;
            for(int i=pos;i<n;i++)
            {
                int flag=0;
                for(int j=i+1;j<=n;j++)
                {
                    num[j]++;
                    int maxx=max(num[j],num[k]);
                    if(maxx==num[k])
                    {
                        cout<<"YES"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
        }
    }
    return 0;
}

/*
//更快的做法，只要找到出现这个数k就行
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (std::find(a.begin(), a.end(), k) != a.end()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
*/
