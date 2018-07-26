# include<cstdio>
int main()
{
    double num;
    while(scanf("%lf",&num)!=EOF)
    {
        while(num>18)
        num/=18;
        if(num>9)
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }
    return 0;
}
