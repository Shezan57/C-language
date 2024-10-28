# include<stdio.h>
int main()
{
    float f;
    float c;
    printf("Enter farenheit temperature: ");
    scanf("%f",& f);
    c = (f-32)* 0.55556;
    printf("Celcious: %f",c);

    return 0;
}

