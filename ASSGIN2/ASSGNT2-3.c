#include <iostream>
using namespace std;
#include <string.h>

class Address
{

    string building;
    string city;
    string street;
    int pin;

public:
    Address() // Default Parameterless Constructor
    {
        this->building = "";
        this->city = "";
        this->street = "";
        this->pin = 0;
    }

    Address(string building, string city, string street, int pin) // Parameterized Constructor
    {
        cout << "In Parameterized constructor";
        this->building = building;
        this->city = city;
        this->street = street;
        this->pin = pin;
    }

    void accept() // FACILITATOR
    {
        cout << "Enter  Address details\n";
        cout << "Enter Building : ";
        getline(cin, this->building);

        cout << "Enter street : ";
        getline(cin, this->street);

        cout << "\nEnter city : ";
        getline(cin, this->city);

        cout << "\nEnter pin : ";
        cin >> this->pin;
    }

    void display() // FACILITATOR
    {
        cout << "\nAddress is ";
        cout << "\nBuilding : " << this->building;
        cout << "\t Street : " << this->street;
        cout << "\tCity : " << this->city;
        cout << "\tPin : " << this->pin << endl;
    }

    string get_building() // INSPECTOR FOR BUILDING
    {
        return this->building;
    }

    string get_city() // INSPECTOR FOR CITY
    {
        return this->city;
    }

    string get_street() // INSPECTOR FOR STREET
    {
        return this->street;
    }

    int get_pin() // INSPECTOR FOR PIN
    {
        return this->pin;
    }

    void set_pin() // MUTATOR/SETTER FOR PIN
    {
        cout << "Enter Pin : ";
        cin >> this->pin;
    }
    void set_city() // MUTATOR/SETTER FOR CITY
    {
        cout << "Enter City : ";
        cin >> this->city;
    }
    void set_building() // MUTATOR/SETTER FOR PIN
    {
        cout << "Enter Building : ";
        cin >> this->building;
    }
    void set_street() // MUTATOR/SETTER FOR STREET
    {
        cout << "Enter Street : ";
        cin >> this->street;
    }
};

int main()
{
    Address a1;
    a1.accept();

    a1.display();

    cout << "\nCall To Setters " << endl;

    a1.set_building(); // call to Setters/Mutators
    a1.set_street();
    a1.set_city();
    a1.set_pin();

    cout << "\nCall To Getters " << endl;

    cout << "Bulding : " << a1.get_building() << endl; // call to Getters/Inspectors
    cout << "Street : " << a1.get_street() << endl;
    cout << "City : " << a1.get_city() << endl;
    cout << "Pin : " << a1.get_pin() << endl;

    a1.display();

    Address a2("Neelkamal Building", "Nashik", "College road", 422205);
    a2.display();
}
