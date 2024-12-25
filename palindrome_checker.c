#include<stdio.h>
int main()
{
    char x[1000],y[1000];
    int i,j,k,m=0;
    printf("Enter a string :");
    scanf("%s",x);
    for(i=0;x[i]!='\0';i++){}
    i-=1;
    for(j=i,k=0;k<=i;j--,k++)
    {
        y[k] = x[j];
    }
    for(j=0,k=0;j<=i;j++,k++)
    {
        if(x[j]==y[k])
        {
            m++;
            continue;
        }
        else
        {
        printf("Not a palidrome string");
        break;
        }
    }
    if((m-1)==i)
    {
        printf("It's a Palidrome string");
    }
}
