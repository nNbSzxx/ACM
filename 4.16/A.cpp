#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1010][190][90];
int len[190];
int lineword[1010];

int main()
{
	freopen("A.txt","r",stdin);
//	freopen("A.out","w",stdout);
	char c;
	int line = 1, word = 1, curchar = 0, isword = 0;
	memset(lineword, 0,sizeof(lineword));
	memset(len, 0,sizeof(len));
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (isword) {
				s[line][word][curchar] = '\0';
				len[word] = max(len[word], curchar);
				++ word;
				curchar = 0;
				isword = 0;
			}
			continue;
		}
		if (c == '\n') {
			s[line][word][curchar] = '\0';
			len[word] = max(len[word], curchar);
			lineword[line] = word;
			isword = 0;
			curchar = 0;
			word = 1;
			++ line;
			continue;
		}
		s[line][word][curchar ++] = c;
		isword = 1;
	}
//	if (c != '\n') {
//		s[line][word][curchar] = '\0';
//		len[word] = max(len[word], curchar);
//		lineword[line] = word;
//		isword = 0;
//		curchar = 0;
//		word = 1;
//		++ line;
//	}
//	printf("%c\n",c);
//	printf("%d\n",line);
	for (int i = 1; i < line; i ++) {
		for (int j = 1; j <= lineword[i]; j ++) {
			if (j != lineword[i])
				printf("%-*s",len[j]+1,s[i][j]);
			else
				printf("%s",s[i][j]);
		}
		printf("\n");
	}
}
