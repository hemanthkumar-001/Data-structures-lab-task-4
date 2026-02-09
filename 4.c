/*In a digital signal processing (DSP) system, digital filters are commonly represented
using polynomial equations, where the coefficients correspond to filter weights and
the exponents represent delay elements. Suppose two digital filters are represented
as polynomials stored using arrays. To analyze the combined effect of applying both
filters in sequence, the system needs to compute the multiplication of the two
polynomials.
Task:
Write a C program to: Store two polynomials using arrays, Perform polynomial
multiplication, Display the resulting polynomial in standard form.*/
#include <stdio.h>

int main()
{
    int d1, d2, i, j;
    int p1[50], p2[50], res[100];
    printf("Enter degree of first polynomial: ");
    scanf("%d", &d1);
    printf("Enter coefficients of first polynomial:\n");
    for(i = 0; i <= d1; i++)
        scanf("%d", &p1[i]);
    printf("Enter degree of second polynomial: ");
    scanf("%d", &d2);
    printf("Enter coefficients of second polynomial:\n");
    for(i = 0; i <= d2; i++)
        scanf("%d", &p2[i]);
    for(i = 0; i <= d1 + d2; i++)
        res[i] = 0;
    for(i = 0; i <= d1; i++)
        for(j = 0; j <= d2; j++)
            res[i + j] += p1[i] * p2[j];
    printf("Resultant polynomial:\n");
    for(i = d1 + d2; i >= 0; i--)
    {
        if(res[i] != 0)
        {
            if(i == 0)
                printf("%d", res[i]);
            else
                printf("%dx^%d + ", res[i], i);
        }
    }
    return 0;
}
