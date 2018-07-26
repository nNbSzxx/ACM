#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    char s[11];

    while (~scanf("%d", &n)) {
        int d;
        int sumc = 0;
        double sumcs = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d %s", &d, s);
            //printf("%d %s\n", d, s);
            if (!strcmp(s, "P") || !strcmp(s, "N")) {
                    //cout << "pn" <<endl;
                continue;
            } else {
                //cout << 111111 << endl;
                sumc += d;
                //cout << sumc << " cccc" << endl;
                //printf("%d\n", sumc);
                if (!strcmp(s, "A")) {
                    sumcs += 4.0 * d;
                    //cout << sumcs <<endl;
                    //cout << "a" << endl;
                } else if (!strcmp(s, "A-")) {
                    sumcs += d * 3.7;
                    //cout << "b" << endl;
                } else if (!strcmp(s, "B+")) {
                    sumcs += d * 3.3;
                } else if (!strcmp(s, "B")) {
                    sumcs += d * 3.0;
                } else if (!strcmp(s, "B-")) {
                    sumcs += d * 2.7;
                } else if (!strcmp(s, "C+")) {
                    sumcs += d * 2.3;
                } else if (!strcmp(s, "C")) {
                    sumcs += d * 2.0;
                } else if (!strcmp(s, "C-")) {
                    sumcs += d * 1.7;
                } else if (!strcmp(s, "D")) {
                    sumcs += d * 1.3;
                } else if (!strcmp(s, "D-")) {
                    sumcs += d * 1.0;
                } else {
                    sumcs += 0;
                    //cout << "else!!!" << endl;
                }
                //printf("sumcs : %.2f\n", sumcs);
                //cout << sumcs <<endl;
            }

        }
        //printf("%d\n", sumc);
        if (sumc == 0) {
            printf("%.2f\n", 0);
            //cout << "222222222222" << endl;
        } else {
            printf("%.2f\n", 1.0 * sumcs / sumc);
            //cout << 333333333333333 << endl;
        }
    }
}
