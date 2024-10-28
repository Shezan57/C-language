#include<stdio.h>
int main(){
    int i, number,range,a=0;
    printf("Enter the day number: ");
    scanf("%d",&number);
    range = number+1;
    while (number <= 3)
    {
        printf("Fishing");
        break;
    }
    
    for(i=4; i< range;i=i+5){
       if( number == i){
           a=1;
       }
            
    }
    for(i=5; i< range; i=i+5){
        if( number == i){
          a=1;
       }
    }
    if(a == 0){
        printf("Fishing in day %d",number);
    }
    else{
        printf("Drying in day %d",number);
    }
    return 0; 
}