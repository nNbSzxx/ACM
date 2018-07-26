#include <bits/stdc++.h>
using namespace std;
string s[] = {"", "rat", "ox", "tiger", "rabbit", "dragon", "snake",
"horse", "sheep", "monkey", "rooster", "dog", "pig"};
map<string, int> mp;

int main()
{
    string s1, s2;
    int t;
    mp.clear();
    for (int i = 1 ;i <= 12; i ++) {
        mp[s[i]] = i;
    }
    scanf("%d", &t);
    while (t --) {
        cin >> s1 >> s2;
        int a1 = mp[s1], a2 = mp[s2];
        int ans = (a2 - a1 + 12) % 12;
        if (ans == 0) {
            ans = 12;
        }
        cout << ans << endl;
    }

}
