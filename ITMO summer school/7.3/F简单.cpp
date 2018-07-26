#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 510;
const int INF = 0x3f3f3f3f;
unsigned long long n, m ,x;

int main()
{
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> m >> x;
        unsigned long long t1, t2;
        unsigned long long c1, c2, conv;
        if (n > m)
			t2 = m * (n - m) * x, conv = m;
		else
			t2 = 0;
    	c1 = n / 2;
        c2 = n / 2 + 1;
		if (c1 <= m) {
			if (n * x * c1 - c1 * c1 * x >= t2)
            	t2 = n * x * c1 - c1 * c1 * x, conv = c1;
            	
		}
        if (c2 <= m)
        	if (n * x * c2 - c2 * c2 * x > t2)
            	t2 = n * x * c2 - c2 * c2 * x, conv = c2;
        
        cout << conv << " " << t2 << endl;
    }
    return 0;
}
