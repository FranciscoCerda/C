#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower=0;
    upper=300;
    step=20;
    printf("Celsius to Fahrenheit conversion\n");
    celsius=lower;
    while(celsius<=upper)
        {
            fahr=(celsius*(9.0/5.0))+32;
            printf("%9.0f\t%9.2f\n", celsius, fahr);
            celsius=celsius+step;
        }
}
