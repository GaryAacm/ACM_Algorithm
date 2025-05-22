#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int n;

    for(int i=0;i<10;i++)
        a[i]=i;

    for(int s=0;s<(1<<10);s++)//
    {
        if(__builtin_popcount(s)==3)
        {
            for(int i=0;i<10;i++)
            {
                if(s&(1<<i)) cout<<a[i];

            }
            cout<<endl;
        }
    }
    return 0;
}

