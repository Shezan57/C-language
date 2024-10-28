#include<stdio.h>
#include<string.h>
struct information{
    char name[10];
    char birthday[11];
    char sex;
    char fixed_phone[15];
    char mobile_phone[15];
};

int main(){
     int n;
     printf("How many peoples information you want to store: ");
     scanf("%d",&n);
     
    struct information person[n];
    int i;
    for(i=0; i<n; i++){
        printf("Information for persons %d: \n",i+1);
        gets(person[i].name);
        gets(person[i].birthday);
        scanf("%c",&person[i].sex);
        gets(person[i].fixed_phone);
        gets(person[i].mobile_phone);
    }
    int q;
    printf("quety: ");
    scanf("%d",&q);
    int query[q];

    for(i=0; i<q; i++){
        if(query[i] < q){
            printf("%s\t%s\t%s\t%c\t%s",person[i].name,person[i].fixed_phone,person[i].mobile_phone,person[i].sex,person[i].birthday);

        }
        else{
            printf("Not Found!\n");
        }
    }
    return 0;
}