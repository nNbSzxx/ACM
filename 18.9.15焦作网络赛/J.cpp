#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 100;

bool isSqu(int k)
{
    int s = sqrt(k);
    if (s * s == k) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int sum = 0;
    for (int i = 1; i <= MAX; i ++) {
        bool fir = isSqu(i), sec = isSqu(sum);
        printf("%d ", i);
        if (fir && sec) {
            puts("Arena of Valor");
        } else if (fir && !sec) {
            puts("Hearth Stone");
        } else if (!fir && sec) {
            puts("Clash Royale");
        } else {
            puts("League of Legends");
        }
        sum += i;
    }
    return 0;
}
