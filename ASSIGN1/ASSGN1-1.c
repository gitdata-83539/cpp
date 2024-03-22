#include<stdio.h>
#include<stdlib.h>

struct Date {
    int day;
    int month;
    int year;
    };

    void initDate(struct Date* ptrDate);
    void printDateOnConsole(struct Date* ptrDate);
    void acceptDateFromConsole(struct Date* ptrDate);

int main()
{
    struct Date date;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Init Date\n");
        printf("2. Print Date On Console\n");
        printf("3. Accept date from console\n");
        printf("4.Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
              initDate(&date);
              break;

            case 2:
            printDateOnConsole(&date);
            break;

            case 3:
            acceptDateFromConsole(&date);
            break;

            case 4:
            printf("Exit..");

            default:
            printf("invalid choice!");

        }

    } while(1);
    
    return 0;
}

void initDate(struct Date* ptrDate) {
    printf("Enter day:");
    scanf("%d", &ptrDate->day);

    printf("Enter month:");
    scanf("%d", &ptrDate->month);

    printf("Enter year:");
    scanf("%d", &ptrDate->year);

    printf("Date init Successfully!");
}

void printDateOnConsole(struct Date* ptrDate) {
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);

    printf("Enter month: ");
    scanf("%d", &ptrDate->month);

    printf("Enter year: ");
    scanf("%d", &ptrDate->year);

    printf("Date accepted successfully!\n");
}

