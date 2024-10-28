#include<stdio.h>
#include<math.h>
int main()
{
    int n, j, i, r, t, sum, num;
    printf("Please enter a positive integer between 3 to 7 for Narcissistic number: ");
    scanf("%d", &num);
    n = pow(10, num);
    printf("Narcissistic numbers are: \n");
    for (i=100; i<n; i++)
    {
        sum = 0;
        t = i;
        while (t != 0)
    {
        r = t % 10;
        sum = sum + pow(r, num);
        t = t/10;
    }
    if (i == sum)
    {
        printf("%d\n", i);
    }
    }
    return 0;
}