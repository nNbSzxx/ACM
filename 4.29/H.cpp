#include <cstdio>
using namespace std;

const int mod = 1e9 + 7;

long long mpow(int p,int x)  
{  
    long long ans = 1,t = p;  
    while(x)  
    {  
        if (x&1) ans = ( ans * t) % mod;  
        t = (t*t) % mod;  
        x >>= 1;  
    }  
    return ans;  
} 

int main()
{
	int n,m,k;
	int t;
	int tc = 1;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d%d",&n,&m,&k);
		long long ans = 0;
		printf("Case #%d: ",tc ++);
		if (m == 1 && n == 1) {
			printf("%d\n",k * 2);
			continue;
		}
		for (int i = 1; i <= k - 1; i ++) {
			ans += mpow(i, n + m - 2) * mpow(k, (n - 1) * (m - 1)) % mod;
		}
		ans = (ans * n) % mod * m % mod;
		ans = (ans + mpow(k, n * m)) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}
