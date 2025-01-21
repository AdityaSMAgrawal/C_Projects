#include<stdio.h>
void money_exchange(int dummy_amount,int dummy_exr)
{
    printf("The value of the given amount after applying the exchange rate is : $%d\n",dummy_amount/dummy_exr);
}
void transaction(int* actual_amount,int* exchange_rate,int * wallet,int* r_wallet)
{
    *wallet = *wallet - *actual_amount;
    *actual_amount = *actual_amount / *exchange_rate;
    *r_wallet = *r_wallet + *actual_amount;
}
int main()
{
    //taking input 
    int wallet,r_wallet,amount,exchange_rate;
    char choice;
    printf("Enter receiver's bank balance (in $): ");
    scanf("%d",&r_wallet);
    printf("Enter your bank balance(INR): ");
    scanf("%d",&wallet);
    printf("Enter the amount (INR) and exchange value for $: ");
    scanf("%d %d",&amount,&exchange_rate);
    //exchange amounts
    money_exchange(amount,exchange_rate);
    printf("The original amount(INR) is : %d\nThe exchange rate is : %d\n",amount,exchange_rate);
    printf("Your current bank balance (INR)is :%d\n",wallet);
    printf("Do you want to perform the transaction? y/n: ");
    scanf(" %c", &choice);
    if(choice=='y'||choice=='Y')
    {
        transaction(&amount, &exchange_rate,&wallet,&r_wallet);
        printf("$%d Have been transferred successfully\n",amount);
        printf("Receiver's bank balance: $%d\n",r_wallet);
        printf("Transaction has been completed successfully, now you have %d(INR)\n",wallet);
    }
    else
    {
        printf("Thank you for banking with us:)\n");
    }
    return 0;
}
