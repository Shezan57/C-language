#include<stdio.h>
int main(){
    double loan_amount,interest_rate,number_of_years,total_ammount,monthly_amount;
    printf("Enter the loan amount: ");
    scanf("%lf",&loan_amount); 
    printf("Enter the loan interest rate: ");
    scanf("%lf",&interest_rate); 
    printf("Numbers of years: ");
    scanf("%lf",&number_of_years);
    total_ammount = loan_amount + (loan_amount*interest_rate*number_of_years)/100;
    monthly_amount = total_ammount/(number_of_years*12); 
    printf("Total amount: %0.2lf\n",total_ammount);
    printf("Monthly payable amount: %0.lf\n",monthly_amount);
    return 0;
}