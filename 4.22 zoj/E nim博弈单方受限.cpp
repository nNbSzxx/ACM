#include <cstdio>
using namespace std;
const int cost[16] = {6,2,5,5,4, 5,6,3,7,6, 6,5,4,5,5, 4};
const long long sumcost = 78;
cosnt long long pow[10] = {1,16,256,409,65536,1048576,16777216,268435456LL,4294967296LL,};
const long long END = 0xFFFFFFFFLL;

struct C {
	int cost;
	
};
int main()
{

	int n,t;
	long long start, end, sumnow;
	unsigned long long ans;
	scanf("%d",&t);
	
	while (t --) {
		scanf("%d",&n);
		scanf("%X",&start);
		
		sumnow = 0;
		int cnt = 0;
		long long sstart = start;
		while (sstart > 0) {
			sumnow += cost[sstart % 16];
			sstart /= 16;
			cnt ++;
		}
		for (int i = cnt + 1; i <= 8; i ++) {
			sumnow += cost[0];
		}
		
		end = start + n - 1;
		int flag = 0;
		ans = sumnow;
		
		if (end >= pow[8]) {
			end -= pow[8];
			flag = 1;
		}
		long long aim = ((flag)? END : end);
		long long step = 1;
		int base = 1;
		long long lowbit,highbit;
		int islimit;

		
		while (start < aim) {
//			if ((aim - start) < 15 * step) {
//				islimit = 1;
//			} else {
//				islimit = 0;
//			}
			
			int bound = (n % (16 * step) / step);
			lowbit = start % (16 * step) / step;
			highbit = start % (16 * 16 * step) / (16 * step);
			start += bound * step;
			sumnow -= cost[highbit];
			sumnow -= cost[lowbit];
			printf("%d %lld %lld %lld %llu\n", islimit, lowbit, step, sumnow, ans);
			
			
			while (bound --) {
				++ lowbit;
				if (lowbit > 15) {
					sumnow 
				}
				ans += (sumnow + cost[++ lowbit]) + (sumcost * (base - 1));
			}
			step *= 16;
			++ base;
		}
		
		if (flag) {
			start = 0;
			aim = end;
			while (start < aim) {
//				if ((aim - start) < 15 * step) {
//					islimit = 1;
	//			} else {
	//				islimit = 0;
	//			}
				
				int bound = (n % (16 * step) / step);
				lowbit = start % (16 * step) / step;
				start += bound * step;
				
				sumnow -= cost[lowbit];
				printf("%d %lld %lld %lld %llu\n", islimit, lowbit, step, sumnow, ans);
				
				
				while (bound --) {
					ans += (sumnow + cost[++ lowbit]) + (sumcost * (base - 1));
				}
				step *= 16;
				++ base;
			}
		}
		printf("%llu\n",ans);
	}
	
}
