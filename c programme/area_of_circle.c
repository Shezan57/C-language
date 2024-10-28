# include<stdio.h>
// area measuring
int main(){
    float r;
    float pi = 3.1416;
    float area;
    printf("Enter the radious: ");
    scanf("%f",& r);

    area = pi*r*r;
printf("The area is: %f",area);

    return 0;
}