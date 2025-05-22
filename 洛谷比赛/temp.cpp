#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x1,y11,x2,y2;

int main()
{

    //freopen("D:\\算法进阶\\洛谷比赛\\in.txt","r",stdin);
    cin>>x1>>y11;
    cin>>x2>>y2;
    if((y2>=46341&&y11>=46341)||(x1<=-46341&&x2<=-46341)||(x1<=-46341&&y2>=46341)||(x2<=-46341&&y11>=46341))
        cout<<"long long int"<<endl;
    else
         cout<<"int"<<endl;
    return 0;

}
