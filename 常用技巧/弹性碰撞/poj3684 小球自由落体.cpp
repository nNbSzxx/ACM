#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const double g = 10.0;
double ans[110];
int h;

double cal(int time)
{
	if (time <= 0) 
		return h;
	double cycle = sqrt(2.0 * h / g);
	//printf("cycle: %.6f\n", cycle);
	int k = (floor)(time / cycle);
	if (k & 1) {
		double left = cycle - (time - k * cycle);
		return 1.0 * h - g * left * left / 2.0;
	} else {
		double left = time - k * cycle;
		return 1.0 * h - g * left * left / 2.0;
	}
}

int main()
{
	int c;
	scanf("%d", &c);
	while (c --) {		
		int n, r, t;
		scanf("%d%d%d%d", &n, &h, &r, &t);
		for (int i = 0; i < n; i ++) {
			ans[i] = cal(t - i);
		}
		sort(ans, ans + n);
		for (int i = 0; i < n - 1; i ++) {
			printf("%.2f ", 2.0 * i * r / 100.0 + ans[i]);
		}
		printf("%.2f\n", 2.0 * (n - 1) * r / 100.0 + ans[n - 1]);
	}
	
	return 0;
}
