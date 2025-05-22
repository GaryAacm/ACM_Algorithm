#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int k,g,m;
int glass=0,mug=0;

int main()
{
    cin>>k>>g>>m;
    k--;
    mug=m;
    while(k--)
    {
        if(glass==g) glass=0;
        else if(mug==0) mug=m;
        else
        {
            if(m<g)
            {
                int temp=g-glass;
                if(mug<temp)
                {
                    glass+=mug;
                    mug=0;

                }
                else
                {

                    glass+=temp;
                    mug-=temp;
                }
            }

            else
            {
                int temp=g-glass;
                if(mug>=temp)
                {
                    glass+=temp;
                    mug-=temp;
                }

                else
                {

                    glass+=mug;
                    mug=0;
                }
            }

        }
    }
    cout<<glass<<' '<<mug;

    return 0;
}
