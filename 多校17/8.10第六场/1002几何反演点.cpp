#include<bits/stdc++.h>  
using namespace std;  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    int x1,y1,y2,x2,r;  
    double xx1,yy1,xx2,yy2,dis,ans;  
    double a,b,c;  
    while(t--)  
    {  
        scanf("%d%d%d%d%d",&r,&x1,&y1,&x2,&y2);  
        a=sqrt(x1*x1+y1*y1);  
        if(x1==x2&&y1==y2)  
        {  
            printf("%.7f\n",2.0*(r-a));  
            continue;  
        }  
        c=(1.0*a)/(1.0*r);  
        a=1.0*r*r/(a*a);  
        xx1=x1*a;  
        yy1=y1*a;  
        xx2=x2*a;  
        yy2=y2*a;  
        dis=fabs((yy2-yy1)*(-xx1)-(xx2-xx1)*(-yy1))/( sqrt((xx1-xx2)*(xx1-xx2)+(yy2-yy1)*(yy2-yy1)));  
        ans= sqrt((xx1-xx2)*(xx1-xx2)+(yy2-yy1)*(yy2-yy1));  
        if(dis>r) {  
            dis-=r;  
            ans=2*sqrt((ans/2.0)*(ans/2.0) + dis*dis);  
        }  
        printf("%.7f\n",ans*c);   
    }  
      
    return 0;  
}
