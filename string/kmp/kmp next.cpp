// IT'S WRONG!!!

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 10005;
int main()
{
	string s = "agctagcagctagctg";
	string s1 = "agcagcdagctagcagctagctgsdfds";
	s = "bababb";
	s1 = "bababababababababb";
	int next[MAX];
	next[0] = 0;
	for (int i = 1; i < s.size(); i ++) {
		int j = i - 1;
//		if ( i == 15 || i == 14 || i == 1) {
//			printf("%d ",j);
//		}
		while (s[i] != s[next[j]] && j >= 0) {
			j = next[j] - 1;
//			if (i == 15 || i == 14 || i == 1) {
//				printf("%d ",j);
//			}
		}  
//		if (i == 15 || i == 14 || i == 1)
//			printf("%d ",j);
		if (j != -1)
			next[i] = next[j] + 1;
		else
			next[i] = 0;
	}
	int i = 0;
	int j = 0;
	while (i < s1.size()) {
		for (; j < s.size(); j ++) {
			if (s1[i + j] != s[j] ){
				break;			
			}  
		}
		if (j == s.size()) {
			printf("%d\n",i);
			i += j - next[j - 1];
			j = next[j - 1];
		} else {
			i += j - next[j - 1];
			j = next[j - 1];
		}
	}
	
	for (int i = 0; i < s.size(); i ++) {
		printf("%d ",next[i]);
	}
	printf("\n");
}
