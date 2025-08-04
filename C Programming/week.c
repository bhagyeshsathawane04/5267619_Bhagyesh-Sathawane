// C Program to Print the days of week 
#include <stdio.h>

int main() {
    int day;

    do {
        printf("Enter any day between 1 to 7: ");
        scanf("%d", &day);

        switch(day) {
            case 1:
                printf("Sunday\n");
                break;
            case 2:
                printf("Monday\n");
                break;
            case 3:
                printf("Tuesday\n");
                break;
            case 4:
                printf("Wednesday\n");
                break;
            case 5:
                printf("Thursday\n");
                break;
            case 6:
                printf("Friday\n");
                break;
            case 7:
                printf("Saturday\n");
                break;
            default:
                printf("Enter correct choice\n");
        }
    } while (day < 1 || day > 7);  

return 0;
}