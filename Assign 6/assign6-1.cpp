#include <iostream>
using namespace std;

class date
{
    int d;
    int m;
    int y;

public:
    date()
    {
        this->d = 0;
        this->m = 0;
        this->y = 0;
    }

    date(int d, int m, int y)
    {
        this->d = d;
        this->m = m;
        this->y = y;
    }

    int getDay()
    {
        return this->d;
    }

    void setDay(int d)
    {
        this->d = d;
    }
    int getMonth()
    {
        return this->m;
    }

    void setMonth(int m)
    {
        this->m = m;
    }
    int getYear()
    {
        return this->y;
    }

    void setYear(int y)
    {
        this->y = y;
    }

    void acceptDate()
    {
        cout << "Enter Date as follows : ";
        cout << "Enter day : ";
        cin >> this->d;
        cout << "Enter month : ";
        cin >> this->m;
        cout << "Enter year : ";
        cin >> this->y;
    }

    void displayDate()
    {
        cout << "Date is : ";
        cout << this->d << "/" << this->m << "/" << this->y << endl;
    }

    bool isLeapYear()
    {

        if ((this->y % 4 == 0 && this->y % 100 != 0) || (this->y % 4 == 0 && this->y % 400 == 0))
            return 1;
        else
            return 0;
    }
};

class person
{
    string name;
    string addr;
    date bdate;

public:
    person()
    {
        this->addr = "";
        this->name = "";
    }

    person(string name, string addr, int d, int m, int y) : bdate(d, m, y)
    {
        this->name = name;
        this->addr = addr;
    }
    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {

        this->name = name;
    }

    string getAddr()
    {
        return this->addr;
    }

    void setAddr(string addr)
    {
        this->addr = addr;
    }

    date getBdate()
    {
        return bdate;
    }

    void setBdate(date bdate)
    {

        this->bdate = bdate;
    }

protected:
    virtual void accept()
    {
        cout << "Enter person name :";
        getline(cin, this->name);

        cout << "Enter address : ";
        getline(cin, this->addr);

        cout << "Enter Birthdate ";
        bdate.acceptDate();
    }

    virtual void display()
    {
        cout << "\n******************************* Person Details *******************************\n";
        cout << "Person name is : " << this->name << endl;
        cout << "Person address is : " << this->addr << endl;
        cout << "Birthdate is ";
        bdate.displayDate();
        if (bdate.isLeapYear() == 1)
            cout << "Year is leap year" << endl;
        else
            cout << "Year is not leap year" << endl;
    }
};

class employee : public person
{
private:
    int id;
    float sal;
    string dept;
    date doj;

public:
    employee()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "";
    }
    employee(int id, float sal, string dept, int d, int m, int y, string name, string addr, int b_d, int b_m, int b_y) : doj(d, m, y), person(name, addr, b_d, b_m, b_y)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }
    float getSal()
    {
        return this->sal;
    }

    void setSal(float sal)
    {
        this->sal = sal;
    }

    string getDept()
    {
        return this->dept;
    }

    void setDept(string dept)
    {
        this->dept = dept;
    }

    date getDOJ()
    {
        return this->doj;
    }

    void setDOJ(date d1)
    {
        this->doj = d1;
    }
    void accept()
    {
        person::accept();
        cout << "Enter employee id : ";
        cin >> this->id;
        cout << "Enter salary : ";
        cin >> this->sal;
        cout << "Enter department : ";
        getchar();
        getline(cin, this->dept);
        cout << "Enter date of joining : ";
        doj.acceptDate();
    }

    void display()
    {
        person::display();
        cout << "Employee id : " << this->id << endl;
        cout << "Employee salary : " << this->sal << endl;
        cout << "Employee dept : " << this->dept << endl;
        cout << "Employee joining date :";
        doj.displayDate();
        if (doj.isLeapYear() == 1)
            cout << "Year is leap year" << endl;
        else
            cout << "Year is not leap year" << endl;
        cout << "\n*****************************************************************************\n";
    }
};

int main()
{
    person *p1 = new employee();
    employee *e1 = (employee *)p1;
    e1->accept();
    e1->display();
    
    delete p1;
    p1 = NULL;
    e1 = NULL;
}