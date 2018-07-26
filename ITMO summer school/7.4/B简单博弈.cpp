#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, a, sum = 0;
    string s;
    map<char, int> mp;
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        mp[s[i]] ++;
    }
    int cnt = 0;
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it ++) {
        if (it -> second % 2 == 1) {
            ++ sum;
        }
        ++ cnt;
    }
    if ((sum & 1) || cnt == 1 || sum == 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}

