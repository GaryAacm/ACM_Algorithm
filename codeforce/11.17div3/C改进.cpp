#include<bits/stdc++.h>
using namespace std;
int a[31];
signed main()
{
	int n;
	string s;
	cin>>n>>s;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i-1])
		{
			a[s[i-1]-'a']=max(a[s[i-1]-'a'],cnt);//�൱�ڼ��������ĸ���ӵ���ֵ�������Ա����ظ����ּ���ɹ�
			cnt=1;
		}
		else cnt++;
	}
	a[s[n-1]-'a']=max(a[s[n-1]-'a'],cnt);
	int ans=0;
	for(int i=0;i<26;i++) ans+=a[i];
	cout<<ans;
}
