#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int disf=1,disc=1;//初始表示往上，2表示右，3下，4左
int fx,fy,cx,cy;
int walkx[5]={0,-1,0,1,0},walky[5]={0,0,1,0,-1};

int main()
{
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='F')
            {
                fx=i;
                fy=j;
            }
            if(a[i][j]=='C')
            {
                cx=i;
                cy=j;
            }
        }
    }
    int ans=0;

    while(1)
    {
        if(ans>=100000)
        {
            cout<<0<<endl;
            break;
        }
        if(fx==cx&&fy==cy)
        {
            cout<<ans<<endl;
            break;
        }

        ans++;

        if(disf==1)
        {
            int fxu=fx+walkx[1],fyu=fy+walky[1];
            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disf=2;
            }
            else
            {
                fx=fxu;
                fy=fyu;
            }
        }
        else if(disf==2)
        {
            int fxu=fx+walkx[2],fyu=fy+walky[2];
            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disf=3;
            }
            else
            {
                fx=fxu;
                fy=fyu;
            }
        }
        else if(disf==3)
        {
            int fxu=fx+walkx[3],fyu=fy+walky[3];
            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disf=4;
            }
            else
            {
                fx=fxu;
                fy=fyu;
            }
        }
        else if(disf==4)
        {
            int fxu=fx+walkx[4],fyu=fy+walky[4];
            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disf=1;
            }
            else
            {
                fx=fxu;
                fy=fyu;
            }
        }

        if(disc==1)//上
        {
            int fxu=cx+walkx[1],fyu=cy+walky[1];

            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disc=2;
            }
            else
            {
                cx=fxu;
                cy=fyu;
            }
        }
        else if(disc==2)
        {
            int fxu=cx+walkx[2],fyu=cy+walky[2];

            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disc=3;
            }
            else
            {
                cx=fxu;
                cy=fyu;
            }
        }
        else if(disc==3)
        {
            int fxu=cx+walkx[3],fyu=cy+walky[3];
            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disc=4;
            }
            else
            {
                cx=fxu;
                cy=fyu;
            }
        }
        else if(disc==4)
        {
            int fxu=cx+walkx[4],fyu=cy+walky[4];
            if(a[fxu][fyu]=='*'||fxu<1||fyu<1||fxu>10||fyu>10)
            {
                disc=1;
            }
            else
            {
                cx=fxu;
                cy=fyu;
            }
        }
    }

    return 0;
}
