#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
 
int main(){
    float res[300] = {0},c;
    int i,num = 0;
    for (i = 1;i< 300;i++)
        res[i] = res[i-1] + 1.0/(i+1); 
    while(cin>>c&&c){
        for(i = 1;i < 300;i++){
            if(res[i] >= c){
                printf("%d card(s)\n",i);
                break;
            }
        }
    }
    return 0;
}
