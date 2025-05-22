#include<bits/stdc++.h>
using namespace std;
int t;
int a[1005];
int temp;
int main()
{

    cin>>t;
    while(t--)
    {
        cin>>temp;
        if(temp%3==0)
            cout<<"Second"<<endl;
        else
            cout<<"First"<<endl;
    }

    return 0;
}
