// WA

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <pair>
using namespace std;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 7;
int e[MAX];
int a, b, h, w ,n;
map<int, int> mp;
vector<pair<int, int> > faim1, faim2;

void getFactor(int aim, vector<pair<int, int> >& faim)
{
    faim.clear();
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            int times = 0;
            while (n % i == 0) {
                n /= i;
                ++ times;
            }
            faim.push_back(make_pair(i, times));
        }
        ++ i;
    }
    if (n > 1) {
        faim.push_back(make_pair(n, 1));
    }
    return ;
}

int getAns(int aim1, int aim2)
{
    int cnt = 0;
    getFactor(aim1, faim1);
    getFactor(aim2, faim2);
    while (aim1 > 1) {
        for (vector<pair<int, int> >::iterator it = faim1.begin(); it != faim1.end(); it ++) {
            if (mp.count(it -> first))
                while (mp[it -> first] && it -> second) {
                    aim1 /= it -
                }
        }
    }
    for (int i = 0; i < n; i ++) {
        if (aim1 <= 1 && aim2 <= 1) return cnt;
        cnt ++;
        if (aim1 <= 1) {
            aim2 = aim2 / e[i] + (aim2 % e[i] > 0);
            continue;
        }
        if (aim2 <= 1) {
            aim1 = aim1 / e[i] + (aim1 % e[i] > 0);
            continue;
        }
        if (aim2 % e[i] < aim1 % e[i]) {
            aim2 = aim2 / e[i] + (aim2 % e[i] > 0);
        } else {
            aim1 = aim1 / e[i] + (aim1 % e[i] > 0);
        }
    }
    if (aim1 > 1 || aim2 > 1) return INF;
    return cnt;
}

int main()
{

    cin >> a >> b >> h >> w >> n;
    for (int i = 0; i < n; i ++) {
        cin >> e[i];
    }
    if (a <= h && b <= w || a <= w && b <= h) {
        cout << 0 << endl;
        return 0;
    }
    int aim1 = a / h + (a % h > 0);
    int aim2 = b / w + (b % w > 0);
    int i = 0;
    while (i < n && aim1 > 1) {
        aim1 = aim1 / e[i] + (aim1 % e[i] > 0);
        mp[e[i]] ++;
        i ++;
    }
    while (i < n && aim2 > 1) {
        aim2 = aim2 / e[i] + (aim2 % e[i] > 0);
        mp[e[i]] ++;
        i ++;
    }
    int cnt1 = getAns(a / h + (a % h > 0), b / w + (b % w > 0));
    int cnt2 = getAns(a / w + (a % w > 0), b / h + (b % h > 0));
    if (cnt1 == INF && cnt2 == INF) {
        cout << -1 << endl;
    } else {
        cout << min(cnt1, cnt2) << endl;
    }

    return 0;
}

