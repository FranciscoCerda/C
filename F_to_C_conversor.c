#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower=0;
    upper=300;
    step=20;
    printf("Fahrenheit to Celsius conversion\n");
    fahr=lower;
    while(fahr<=upper)
        {
            celsius=(5.0/9.0)*(fahr-32.0);
            printf("%9.0f\t%9.2f\n", fahr, celsius);
            fahr=fahr+step;
        }
}
