#include<stdio.h>
int main(){
    char ch;

    printf("C programme to check given character is digit or not \n");
    scanf(" Please enter a digit %c",&ch);

    if(ch >= '0' && ch<= '9'){
        printf("Given number %c is a digit", ch);
    } else{
         printf("Given number %c is not a digit", ch);
    }
    return 0;

}