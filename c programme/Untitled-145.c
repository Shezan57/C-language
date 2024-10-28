#include<stdio.h>
float getvalue(int r){
  float pi = 3.14;
  float a = pi*r*r;
  return a;

}

int main(){
   float Area = getvalue(3);
printf("Area is: %f,\n",Area);
return 0;
}