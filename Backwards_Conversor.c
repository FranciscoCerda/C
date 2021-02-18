#include <stdio.h>

int main()

{
    int fahr;
    printf("Backwards Fahrenheit to Celsius converter\n");
    for (fahr=300; fahr>=0; fahr=fahr-20)
    printf("%9d\t%9.2f\n",fahr, (5.0/9.0)*(fahr-32));

}
