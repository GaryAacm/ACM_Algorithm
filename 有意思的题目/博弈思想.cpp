#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;

int n,a[N],b[N],c[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i <= n;i ++) cin >> b[i];
    ll sum = 0;
    for(int i = 1;i <= n;i ++){
        sum -= (b[i] - 1);//���������÷���С��
        c[i] = (a[i] - 1) + (b[i] - 1);//����˿�ͱ��������÷�
    }
    sort(c + 1,c + 1 + n,greater <int>());
    for(int i = 1;i <= n;i += 2) sum += c[i];
    cout << sum << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
