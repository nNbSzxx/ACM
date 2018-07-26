#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i, j, k)  for ( int i = (j); i <= (k); ++i)
#define REPD(i, j, k) for ( int i = (j); i >= (k); --i)
#define IOS ios::sync_with_stdio(false);cin.tie(0);

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;

int a[maxn], b[maxn];
int n, m;
int sum[maxn], va[maxn], vb[maxn];
long long val[maxn];

long long ans ;

void init() {
    REP(i, 0, n - 1)
        scanf("%d", &a[i]);
    REP(i, 0, m - 1)
        scanf("%d", &b[i]);
    memset(sum, 0, sizeof sum);
    memset(val, 0, sizeof val);
    memset(va, 0, sizeof va);
    memset(vb, 0, sizeof vb);


    REP(i, 0, m - 1)
        if ( vb[i] == 0) {
            int lb = i, t = 1;
            vb[lb] = 1;
            while ( vb[b[lb]] == 0 ) {
                ++t;
                lb = b[lb];
                vb[lb] = 1;
            }
            ++sum[t];
        }
    for (int i = 1; i <= 3; i ++) {
    	cout << sum[i] << " ";
	}
	cout << endl;
    REP(i, 1, maxn - 1)
        for (int j = 1; i * j < maxn; ++j)
            val[i * j] += 1LL * i * sum[i] % mod ;
    
    memset(sum, 0, sizeof sum);
    REP(i, 0, n - 1)
        if ( va[i] == 0) {
            int la = i, t = 1;
            va[la] = 1;
            while ( va[a[la]] == 0 ) {
                ++t;
                la = a[la];
                va[la] = 1;
            }
            ++sum[t];
        }
    for (int i = 1; i <= 3; i ++) {
    	cout << sum[i] << " ";
	}
	cout << endl;
    ans = 1;
    REP(i, 1, maxn - 1)
        while (sum[i]--)
            ans = ans * val[i] % mod;
    cout << ans << endl;
}

void solve() {

}

int main() {
    int t = 0;
    while(scanf("%d%d", &n, &m)!=EOF) {
        cout << "Case #" << ++t << ": " ;
        init();
        solve();
    }
    return 0;
}
