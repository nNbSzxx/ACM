#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct nn{
    string s;
    int sum;
}per[55];
bool cmp (const nn& n1, const nn& n2)
{
    return n1.sum > n2.sum;
}
int main()
{
    int n;
    int p,m,a,b,c,d,e, sum[55];
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> per[i].s >> p >> m >> a >> b >> c >> d >> e;
        per[i].sum = 100 * p - 50 * m + a + b + c +d +e;
    }
    sort(per + 1, per + 1 + n, cmp);
    cout << per[1].s << endl;
    return 0;
}

