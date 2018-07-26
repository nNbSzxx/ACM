#include <cstdio>
typedef long long lld;
int modulo = 1e9+7;
#define mod(n) ((n) % modulo)
lld ppap[64];

void init()
{
    ppap[0] = 0;
    ppap[1] = 1;
    lld tmp1, tmp2, tmp;
    for (int i = 2; i < 64; i++)
    {
        tmp = mod(mod(1+(1LL<<(i-1))) * mod(1LL<<(i-2)));
        ppap[i] = mod(mod(ppap[i-1]*2-1)+tmp);
    }
}

int highbin(lld n)
{
    int i = 62;
    while ((1LL << i) > n) i--;
    return i;
}

lld solve(lld n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int pt = highbin(n);
    lld pows = 1LL << pt;
    lld result = mod(mod(ppap[pt] + solve(n - pows + 1) - 1) + mod(mod(pows>>1) * mod(n - pows)));
    return result;
}

int main()
{
    init();
    for (int i = 0; i < 64; i++)
        printf("%d=%lld\t", i, solve(i));
    return 0;
}

