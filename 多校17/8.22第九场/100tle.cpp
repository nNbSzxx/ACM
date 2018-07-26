#include <bits/stdc++.h>
using namespace std;
char str[2510], pat[2510];
int matchhere(char*, char*);
int matchstar(int, char*, char*);
int matchhere(char* regexp, char* text){
    if(regexp[0] == '\0') return *text == '\0';
    if(regexp[1] == '*') return matchstar(regexp[0], regexp + 2, text);
    if(*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)) return matchhere(regexp + 1, text + 1);
    return 0;
}
int matchstar(int c, char *regexp, char * text){
    do{
        cout << "aaaaaaaa" << endl;
        if(matchhere(regexp, text)) return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s %s", str, pat);
        if(matchhere(pat, str))
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
