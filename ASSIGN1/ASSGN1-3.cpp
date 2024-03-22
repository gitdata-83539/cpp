#include <iostream>
using namespace std;
#include <string.h>

class student
{
    int rollNo;
    string name;
    int marks;

public:
    void initStudent()
    {
        this->rollNo = 0;
        this->name = "";
        this->marks = 0;
    }
    void printStudentOnConsole()
    {
        cout << "Student details - \n";
        cout << "Roll No : " << this->rollNo << "\n";
        cout << "Name : " << this->name << "\n";
        cout << "Marks : " << this->marks << "\n";
    }

    void acceptStudentFromConsole()
    {
        cout << "Enter Roll No\n";
        cin >> rollNo;
        cout << "Enter Name\n";
        cin.ignore(); // Clear the input buffer
        getline(cin, this->name);
        cout << "Enter marks\n";
        cin >> marks;
    }
};
int main()
{
    int choice;
    student s1;

    do
    {
        cout << "Enter your choice : 1.Print default details 2.Enter Student Details 3.Print Student Deatails 4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.initStudent();
            s1.printStudentOnConsole();
            break;
        case 2:
            s1.acceptStudentFromConsole();
            break;
        case 3:
            s1.printStudentOnConsole();
            break;
        }
    } while (choice != 4);
    return 0;
}
