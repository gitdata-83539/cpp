#include <iostream>
using namespace std;

class _Date
{ // In cpp,By default Class members  are private
    int Day;
    int Month;
    int Year;

public: // To make functions acccessible outside the class we made them public
    void initDate()
    {
        this->Day = 00;
        this->Month = 00;
        this->Year = 00;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter Date as Day Month Year:\n"
             << endl;
        cin >> this->Day;
        cin >> this->Month;
        cin >> this->Year;
    }
    void printDateOnConsole()
    {
        cout << "Date is : " << endl;
        cout << this->Day << "/" << this->Month << "/" << this->Year << endl;
    }

    bool isLeapYear()
    {
        if (this->Year != 0) // To Check Leap Year
            if ((this->Year % 4 == 0 && this->Year % 100 != 0) || (this->Year % 4 == 0 && this->Year % 400 == 0))
                return 1;
            else
                return 0;
        else
            return 0;
    }
};

int main()
{
    int choice;
    _Date d1;

    do
    {
        cout << "Enter your choice :\n 1.Print Default Date 2.Enter the Date 3.Print the Date 4.Check Leap year 5.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            d1.initDate();
            d1.printDateOnConsole();
            break;
        case 2:
            d1.acceptDateFromConsole();
            break;
        case 3:
            d1.printDateOnConsole();
            break;
        case 4:
            if (d1.isLeapYear())
                cout << "Year is leap year " << endl;
            else
                cout << "Year is not leap year " << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
