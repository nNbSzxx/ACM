void get_facnum()  
{  
    int pnum = 0;  
    facnum[1] = 1;  
    for(int i = 2; i < MAX; i++)  
    {  
        if(!noprime[i])  
        {  
            p[pnum ++] = i;     
            facnum[i] = 2;    
            d[i] = 1;        
        }  
        for(int j = 0; j < pnum && i * p[j] < MAX; j++)  
        {  
            noprime[i * p[j]] = true;  
            if(i % p[j] == 0)  
            {  
                facnum[i * p[j]] = facnum[i] / (d[i] + 1) * (d[i] + 2);   
                d[i * p[j]] = d[i] + 1;   
                break;  
            }  
            facnum[i * p[j]] = facnum[i] * 2;  
            d[i * p[j]] = 1;   
        }  
    }  
}  
