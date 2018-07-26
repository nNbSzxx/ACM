#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MAX = 100000;

bool isTrue(int n)
{
	char s[15];
	itoa(n * 13, s, 10);
	if (strstr(s,"13")) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	struct F{
		int sum;
		int begin;
		int end;
	} f[MAX];
	memset(f,0,sizeof(f));
	f[0].sum = 0;
	f[0].begin = 0;
	f[0].end = 12;
	f[1].sum = 1;
	f[1].begin = 13;
	f[1].end = 13;
	int cur = 2;
	for (int i = 2; i <= 76923080; i ++) {
		if(isTrue(i)) {
			f[cur].sum = f[cur - 1].sum + 1;
			f[cur].begin = i * 13;
			f[cur].end = i * 13;
			cur ++;
		} else {
			f[cur - 1].end += 13;
		}
	}
	
	int n;
	while (~scanf("%d",&n)) {
		int begin, end;
		begin = 0;
		end = cur - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (n >= f[mid].begin && n <= f[mid].end) {
				printf("%d\n",f[mid].sum);
				break;
			} 
			if (n > f[mid].end) {
				begin = mid + 1;
				continue;
			}
			if (n < f[mid].begin) {
				end = mid - 1;
			}
		}
	}
	return 0;
}
