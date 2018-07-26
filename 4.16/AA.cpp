#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<sstream>  
#include<vector>  
using namespace std;  
vector<string> s[1010];  
int len[190];  

int main()  
{  
//	freopen("A.txt","r",stdin);
    string l;  
    int line = 0;  
    memset(len,0,sizeof(len));  
    while(getline(cin,l))  
    {  
        string t;  
        int lenl, cnt=0;  
        stringstream ss(l);  
        while(ss >> t)  
        {  
            lenl = t.size();  
            len[cnt] = max(len[cnt], lenl);  
            s[line].push_back(t);  
            ++ cnt;  
        }  
        ++ line;  
    }  
    for(int i = 0; i < line; i ++)  
    {  
        for(int j = 0; j < s[i].size();j++)  
        {  
            cout << s[i][j];  
            int lenl = s[i][j].size();  
            if(j != (s[i].size() - 1))  
            {  
                for(int k = lenl; k < len[j]; k ++)  
                	cout << " ";  
                cout << " ";  
            }  
        }  
        cout << endl;  
    }  
    return 0;  
}  
