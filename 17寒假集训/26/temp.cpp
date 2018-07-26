#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	int i;
	__int64 ans = 9;
	int flag = 2;
	for (i = 0; i <= 100; i ++) {
		ans *= flag;
		if (flag == 2) {
			flag = 9;
		} else {
			flag = 2;
		}
		if (ans > 4294967295) {
			break;
		}
		printf("%I64d,",ans);
	}
	
	return 0;
}
