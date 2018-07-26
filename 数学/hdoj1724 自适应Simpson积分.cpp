#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;

double f(double x)
{
	return (1.0 * b * sqrt((1.0 - x / a) * (1.0 + x / a)));
}

double simpson(double a, double b)
{
//	cout << "ccccccc" << endl;
	double c = (a + b) / 2;
	return (f(a) + f(b) + 4 * f(c)) * (b - a) / 6.0;
}

double asr(double a, double b, double eps, double s)
{
//	cout << "bbbbbbb" << endl;
	double c = (a + b) / 2;
	double l = simpson(a, c), r = simpson(c, b);
	if (abs(l + r - s) <= 15 * eps) {
		return l + r + (l + r - s) / 15.0;
	}
	return asr(a, c, eps / 2, l) + asr(c, b, eps / 2, r);
}

double inasr(double a, double b, double eps)
{
//	cout << "aaaaa" << endl; 
	return asr(a, b, eps, simpson(a, b));
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d%d", &a, &b, &l, &r);
		double ans = inasr(l, r, 1e-6);
		printf("%.3f\n", 2.0 * ans);
	}
	return 0;
}
