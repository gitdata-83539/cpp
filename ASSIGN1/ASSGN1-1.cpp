#include<iostream>
using namespace std;
struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate) {
    ptrDate->day = 12;
    ptrDate->month = 2;
    ptrDate->year = 2023;

}

void printDateOnConsole(struct Date* ptrDate) {
    cout << setfill('0') << setw(2) << ptrDate->day << "/"
              << setw(2) << ptrDate->month << "/"
              << setw(4) << ptrDate->year << endl;
}

void acceptDateFromConsole(struct Date* ptrDate) {
    cout << "Enter day:";
    cin >> ptrDate->day;
    cout << "Enter month:";
    cin >> ptrDate->month;
    cout << "Enter year:";
    cin >> ptrDate->year;
    
}

int main() {
    struct Date date;
    int choice;

    initDate(&date);

    do {
        cout << "\nMenu:\n";
        cout << "1. Initialize date\n";
        cout << "2. Print date\n";
        cout << "3. Accept date from console\n";
        cout << "0. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
            initDate(&date);
            cout << "Date initialized \n";
            break;

            case 2:
            printDateOnConsole(&date);
            break;

             case 3:
            acceptDateFromConsole(&date);
            break;

             case 0:
            cout << "Exiting the program \n";
            break;

            default:
            cout << "Invalid choice!!";
            break;
        }
    } while (choice !=0);
    
    return 0;

    
}
