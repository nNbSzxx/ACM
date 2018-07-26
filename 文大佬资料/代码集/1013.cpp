
#include<bits/stdc++.h> 
int main()
{
    int n,k,i,t,len,max;
    char s1[13],s2[13],temp[10];
    int flag[12];
    scanf("%d",&n);
    while(n--)
    {
        memset(flag,0,sizeof(flag));
        for(t=1;t<=3;++t)
        {
            scanf("%s%s%s",s1,s2,temp);
            len=strlen(s1);                
            if(strcmp(temp,"even")==0)
            {
                for(i=0;i<len;++i)
                {
                    flag[s1[i]-'A']=10;  
                    flag[s2[i]-'A']=10;

                }
            }
            else if(strcmp(temp,"up")==0)
            {
                for(i=0;i<len;++i)
                {
                    if(flag[s1[i]-'A']!=10)
                        ++flag[s1[i]-'A'];  
                    if(flag[s2[i]-'A']!=10)
                        --flag[s2[i]-'A'];  

                }
            }
            else
            {
                for(i=0;i<len;++i)      
                {
                    if(flag[s1[i]-'A']!=10)
                        --flag[s1[i]-'A'];  
                    if(flag[s2[i]-'A']!=10)
                        ++flag[s2[i]-'A'];  
                }
            }
        }
        max=0;
        k=0;
        for(i=0;i<12;++i)
        {
            if(flag[i]==10)
                continue;
            if(max<=abs(flag[i]))
            {
                max=abs(flag[i]);
                k=i;
            }
        }
        if(flag[k]>0)
            printf("%c is the counterfeit coin and it is heavy.\n",'A'+k);
        else
            printf("%c is the counterfeit coin and it is light.\n",'A'+k);
    }
    return 0;
}
