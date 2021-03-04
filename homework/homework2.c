/*This code has been done mainly with the help of Angel and Caesar, 
whom I thank greatly for them ideas and I send them a great greeting.
Also, I would like to credit the YouTube channel "Pasos por Ingeniería" 
for helping me resolve some programming doubts.*/

#include <stdio.h>
#define MAX 128

int main()
    {
        int x;
        int i;
        int k;
        int cont = 0;
        int state = 0;
        unsigned long bin = MAX;
        
        printf("Write the number of prime numbers that you wish convert to binary:\n");
        scanf("%d", &k);
        
        printf("The first %d prime numbers are:\n", k);
        for(i = 2 ; cont < k ; ++i)
        {
            state = 0;
            for(x = 2 ; x <= i ; ++x)
            {
                if(i % x == 0)
                {
                    ++state;
                }
            }
                    if(state == 1)
                    {
                    printf("%3d = ", i);
                    ++cont;
                    state = 0;
                    
                for(bin = MAX; bin > 0; bin >>= 1)
                {
                    if (bin & i)
                    {
                        printf("1");
                    }
                    else
                    {
                        printf("0");
                    }
                }
                printf("\n");
            }
        }
    }
