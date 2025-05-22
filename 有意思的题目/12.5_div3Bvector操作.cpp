#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\codeforce\\12.5_div3\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        string s;
        vector<int> a,b;//存储大小写字母的位置
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')
            {
                if(a.size()) a.pop_back();//删除小写字母最后一位
            }
            else if(s[i]=='B')
            {
                if(b.size()) b.pop_back();
            }
            else
            {
                if(s[i]>='a'&&s[i]<='z')
                    a.push_back(i);
                else
                    b.push_back(i);
            }
        }
        int k1=0,k2=0;
        while(k1<a.size()||k2<b.size())
        {
            if(k1<a.size()&&(k2>=b.size()||a[k1]<b[k2]))
            {
                cout<<s[a[k1]];
                k1++;
            }
            else
                {
                    cout<<s[b[k2]];
                    k2++;
                }
        }
        cout<<endl;
    }
    return 0;
}
