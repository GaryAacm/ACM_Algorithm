#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x1,y11,x2,y2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>x1>>y11;
    cin>>x2>>y2;
    if(x1*y2<(ll)(−2147483648)||y11*y2>(ll)(2147483648)||x1*x2<(ll)(−2147483648)||x2*y11<(ll)(−2147483648))
        cout<<"long long int"<<endl;
    else
         cout<<"int"<<endl;
    return 0;

}
