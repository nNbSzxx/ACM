#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 1010;
int main()
{
    int k;
    cin >> k;
    char s[MAX];
    for (int i = 0; i < 1000; i ++) {
        s[i] = 'a';
    }
    s[1000] = '\0';
    for (int i = 0; i < k; i ++) {
        printf("%s\n", s);
        s[i] += 1;
        s[i + 1] -= 31;
    }
    return 0;
}
