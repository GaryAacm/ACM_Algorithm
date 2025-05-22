#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int t,n,k;
char a[maxn];
int pos[maxn];//记录出现B的位置
int posA[maxn];
int sumB;
struct node
{
    int nums;
    char ss;
}anss[maxn];
int main()
{
    freopen("D:\\算法进阶\\codeforce\\11.19div2\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>a+1;
        int tot=1,frontnum;
        char c;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='B')
            {
                pos[num++]=i;

            }
        }
        int numA=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='A')
            {
                posA[numA++]=i;

            }
        }
        sumB=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='B')
                sumB++;
        }
        int countB=1;
        //cout<<sumB<<endl;
        if(sumB==k)
            cout<<'0'<<endl;

        else if(sumB>k)//减少B
        {

            c='A';
            int countA=1;
            int need=sumB-k;
            for(int i=0;i<numA;i++)
            {
                if(posA[i]-countA>=need)
                {
                    frontnum=need+countA-1;
                    countA++;
                    sumB--;
                    if(sumB==k)
                        break;
                }
            }




            cout<<tot<<endl;
            cout<<frontnum<<' '<<c<<endl;

        }
        else
        {
            int need=k-sumB;
            c='B';
            for(int i=0;i<num;i++)
            {
                if(pos[i]-countB>=need)
                {
                    frontnum=need+countB-1;
                    //cout<<countB<<endl;
                    //cout<<need<<endl;
                    countB++;
                    sumB++;
                    if(sumB==k)
                        break;
                }

            }
            cout<<tot<<endl;
            cout<<frontnum<<' '<<c<<endl;
        }


    }
    return 0;
}

