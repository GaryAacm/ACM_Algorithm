#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
int main(void)
{
  int h, w, a[6][6], b[6][6];
  cin >> h >> w;
  for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
  for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> b[i][j];

  int p[6], q[6];
  for(int i = 1; i <= h; i++) p[i] = i;
  for(int i = 1; i <= w; i++) q[i] = i;//记录原来的下标

  int ans = inf;
  do{
    do{

      bool match = true;
      for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++)
      {
        if(a[p[i]][q[j]] != b[i][j]) match = false;//出现匹配不上的
      }
      if(!match) continue;//有不相等的

      int pinv = 0, qinv = 0;//操作次数就是逆序数
      for(int i = 1; i <= h; i++) for(int j = i+1; j <= h; j++) if( p[i] > p[j]) pinv++;
      for(int i = 1; i <= w; i++) for(int j = i+1; j <= w; j++) if( q[i] > q[j]) qinv++;
      ans = min(ans, pinv+qinv);

    }while(next_permutation(q+1, q+w+1));
  }while(next_permutation(p+1, p+h+1));//全排列枚举全部的行和列组合，记录的是行和列的下标的全排列

  if(ans == inf) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
