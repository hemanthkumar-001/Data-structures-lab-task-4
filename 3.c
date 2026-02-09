/*In an electrical power grid management system, daily power consumption patterns
are modeled using polynomial equations, where each term represents the
contribution of different factors such as industrial load, residential usage, and peak-
hour demand. These polynomial equations are stored using arrays to facilitate
efficient computation. To analyze the combined power consumption from two different
regions, the system needs to add two polynomial equations. (Implement in C
language)*/
#include <stdio.h>

int main()
{
    int n, i;
    int p1[50], p2[50], sum[50];
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficients of first polynomial:\n");
    for(i = 0; i <= n; i++)
        scanf("%d", &p1[i]);
    printf("Enter coefficients of second polynomial:\n");
    for(i = 0; i <= n; i++)
        scanf("%d", &p2[i]);
    for(i = 0; i <= n; i++)
        sum[i] = p1[i] + p2[i];
    printf("Resultant polynomial:\n");
    for(i = n; i >= 0; i--)
    {
        if(sum[i] != 0)
        {
            if(i == 0)
                printf("%d", sum[i]);
            else
                printf("%dx^%d + ", sum[i], i);
        }
    }
    return 0;
}
