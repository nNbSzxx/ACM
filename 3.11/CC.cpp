#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
typedef unsigned long long LL;  
  
int main()  
{  
    int n,a,b,c;  
    scanf("%d%d%d",&n,&a,&b);  
    c=max(a,b);  
    n--;  
  
    LL ans = 1, tmp = 1, sum = 1;  
    for(int i=1;i<=c;i++)  
    {  
        tmp = tmp*(n+i)/i;  
        sum += tmp;  
  
        if (i==a) ans *= sum;  
        if (i==b) ans *= sum;  
    }  
  
    printf("%I64u\n", ans);  
}  

