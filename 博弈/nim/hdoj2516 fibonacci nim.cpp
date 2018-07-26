// Fibonacci Nim
// http://blog.csdn.net/acm_cxlove/article/details/7835016
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int n;
	long long a = 2, b = 3, c;
	set <long long> s;
	s.insert(a);
	s.insert(b);
	for (; b <= ((long long)1 << 31);) {
		c = a + b;
		s.insert(c);
		a = b;
		b = c;
	}
	while (~scanf("%d",&n), n) {
		if (s.count(n)) {
			printf("Second win\n");
		} else {
			printf("First win\n");
		}
	}
	return 0;
}
