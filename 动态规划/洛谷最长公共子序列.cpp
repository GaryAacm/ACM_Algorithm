#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int dp[maxn];
int a[maxn],n,b[maxn],id[maxn];

//n平方的做法
/*
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;//初始化
		for(int j=1;j<i;j++)//枚举i之前的每一个j
		if(data[j]<data[i] && dp[i]<dp[j]+1)
		//用if判断是否可以拼凑成上升子序列，
		//并且判断当前状态是否优于之前枚举
		//过的所有状态,如果是，则↓
		dp[i]=dp[j]+1;//更新最优状态

	}
*/
//nlgn做法
/*
int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=0x7fffffff;
		//初始值要设为INF
		/*原因很简单，每遇到一个新的元素时，就跟已经记录的f数组当前所记录的最长
		上升子序列的末尾元素相比较：如果小于此元素，那么就不断向前找，直到找到
		一个刚好比它大的元素，替换；反之如果大于，么填到末尾元素的下一个q，INF
                就是为了方便向后替换啊！
	}
	f[1]=a[1];
	int len=1;//通过记录f数组的有效位数，求得个数
	/*因为上文中所提到我们有可能要不断向前寻找，
	所以可以采用二分查找的策略，这便是将时间复杂
    度降成nlogn级别的关键因素。
	for(int i=2;i<=n;i++)
	{
		int l=0,r=len,mid;
		if(a[i]>f[len])f[++len]=a[i];
		//如果刚好大于末尾，暂时向后顺次填充
		else
		{
		while(l<r)
		{
		    mid=(l+r)/2;
		    if(f[mid]>a[i])r=mid;
	//如果仍然小于之前所记录的最小末尾，那么不断
	//向前寻找(因为是最长上升子序列，所以f数组必
	//然满足单调)
			else l=mid+1;
		}
		f[l]=min(a[i],f[l]);//更新最小末尾
     	}
    }
    cout<<len;
*/

//转换为LIS问题，标号转换，然后根据转换找到最长子序列
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        id[a[i]]=i;//重新标号
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        //dp[i]=0x7f7f7f7f;
    }
    int len=0;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(id[b[i]]>dp[len]) dp[++len]=id[b[i]];
        else
        {
            int j=lower_bound(dp+1,dp+1+len,id[b[i]])-dp;
            dp[j]=id[b[i]];
        }
    }
    cout<<len<<endl;
    return 0;
}

