#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define ull unsigned long long
using namespace std;
const int MAX = 4e4 + 10;
const ull P = 233;

char s[MAX];
int n, m;
int ans, id;
ull hsh[MAX], base[MAX];
map<unsigned long long, int> mp;


void init()
{
    base[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        base[i] = base[i - 1] * P;
    }
}

ull gethash(int l, int r)
{
    return hsh[r] - hsh[l - 1] * base[r - l + 1];
}

bool check(int mid)
{
    mp.clear();
    for (int i = 1; i + mid - 1 <= n; i ++) {
        ull h = gethash(i, i + mid - 1);
        ++ mp[h];
        if (mp[h] >= m) {
            return true;
        }
    }
    return false;
}

void bins()
{
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}

void getid(int l)
{
    mp.clear();
    for (int i = 1; i + l - 1<= n; i ++) {
        ull h = gethash(i, i + l - 1);
        mp[h] ++;
        if (mp[h] >= m) {
            id = i;
        }
    }
}

int main()
{
    init();
    while (~scanf("%d", &m), m) {
        scanf(" %s", s + 1);
        n = strlen(s + 1);
        hsh[0] = 0;
        for (int i = 1; i <= n; i ++) {
            hsh[i] = hsh[i - 1] * P + (s[i] - 'a' + 1);
        }
        ans = 0;
        id = -1;
        bins();
        if (ans == 0) {
            puts("none");
            continue;
        }
        getid(ans);
        printf("%d %d\n", ans, id - 1);
    }
    return 0;
}
