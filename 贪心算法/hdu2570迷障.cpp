#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int t,n,v,k;
double ans,ss,w;//物质的量和体积
int val[maxn];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>v>>w;
        memset(val,0,sizeof(val));
        for(int i=1;i<=n;i++)
        {
            //输入药水的浓度
            cin>>val[i];
        }
        sort(val+1,val+1+n);
        //排序，找到浓度最小的
        int i;
        if(val[1]>w)
            {
                cout<<"0"<<' '<<"0.00"<<endl;
                continue;
            }
        ans=0,ss=0,k=0;//注意初始化
        for(i=1;i<=n;i++)
        {
            //遍历药水浓度
            ans+=val[i]*v/100;

            if(ans/(i*v)*100<=w)
            {
                //可以继续加
                ss=ans/(i*v);//浓度增加
                k++;
            }
            else{
                break;
            }
        }
		printf("%d %.2f\n",(i-1)*v,ss);
    }
    return 0;
}
