#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 1005;

int a[N];

int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans = 1;
        for(int i=1;i<=n;i++)
        {
            int tmp = a[i];
            int num = 1;
            while(tmp != i)
            {
                tmp = a[tmp];
                num++;
            }
            ans = lcm(ans,num);
        }
        printf("%d\n",ans);
    }
    return 0;
}

