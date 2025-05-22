#include<bits/stdc++.h>
using namespace std;

int Find(string s,string t,int *sa)
{
    int i=0,j=s.length();
    while(j-i>1)
    {
        //二分查找
        int mid=(j+i)/2;
        if(s.compare(sa[mid],t.length(),t)<0)
            i=mid;
        else
            j=mid;
    }

    if(s.compare(sa[i],t.length(),t)==0)
        return sa[i];
    if(s.compare(sa[j],t.length(),t)==0)
        return sa[j];
    return -1;
}

int main()
{
    string s="vamamadn",t="mad";
    int sa[]={5,3,1,6,4,2,7,0};//后缀数组记录，从字典序最小的开始，记录出现的位置
    int location=Find(s,t,sa);
    cout<<location<<endl;

    return 0;
}
