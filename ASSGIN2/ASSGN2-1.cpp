#include<iostream>
class Box {
    double length;
    double breadth;
    double height;

    public:
    
       Box(double length,double breadth, double height)
       {
          this->length = length;
          this->breadth = breadth;
          this->height = height;
       }
    
    double getLength() {
        return length;
    }

    double getBreadth() {
        return breadth;
    }

    double getHeight() {
        return height;
    }

    double volume(){
        return length * breadth * height;
    }

};

int main(){
    int choice;
    double length, breadth, height;

    do {
        std::cout << "1. Calculate volume of the box\n";
        std::cout << "2. Exit\n";
        
        std::cout << "enter choice:";
        std::cin >> choice;

        switch(choice) {
            case 1:
             std::cout << "Enter length of box:";
             std::cin >> length;
             std::cout << "Enter breadth of box:";
             std::cin >> breadth;
             std::cout << "Enter height of box:";
             std::cin >> height;
               
            Box box(length, breadth, height);
              std::cout << "Volume of the box: " << box.volume() << std::endl;
                break;

        }
    } while(choice !=0);
}
