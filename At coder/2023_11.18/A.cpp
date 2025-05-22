#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
    scanf("%s",s);

    for(int i=0;i<strlen(s)-1;i++)
    {
        printf("%c ",s[i]);
    }

    printf("%c",s[strlen(s)-1]);

    return 0;
}
