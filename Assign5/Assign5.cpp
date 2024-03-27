#include <iostream>
#include <cstring>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const {
        return day;
    }

    void setDay(int d) {
        day = d;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int m) {
        month = m;
    }

    int getYear() const {
        return year;
    }

    void setYear(int y) {
        year = y;
    }

    void display() const {
        cout << day << "/" << month << "/" << year;
    }

    void accept() {
        cout << "Enter Day: ";
        cin >> day;
        cout << "Enter Month: ";
        cin >> month;
        cout << "Enter Year: ";
        cin >> year;
    }

    bool isLeapYear() const {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        return false;
    }
};

class Employee {
private:
    int id;
    float salary;
    char dept[24];
    Date joiningDate;

public:
    Employee() : id(0), salary(0.0), joiningDate() {
        strcpy(dept, "");
    }

    Employee(int empId, float empSalary, const char* empDept, const Date& empJoiningDate)
        : id(empId), salary(empSalary), joiningDate(empJoiningDate) {
        strcpy(dept, empDept);
    }

    int getId() const {
        return id;
    }

    void setId(int empId) {
        id = empId;
    }

    float getSalary() const {
        return salary;
    }

    void setSalary(float empSalary) {
        salary = empSalary;
    }

    const char* getDept() const {
        return dept;
    }

    void setDept(const char* empDept) {
        strcpy(dept, empDept);
    }

    const Date& getJoiningDate() const {
        return joiningDate;
    }

    void setJoiningDate(const Date& empJoiningDate) {
        joiningDate = empJoiningDate;
    }

    void display() const {
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << dept << endl;
        cout << "Joining Date: ";
        joiningDate.display();
        cout << endl;
    }

    void accept() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Department: ";
        cin.ignore();
        cin.getline(dept, sizeof(dept));
        cout << "Enter Joining Date:\n";
        joiningDate.accept();
    }
};

class Person {
private:
    char name[401];
    char addr[100];
    Date birthDate;

public:
    Person() : birthDate() {
        strcpy(name, "");
        strcpy(addr, "");
    }

    Person(const char* pName, const char* pAddr, const Date& pBirthDate)
        : birthDate(pBirthDate) {
        strcpy(name, pName);
        strcpy(addr, pAddr);
    }

    const char* getName() const {
        return name;
    }

    void setName(const char* pName) {
        strcpy(name, pName);
    }

    const char* getAddr() const {
        return addr;
    }

    void setAddr(const char* pAddr) {
        strcpy(addr, pAddr);
    }

    const Date& getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(const Date& pBirthDate) {
        birthDate = pBirthDate;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << addr << endl;
        cout << "Birth Date: ";
        birthDate.display();
        cout << endl;
    }

    void accept() {
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, sizeof(name));
        cout << "Enter Address: ";
        cin.getline(addr, sizeof(addr));
        cout << "Enter Birth Date:\n";
        birthDate.accept();
    }
};

int main() {
    Date date1(10, 8, 1990);
    Date date2(5, 12, 2005);

    cout << "Testing Date class:\n";
    cout << "Date 1: ";
    date1.display();
    cout << endl;
    cout << "Is leap year for Date 1: " << (date1.isLeapYear() ? "Yes" : "No") << endl;

    cout << "Date 2: ";
    date2.display();
    cout << endl;
    cout << "Is leap year for Date 2: " << (date2.isLeapYear() ? "Yes" : "No") << endl;

    Employee emp1(101, 50000.0, "IT", date1);
    Employee emp2;
    emp2.accept();

    cout << "\nTesting Employee class:\n";
    cout << "Employee 1:\n";
    emp1.display();

    cout << "Employee 2:\n";
    emp2.display();

    Person person1("John Doe", "123 Main St", date2);
    Person person2;
    person2.accept();

    cout << "\nTesting Person class:\n";
    cout << "Person 1:\n";
    person1.display();

    cout << "Person 2:\n";
    person2.display();

    return 0;
}
