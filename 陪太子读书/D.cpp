#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<char, char> mp;
string ori = "CARScarsIuVEJxTXsUvOHhngyZKfAYmaqolMNtGQibwdjPrCpekFWzLaySBaPybRMgzYMynY";
string cha = "UnilEPFLvpVZzBNtLSCubWmaocIYneAPqxDshRkMGgJfHrFUQTjXOwdPolyProgisawesome";
char s[100010];

void init()
{
    for (int i = 0; i < ori.size(); i ++) {
        mp[ori[i]] = cha[i];
    }
    mp['D'] = 'K';
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf(" %s", s);
        for (int i = 0; i < strlen(s); i ++) {
            printf("%c", mp[s[i]]);
        }
        printf(" ");
    }
    puts("");
    return 0;
}
