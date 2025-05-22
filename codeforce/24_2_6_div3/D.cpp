/*一定存在相邻两个不相等的*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;

int main()
{

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), p(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 2; i <= n; i++){
            if (a[i] != a[i - 1]) p[i] = i - 1;
            else p[i] = p[i - 1];
        }
        int q;
        cin >> q;
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            if (p[r] >= l){
                cout << p[r] << ' ' << r << '\n';
            }
            else{
                cout << -1 << ' ' << -1 << '\n';
            }
        }
    }

}
