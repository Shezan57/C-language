#include<stdio.h>
#include<string.h>
int main()
{
    char str[101];
    int n,i;
    printf("Enter your message: ");
    gets(str);
    printf("How many time you want to rotate: ");
    scanf("%d",&n);
    int len = strlen(str);
    n = n % len;
    for(i = n; i < len; i++){
        printf("%c", str[i]);
        
    }
    for(i= 0; i < n; i++){
            printf("%c", str[i]);
        }
        printf("\n");
    return 0;
}