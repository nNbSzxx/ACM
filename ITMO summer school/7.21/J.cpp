#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    long long cnt1[30], cnt2[30];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i < s1.size(); i ++) {
        cnt1[s1[i] - 'a'] ++;
    }
    for (int i = 0; i < s2.size() - 1; i ++) {
        cnt2[s2[i] - 'a'] ++;
    }
    long long ans = (long long)s1.size() * (long long)s2.size();
    for (int i = 0; i < 26; i ++) {
        ans -= cnt1[i] * cnt2[i];
    }
    cout << ans << endl;
}
