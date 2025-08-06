// Check if a number is even or odd

#include<stdio.h>
int main() {
    int num;
    printf("Enter Number:");
    scanf("%d",&num);

    if (num%2==0)
    {
        printf("\n %d is even number",num);
    }
    else{
        printf("\n %d is odd number",num);
    }
    return 0;
    
}