#include<stdio.h>
int main(){
    int num,i,f_index;
    int temp,high,x_x;
    int str[10],count[10];
    printf("How many time you want to input: ");
    scanf("%d",&num);
    printf("Please Input Numbers: \n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&str[i]);
}
    for(i=0;i<10;i++)
    {
        count[i] = 0;
}
    for(i=0;i<num;i++)
    {
        f_index = str[i];
    while(f_index!=0)
    {
        temp = f_index % 10;
        f_index = f_index / 10;
    switch(temp)
    {
    case 0:count[0]++;
        break;
    case 1:count[1]++;
        break;
    case 2:count[2]++;
        break;
    case 3:count[3]++;
        break;
    case 4:count[4]++;
        break;
    case 5:count[5]++;
        break;
    case 6:count[6]++;
        break;
    case 7:count[7]++;
        break;
    case 8:count[8]++;
        break;
    case 9:count[9]++;
        break;
}
    }
}
    high = count[0];
    for(i=0;i<10;i++)
    {
        if(count[i]>high)
        {
        high = count[i];
        x_x=i;
}
}
    printf("%d:",count[x_x]);
        for(i=0;i<10;i++){
        if(count[i]==high){
        printf(" %d",i);
}
}
    return 0;
}