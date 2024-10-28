#include <stdio.h>  
#include <string.h>  
void convert12(char* str) 
{  
    int h1 = (int)str[0] - '0'; 
    int h2 = (int)str[1] - '0'; 
    int hh = h1 * 10 + h2; 
    int m1 = (int)str[3] - '0';
    int m2 = (int)str[4] - '0';
    int mm = m1 * 10 + m2;
    char Meridien[2]; 
    if (hh < 12 ) { 
        Meridien[0] = 'A';  
        Meridien[1] = 'M';  
    }  
    else {  
        Meridien[0] = 'P'; 
        Meridien[1] = 'M';  
    } 
    if(hh == 24){
        printf("0:%d",mm);
    } else
    {
    hh %= 12; 
    if (hh == 0) {  
        printf("12:%d",mm); 
      }   
    else {  
        printf("%d:%d", hh,mm);   
    } 
    printf(" %c%c", Meridien[0], Meridien[1]); 
    }
}
int main()  
{  
    int i;
    char str[5]; 
    printf("Enter your time: ");
    scanf("%s",str);
    convert12(str);
    return 0;
}