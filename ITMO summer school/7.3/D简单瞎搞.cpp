#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e5 + 10;

int main()
{
    //printf("%d %d %d %d\n", 'C' - 'U', 'A' - 'n', 'R' - 'i', 'S' - 'l');
    int n;
    map<char, char> mp;
    set<char> st;
    char s1[MAX] = "IuVEJxTXs UvOHhng yZKfAYmaqolM", o1[MAX] = "vpVZzBNtL SCubWma ocIYneAPqxDs";
    for (int i = 0; i < strlen(s1); i ++) {
        mp[s1[i]] = o1[i];
        st.insert(o1[i]);
        //printf("%d %d\n", s[i], o[i]);
    }
    char s2[MAX] = "NtGQibw djPrCpek FWzL", o2[MAX] = "hRkMGgJ fHrFUQTj XOwd";
    for (int i = 0; i < strlen(s2); i ++) {
        mp[s2[i]] = o2[i];
        st.insert(o2[i]);
        //printf("%d %d\n", s[i], o[i]);
    }
    char s3[MAX] = "aySBaPyb RM gzYMynY", o3[MAX] = "PolyProg is awesome";
    for (int i = 0; i < strlen(s3); i ++) {
        mp[s3[i]] = o3[i];
        st.insert(o3[i]);
        //printf("%d %d\n", s[i], o[i]);
    }
    char s4[MAX] = "CARScars", o4[MAX] = "UnilEPFL";
    for (int i = 0; i < strlen(s4); i ++) {
        mp[s4[i]] = o4[i];
        st.insert(o4[i]);
        //printf("%d %d\n", s[i], o[i]);
    }
//    for (map<char, char>::iterator it = mp.begin(); it != mp.end(); it ++) {
//        printf("%c %c\n", it -> first, it -> second);
//    }
//    for (set<char>::iterator it = st.begin(); it != st.end(); it ++) {
//        printf("%c\n", *it);
//    }
    mp['D'] = 'K';
    char s[MAX], o[MAX];
    int flag = 0;
    int j = 0;
    scanf("%d", &n);
    gets(s);
    gets(s);
    for (int i = 0; i < strlen(s); i ++) {
        if (!flag && s[i] == ' ') continue;
        else flag = 1;
        o[j ++] = mp[s[i]];
    }
    -- j;
    while (j >= 0 && o[j] == ' ') {
        -- j;
    }
    o[++ j] = '\0';
    printf("%s\n", o);
    return 0;
}
