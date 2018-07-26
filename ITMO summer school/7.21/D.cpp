#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int W, H, w, h;
    cin >> W >> H >> w >> h;
    int x = (W / w + 1)/ 2;
    int y = (H / h + 1)/ 2;
    cout << x * y << endl;
    return 0;
}
