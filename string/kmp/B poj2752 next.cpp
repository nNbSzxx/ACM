#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char s[400010];
int nt[400010];
int main()
{
	
	while (~scanf("%s",s)) {

		int i = 0;
		int j = -1;
		int len = strlen(s);
		nt[0] = -1;
		while (i < len) {
			if (j == -1 || s[i] == s[j]) {
				nt [++ i] = ++ j;	
			} else {
				j = nt[j];
			}
		}
		
		j = len;
		stack<int> st;
		while (j) {
			st.push(j);
			j = nt[j];
		}
		printf("%d",st.top());
		st.pop();
		while (!st.empty()) {
			printf(" %d",st.top());
			st.pop();
		}
		printf("\n");
	}
	
	return 0;
}
