#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    int n;
    long long a[220];
    set<long long> s;
    cin >> n;
    int ans;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    ans = s.size();
    for (int i = 1; i <= n; i ++) {
        long long t = a[i];
        for (int j = 1; j <= n; j ++) {
            if (t == a[j])
                t *= 2;
        }
        set<long long>::iterator e = s.end();
        for (set<long long>::iterator it = s.begin(); it != s.end(); it ++) {
            if (*it == t) {
                ans --;
                e = it;
                break;
            }
        }
        if (e != s.end()) {
            s.erase(e);
        }
    }
    cout << ans << endl;
    return 0;
}
