#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
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
	map<int,int> m;
	int n,t, ans[5100],num[5100], cnt = 0, cntans = 0;
	scanf("%d",&n);
	m.clear();
	memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans)); 
	for (int i = 0; i < n * n; i ++) {
		scanf("%d",&t);
		if (!m.count(t))
			num[cnt ++] = t;
		m[t] ++;
	}
	sort(num,num+cnt);
	for (int i = cnt - 1; i >= 0 && cntans < n; i --) {
		while (m[num[i]] > 0) {		
			ans[cntans ++] = num[i];
			m[num[i]] --;
			for (int j = 0; j < cntans; j ++) {
				m[gcd(num[i], ans[j])] -= 2;
			}	
		}
		
	}
	printf("%d",ans[0]);
	for (int i = 1; i < cntans; i ++) {
		printf(" %d",ans[i]);
	}
	printf("\n");
	return 0;
}
