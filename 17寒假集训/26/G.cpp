#include <cstdio>
#include <iostream>
using namespace std;  
const int MAX = 1010;  

int main() {  
	int a, b, ans[MAX]; 
    scanf("%d%d",&a,&b);
    int cnt = 0;
    while (a < b) {  
    	
        ans[cnt ++] = b;  
        if (b % 10 == 1) {  
            b /= 10;  
        } else if (b % 2 == 0) {  
            b /= 2;  
        } else {  
            puts("NO");  
            return 0;
        }  
    }  
    if (a != b) { 
        puts("NO"); 
        return 0;
    }  
    puts("YES"); 
    ans[cnt ++] = a;  
    printf("%d\n",cnt); 
	printf("%d ",ans[cnt - 1]); 
    for (int i = cnt - 2; i >= 0; --i)  
        printf("%d ",ans[i]);
    printf("\n");
    return 0;  
}  
