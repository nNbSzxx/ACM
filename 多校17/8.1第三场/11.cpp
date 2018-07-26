#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >>t;
    int ans = 0, a;
    while (t --) {
        cin >> a;
        if (a <= 35) {
            ++ ans;
        }
    }
    cout << ans <<endl;
}
