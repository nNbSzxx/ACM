#include<bits/stdc++.h> 
using namespace std;
char s[25000];
int main(){
   int i;
   double a,b;
   char c;
   while(gets(s),strcmp(s,"0")!=0){
       stack<char>s1;
       stack<double>s2;
       for(int i=0;i<strlen(s);i++){
           if(s[i]>='0'&&s[i]<='9'){
               a=0;
               while(s[i]>='0'&&s[i]<='9'){
                   a=a*10+s[i]-'0';
                   i++;
               }
               i--;
               s2.push(a);
           }
           else if(s[i]=='-'||s[i]=='+'){
               if(!s1.empty()){
                   c=s1.top();
                   s1.pop();
                   a=s2.top();
                   s2.pop();
                   b=s2.top();
                   s2.pop();
                   if(c=='+')
                       a+=b;
                   else
                       a=b-a;
                   s2.push(a);
                   s1.push(s[i]);
               }
               else s1.push(s[i]);
           }
           else if(s[i]=='/'){
               b=0;
               i+=2;
               while(s[i]>='0'&&s[i]<='9')
               {
                   b=b*10+s[i]-'0';
                   i++;
               }
               i--;
               a=s2.top();
               s2.pop();
               a=a/b;
               s2.push(a);
           }
           else if(s[i]=='*')
           {
               b=0;
               i+=2;
               while(s[i]>='0'&&s[i]<='9')
               {
                   b=b*10+s[i]-'0';
                   i++;
               }
               i--;
               a=s2.top();
               s2.pop();
               a=a*b;
               s2.push(a);
           }
       }
       while(!s1.empty())
       {
           c=s1.top();
           s1.pop();
           a=s2.top();
           s2.pop();
           b=s2.top();
           s2.pop();
           if(c=='+')
               a+=b;
           else
               a=b-a;
           s2.push(a);
       }
       printf("%.2f\n",s2.top());
   }
   return 0;
}
