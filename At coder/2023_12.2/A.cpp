#include<bits/stdc++.h>
using namespace std;

int M,D;
int year,mon,day;
int ansy,ansm,ansd;
int main()
{
    cin>>M>>D;
    cin>>year>>mon>>day;
    if(mon==M)
    {
        if(day==D)
            cout<<year+1<<' '<<1<<' '<<1<<endl;
        else
        {
            cout<<year<<' '<<mon<<' '<<day+1<<endl;
        }
    }
    else
    {
        if(day==D)
            cout<<year<<' '<<mon+1<<' '<<1<<endl;
        else
            cout<<year<<' '<<mon<<' '<<day+1<<endl;
    }

    return 0;
}
