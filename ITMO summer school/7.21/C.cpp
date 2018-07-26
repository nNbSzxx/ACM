#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int loc = s.size();
    for (int i = 0;  i < s.size(); i ++) {
        if (s[i] == '-' || s[i] == '+') {
            loc = i;
            break;
        }
        cout << s[i];
    }
    int flag, isfir, hasm;
    for (int i = loc; i < s.size(); i ++) {
        if (s[i] == '+') {
            flag = 0;
            isfir = 0;
            hasm = 0;
        } else if (s[i] == '-') {
            flag = 1;
            isfir = 0;
            hasm = 0;
        } else {
            if (flag) {
                if (!isfir) {
                    isfir = 1;
                } else {
                    if (!hasm) {
                        cout << '+';
                        if (s[i] != '0') {
                            hasm = 1;
                        }
                    }
                }
            }
        }
        cout << s[i];
    }
    cout << endl;
    return 0;
}
