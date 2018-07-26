#include <bits/stdc++.h>
using namespace std;

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
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int g = gcd(n - 1, m - 1);
        //cout << g <<endl;
        long long a = n - 1, b = m - 1;
        if (a > b) swap(a, b);
        long long sum = a / g * b + 1;
        long long ans = sum - (sum / g) - (sum % g > 0) + (sum - 1) / a + (sum - 1) / b;
        /*
        long long times = (sum - 1) / a;
        //cout << 11111 << endl;
        times -= (b / a) + (b % a > 0);
        long long cir = (b - 1) / a + ((b - 1) % a > 0);
        if (!cir) {
            printf("%lld\n", sum);
            continue;
        }
        //cout << cir << endl;
        long long r = times / cir;
        //cout << 11111 << endl;
        long long dif = (1 + r) * r * cir;
        dif += (r + 1) * 2 * (times % cir);
        sum -= dif;
        cout << sum << " " << times << " " << cir << " " << dif <<endl;
        */
        printf("%lld\n", ans);
    }
}
