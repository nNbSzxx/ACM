#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int sum1 = s * v1 + t1 * 2;
	int sum2 = s * v2 + t2 * 2;
	if (sum1 < sum2) {
		cout << "First" << endl;
	} else if (sum1 > sum2 ) {
		cout << "Second" << endl;
	} else {
		cout << "Friendship" << endl;
	}
	
	
	return 0;	
} 
