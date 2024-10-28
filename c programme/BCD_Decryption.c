// (1) The program requires the user to input a positive 3-digit number
//  through the keyboard each time and then outputs the number in digit reverse order.
// Note: when the input number contains a terminating 0, the output should not have a leading 0.
// For example, if 700 is the input, the output should be 7.

// (2) Input format: each test is a 3-digit number as well as a positive integer.
// (3) Output format: output number in digit reverse order.


#include<stdio.h>
int main(){
    int num,temp,r,sum=0;
    printf("Enter a positive 3 digit numbers: ");
    scanf("%d",&num);
    temp = num;
    while (temp != 0)
    {
        r = temp%10;
        sum = sum*10 + r;
        temp = temp/10;

    }
    printf("Reverse of number is: %d\n",sum);
    return 0;
}
