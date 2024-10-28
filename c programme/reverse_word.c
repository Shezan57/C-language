#include <stdio.h>  
int main()  
{   int i=0,j=0;
    char str1[80];
    char str2[80];
    printf("Enter Your Message: ");
    gets(str1);
    while (str1[i] != 0)
    {
        i++;
    }
    while (i>0)
    {
        str2[j] = str1[--i];
        j++;
    }
    str2[j] = '\0';
    printf("Reverse string is: ");
    for ( i = 0; i < str2[i] != '\0' ; i++)
    {
        if(str2[i+1] == ' ' || str2[i+1] == '\0'){
            for ( j = i; j>=0 && str2[j] != ' '; j--)
            {
                printf("%c",str2[j]);
            }
            printf(" ");
            
        }
    }
    return 0;
}