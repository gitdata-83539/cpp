#include<iostream>
//using namespace std;
class Tollbooth {
    private:
    unsigned int totalnoofcars;
    double totalamountofmoney;

 public:
   Tollbooth() 
   {
     std::cout << "Inside Parameterless ctor" << std::endl;
        this->totalnoofcars = 0;
        this->totalamountofmoney = 0.0;
   }

    Tollbooth(int totalnoofcars, double totalamountofmoney) {
        this->totalnoofcars = totalnoofcars;
        this->totalamountofmoney = totalamountofmoney;
    }

    //member function to handle paying cars
    void payingCar() {
        totalnoofcars++;
        totalamountofmoney+= 0.50;
    }

       //member function to handle don't paying cars
       void nopayCar() {
        totalnoofcars++;
       }

       void printOnConsole() const {
        std::cout << "Total cars passed: " << totalnoofcars << std::endl;
        std::cout << "Total amount collected:" << totalamountofmoney << std::endl;
        std::cout << "Number of paying cars: " << totalnoofcars -1 << std::endl; // Deduct 1 for the constructor call
        std::cout << "Number of non-paying cars: " << std::endl;

       }
};

int main() {
    Tollbooth tollbooth;

    tollbooth.payingCar();
    tollbooth.nopayCar();
    tollbooth.payingCar();
    tollbooth.payingCar();
    
    tollbooth.printOnConsole();

    return 0;

}
