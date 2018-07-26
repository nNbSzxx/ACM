#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 5e4 + 10;
int n;
pair<pair<int, int>, int> iv[MAX];
int l[MAX], r[MAX], p[MAX];
stack<pair<pair<int, int>, int> > s;

//bool cmp(const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2)
//{
//    return p1.second < p2.second;
//}

void build()
{
    while (!s.empty()) {
        s.pop();
    }
    s.push(iv[1]);
    int id = iv[1].second;
    l[id] = r[id] = p[id] = 0;
    for (int i = 2; i <= n; i ++) {
        pair<pair<int, int>, int> now;
        pair<pair<int, int>, int> last = make_pair(make_pair(0, 0), 0);
        while (!s.empty()) {
            now = s.top();
            if (now.first.second < iv[i].first.second) {
                break;
            }
            last = s.top();
            s.pop();
        }
        if (s.empty()) {
            int curid = iv[i].second;
            int lastid = last.second;
            p[curid] = r[curid] = 0;
            l[curid] = lastid;
            p[lastid] = curid;
        } else {
            int curid = iv[i].second;
            int lastid = last.second;
            int nowid = now.second;
            p[curid] = nowid;
            r[nowid] = curid;
            
            l[curid] = lastid;
            r[curid] = 0;
            p[lastid] = curid;
        }
        s.push(iv[i]);
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d", &iv[i].first.first, &iv[i].first.second);
            iv[i].second = i;
        }
        sort(iv + 1, iv + 1 + n);
        build();
        puts("YES");
        for (int i = 1; i <= n; i ++) {
            printf("%d %d %d\n", p[i], l[i], r[i]);
        }
    }
    return 0;
}
