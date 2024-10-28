#include<stdio.h>
#include<math.h>
int main(){
    int number, result=0, count=0,cnt,mul=1, rem;
    printf("Enter a number: ");
    scanf("%d",&number);
    int q = number;
    while(q != 0){
        q = q/10;
        count++;
    }
    cnt = count;
    q = number;

    while (q != 0)
    {
      rem = q % 10;
      while (cnt != 0)
      {
         mul = mul * rem;
         cnt--;
      }
      result = result + mul;
      cnt = count;
      q = q/10;
      mul = 1;
    }
    if (result == number)
    {
      printf("%d is an Armstrong number", number);
    }else{
      printf("%d is not an Armstrong number", number);
    }
    
    return 0;
}