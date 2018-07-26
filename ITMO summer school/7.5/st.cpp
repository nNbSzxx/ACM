#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
    const int MAX = 100010;
    int st[MAX][20];
    int a[MAX];
    int t,n,m;
    map<int, long long> mp;
int gcd(int a, int b)
{
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void build()
{
    for (int i = 1; i <= n; i ++) {
        st[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j ++) {
        for (int i = 1; i + (1<<j) - 1 <= n; i ++) {
            st[i][j] = gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l, int r)
{
    int k = 0;
    while ((1 << (k + 1)) <= (r - l + 1)) k ++;
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
void bin()
{
    for (int i = 1; i <= n; i ++) {
        int g = a[i];
        int j = i;
        while (j <= n) {
            int l = j;
            int r = n;
            int mid;
            while (l < r) {
                mid = (l+r+1)>>1;
                if (g == query(i,mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            mp[g] += (l - j + 1) ;
//          printf("%d %d %d %d %lld\n",i,l,j,g,mp[g]);
            j = l + 1;
            g = query(i,j);
        }
    }
}
int main()
{
    scanf("%d",&t);
    int tc = 0;
    while (t --) {
        mp.clear();
        memset(st,0,sizeof(st));
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
        }
        build();
        bin();
//      for (auto it = mp.begin(); it != mp.end(); it ++) {
//          printf("%d %lld\n",it->first,it->second);
//      }
        scanf("%d",&m);
        printf("Case #%d:\n",++ tc);
        for (int i = 1; i <= m; i ++) {
            int l,r;
            scanf("%d%d",&l,&r);
            int g = query(l,r);
            printf("%d %I64d\n",g,mp[g]);
        }
    }
    return 0;
}
