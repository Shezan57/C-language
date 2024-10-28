#include <stdio.h>  
int main(){
    char str[80],search_word;
    int i=0,k,j=0,t=0,p;
    printf("Enter your Message: ");
    gets(str);
    printf("Enter a Key letter you want to search: ");
    scanf("%c",&search_word);
    while(str[t] !='\0'){
        t++;
        if(str[t] == search_word){
            p = 1;
    }
    }
    if(p != 1){
        printf("Not Found!");
    }
    while(p == 1){
    while(str[i] != search_word){
        i++;
    }
    j = i;
    while(str[j] != ' '){
        j--;
    }
    for(k = j; str[k] != '\0'; k++){
        printf("%c",str[k]);
        p=0;
    }
    }
    return 0;
}