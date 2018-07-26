#include <iostream>
#include <string>
using namespace std;

int  n, days;

void init(){
    int        day, year, month;
    string    mon;

    cin >> day;
    getchar();
    getchar();
    cin >> mon;
    cin >> year;
    if (mon == "pop")month = 1;
    if (mon == "no")month = 2;
    if (mon == "zip")month = 3;
    if (mon == "zotz")month = 4;
    if (mon == "tzec")month = 5;
    if (mon == "xul")month = 6;
    if (mon == "yoxkin")month = 7;
    if (mon == "mol")month = 8;
    if (mon == "chen")month = 9;
    if (mon == "yax")month = 10;
    if (mon == "zac")month = 11;
    if (mon == "ceh")month = 12;
    if (mon == "mac")month = 13;
    if (mon == "kankin")month = 14;
    if (mon == "muan")month = 15;
    if (mon == "pax")month = 16;
    if (mon == "koyab")month = 17;
    if (mon == "cumhu")month = 18;
    if (mon == "uayet")month = 19;
    days = day + (month - 1) * 20 + year * 365;
}

void work(){
    int        year, month, day;

    year = days / 260;
    month = days % 260 % 20 + 1;
    day = days % 260 % 13 + 1;
    cout << day << " ";
    switch(month){
        case 1: cout << "imix";break;
        case 2: cout << "ik";break;
        case 3: cout << "akbal";break;
        case 4: cout << "kan";break;
        case 5: cout << "chicchan";break;
        case 6: cout << "cimi";break;
        case 7: cout << "manik";break;
        case 8: cout << "lamat";break;
        case 9: cout << "muluk";break;
        case 10: cout << "ok";break;
        case 11: cout << "chuen";break;
        case 12: cout << "eb";break;
        case 13: cout << "ben";break;
        case 14: cout << "ix";break;
        case 15: cout << "mem";break;
        case 16: cout << "cib";break;
        case 17: cout << "caban";break;
        case 18: cout << "eznab";break;
        case 19: cout << "canac";break;
        case 20: cout << "ahau";break;
    }
    cout << " " << year << endl;
}

int main(){
    //freopen("t.txt", "r", stdin);
    cin >> n;
    cout << n << endl;
    while (n--){
        init();
        work();
    }
    return 0;
}
