#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll p[15],an[15];
ll fac[100005],inv[100005];
ll pow_mod(ll a, int n, int mod)
{
    ll ret = 1;
    while (n)
    {
        if (n&1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}
void ini(int x)
{
    fac[0] = 1;
    for(int i = 1; i < x; i++) fac[i] = fac[i-1]*i%x;
    inv[x - 1] = pow_mod(fac[x-1],x-2,x);
    for(int i = x - 2; i >= 0; i--)   inv[i] = inv[i+1] * (i+1) % x;
}
ll c(ll a,ll b,ll p)
{
    if(a < b || a < 0 || b < 0)
        return 0;
    return fac[a]*inv[b]%p*inv[a-b]%p;
}
ll lucas(ll a,ll b, int p)
{
    if( b == 0)
        return 1;
    return lucas(a/p,b/p,p)*c(a%p,b%p,p)%p;
}
ll ex_gcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ex_gcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
ll mul(ll a, ll b, ll mod)
{
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    ll ret = 0;
    while(b)
    {
        if(b&1)
        {
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        b >>= 1;
        a <<= 1;
        if(a >= mod) a -= mod;
    }
    return ret;
}
ll china(ll n,ll* a,ll* b)
{
    ll M = 1,d,y,x= 0;
    for(int i = 0; i < n; i++)
    {
        M *= b[i];
    }
    for(int i = 0; i < n; i++)
    {
        ll w = M/b[i];
        ex_gcd(b[i],w,d,y);
        x = (x + mul(mul(y, w, M), a[i], M));//¿ÉÄÜ³¬·¶Î§
    }
    return (x+M) % M;
}
int main()
{
    int T,k;
    ll n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&n,&m);
        scanf("%d",&k);
        for(int i = 0; i < k; i++)
        {
            scanf("%I64d",&p[i]);
            ini(p[i]);
            an[i] = lucas(n,m,p[i]);
        }
        printf("%I64d\n",china(k,an,p));
    }
    return 0;
}
