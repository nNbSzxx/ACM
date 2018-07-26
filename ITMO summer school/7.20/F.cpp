#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 60;
int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

int main()
{
    long long t, n;
    cin >> t >> n;
    long long a[MAX];
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<long long> x, y, head;
    x.push_back(0);
    y.push_back(0);
    head.push_back(0);
    long long xx, yy, h;
    long long cir = 0, disx = -1 , disy = -1;
    for (int i = 1; i <= t; i ++) {
        for (int j = 1; j <= n; j ++) {
            xx = x[x.size() - 1];
            yy = y[y.size() - 1];
            h = head[head.size() - 1];
            xx += dir[h][0] * a[j];
            yy += dir[h][1] * a[j];
            h = (h + a[j]) % 4;
            x.push_back(xx);
            y.push_back(yy);
            head.push_back(h);
        }
        if (head[head.size() - 1] == 0) {
            cir = i;
            disx = x[x.size() - 1];
            disy = y[y.size() - 1];
            break;
        }
    }
    //cout << cir << endl;
    //cout << disx << " " << disy << endl;
    if (cir != 0) {
        //long long more = t % cir;
        long long tt = t;
        t /= cir;
        long long ansx = t * disx ;
        //cout << ansx << endl;
        long long ansy = t * disy ;
        //cout << ansy << endl;
        h = 0;
        for (int i = cir * t + 1; i <= tt; i ++) {
            for (int j = 1; j <= n; j ++) {
                ansx += dir[h][0] * a[j];
                ansy += dir[h][1] * a[j];
                h = (h + a[j]) % 4;
            }
        }
        long long ans = abs(ansx) + abs(ansy);
        cout << ans << endl;
        return 0;
    }

    cout << abs(x[x.size() - 1]) + abs(y[y.size() - 1]) << endl;
    return 0;
}
