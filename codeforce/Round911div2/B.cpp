#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  {
     cin>>x>>y>>z;
     int ans=0;
     for(int i=0;i<x;i++) ans^=1;
     for(int i=0;i<y;i++) ans^=2;
     for(int i=0;i<z;i++) ans^=3;
     if(ans==0)
        printf("1 1 1\n");
     else if(ans==1)
        printf("1 0 0\n");
     else if(ans==2)
        printf("0 1 0\n");
     else
        printf("0 0 1\n");

  }
  return 0;
}
