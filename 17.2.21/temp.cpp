#include <iostream>
using namespace std;
const int m = 7;

int ans[m + 2] = {0};
int p[m + 2];
int isput[m + 2] = {0};

void rel(int x)
{
	isput[x] = 0;
}

void cal(void)
{
	for (int i = 1; i <= m; i ++) {
		if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
			ans[i] ++;
		}
	}
}

bool put(int x,int i)
{
	if (!isput[x]) {
		isput[x] = 1;
		p[i] = x;
		return true;
	}
	return false;
}

int main()
{
	
	int i,j,k,l,p,q;
	for (i = 1; i <= m; i++) {
		put(i,1);
		for (j = 1; j <= m; j ++) {
			if (!put(j,2)) continue;
			for (k = 1;  k <= m; k ++) {
				if (!put(k,3)) continue;
				for (l = 1; l <= m; l ++) {
					if (!put(l,4)) continue;
					for (p = 1; p <= m; p ++) {
						if (!put(p,5)) continue;
						for (q = 1; q <= m; q ++) {
							if (!put(q,6)) continue;
							for (int o = 1; o <= m; o ++) {
								if (!put(o,7)) continue;
								cal();
								rel(o);
							}
							
							rel(q);
						}
						rel(p);
					}
					rel(l);
				}
				rel(k);
			}
			rel(j);
		}
		rel(i);
	}
	for (i = 1; i <= m; i ++) {
		printf ("%d ",ans[i]);
	}
}
