#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, m;
long long ans;
const int mod = 1e9 + 7; 

long long p(long long base, long long r)        
{
    long long ret = 1;
    while (r) {
        if (r & 1) 
			ret = ret * base % mod;
        base = base * base % mod;
        r >>= 1;
    }
    return ret;
}
long long inv(long long x)
{
    return p(x, mod - 2);
}

int main()
{
	int t;
    scanf("%d",&t);
    while(t --) {
        scanf("%lld%lld", &n, &m);
        if(n & 1)    
			ans = (p(p(2, n) - 1, m - 1) * 2 % mod + 1) * inv(3) % mod;
        else 
			ans = p(p(2, n) - 1, m - 1) * 2 % mod * inv(3) % mod;
        printf("%lld\n",ans);
    }
}
