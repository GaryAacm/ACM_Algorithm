#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int dp[maxn];
int a[maxn],n,b[maxn],id[maxn];

//nƽ��������
/*
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;//��ʼ��
		for(int j=1;j<i;j++)//ö��i֮ǰ��ÿһ��j
		if(data[j]<data[i] && dp[i]<dp[j]+1)
		//��if�ж��Ƿ����ƴ�ճ����������У�
		//�����жϵ�ǰ״̬�Ƿ�����֮ǰö��
		//��������״̬,����ǣ����
		dp[i]=dp[j]+1;//��������״̬

	}
*/
//nlgn����
/*
int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=0x7fffffff;
		//��ʼֵҪ��ΪINF
		/*ԭ��ܼ򵥣�ÿ����һ���µ�Ԫ��ʱ���͸��Ѿ���¼��f���鵱ǰ����¼���
		���������е�ĩβԪ����Ƚϣ����С�ڴ�Ԫ�أ���ô�Ͳ�����ǰ�ң�ֱ���ҵ�
		һ���պñ������Ԫ�أ��滻����֮������ڣ�ô�ĩβԪ�ص���һ��q��INF
                ����Ϊ�˷�������滻����
	}
	f[1]=a[1];
	int len=1;//ͨ����¼f�������Чλ������ø���
	/*��Ϊ���������ᵽ�����п���Ҫ������ǰѰ�ң�
	���Կ��Բ��ö��ֲ��ҵĲ��ԣ�����ǽ�ʱ�临��
    �Ƚ���nlogn����Ĺؼ����ء�
	for(int i=2;i<=n;i++)
	{
		int l=0,r=len,mid;
		if(a[i]>f[len])f[++len]=a[i];
		//����պô���ĩβ����ʱ���˳�����
		else
		{
		while(l<r)
		{
		    mid=(l+r)/2;
		    if(f[mid]>a[i])r=mid;
	//�����ȻС��֮ǰ����¼����Сĩβ����ô����
	//��ǰѰ��(��Ϊ������������У�����f�����
	//Ȼ���㵥��)
			else l=mid+1;
		}
		f[l]=min(a[i],f[l]);//������Сĩβ
     	}
    }
    cout<<len;
*/

//ת��ΪLIS���⣬���ת����Ȼ�����ת���ҵ��������
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        id[a[i]]=i;//���±��
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

