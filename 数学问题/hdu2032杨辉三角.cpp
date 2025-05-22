#include<bits/stdc++.h>
using namespace std;
long long c[31][31];

int main()
{
    for(int i=0;i<=30;++i)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        int k=a;
        //cout<<k<<endl;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                cout<<c[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }



    return 0;
}

/*
#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[31][31];
        for(int i=0;i<n;i++){
            a[i][0]=1;a[i][i]=1;
            for(int j=1;j<i;j++)
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<=i;j++){
                if(p==0){printf("%d",a[i][j]);p=1;}
                else printf(" %d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
            return 0;
}
*/
