
// C program to find log(n) on arbitrary base using Recursion
#include <stdio.h>

double Logn(double n, double r)
{
    return (n > r - 1) ? 1 + Logn(n / r, r) : 0;
}

int main()
{
    double n = 32;
    double r = 2;
    printf("%f", Logn(n, r));
    return 0;
}
