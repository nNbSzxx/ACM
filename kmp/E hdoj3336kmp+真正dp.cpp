#include <stdio.h>  
#define maxn 200000 + 5  
char str[maxn];  
int next[maxn], len, dp[maxn];  
  
void getNext(){  
    int i = 0, j = -1;  
    next[0] = -1;  
    while(i < len){  
        if(j == -1 || str[i] == str[j]){  
            ++i; ++j;  
            next[i] = j;              
        }else j = next[j];  
    }  
}  
  
int main(){  
    int t, sum;  
    scanf("%d", &t);  
    while(t--){  
        scanf("%d%s", &len, str);  
        getNext();  
        sum = 0;  
        for(int i = 1; i <= len; ++i){  
            dp[i] = dp[next[i]] + 1;  
            sum += dp[i] % 10007;  
        }  
        printf("%d\n", sum % 10007);  
    }  
    return 0;  
}
