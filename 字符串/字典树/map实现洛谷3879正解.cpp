#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int n, m, num, cnt[maxn];
string s;
map<string,vector<int> >a;
int main()
{
	std::ios::sync_with_stdio(false);//Ҫ�ر�ͬ������ܶ�
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>num;
		for(int j = 1; j <= num; j++)
		{
			cin>>s;
			a[s].push_back(i);//vector��ѹ���������ÿһ�����ʾ���һ��vector��
		}
	}
	cin>>m;
	for(int i = 1; i <= m; i++)
	{
		cin>>s;
		memset(cnt,0,sizeof(cnt));//cnt����ȥ�ص�Ͱ��ÿ��һ�������ͬ�Ĳ�ѯҪ���㡣
		for(int j = 0; j < a[s].size(); j++)//a[s].size()��vector�Զ������䳤�ȵĺ�����
		if(cnt[a[s][j]] == 0)
		{
			cout<<a[s][j]<<" ";//���Ǵ�ľ��Ǵ�����������ֵľ��ӵı�ţ�����ֱ���������bb�����Ҵ��ʱ��Ҳ�ǰ�˳������¼�ġ�
			cnt[a[s][j]]++;//��������Ͱȥ�أ�
		}
		cout<<endl;
	}
	return 0;
}
