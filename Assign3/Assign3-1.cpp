#include<iostream>
using namespace std;

class Cylinder
{
private:
float  radius,height ,volume;
public:
  Cylinder(double radius, double height):radius(0.0),height(0.0){

  }
    Cylinder(){

    }

float getRadius(){
    return radius;
}
void setRadius(float radius){
    this->radius=radius;
}
float getHeight(){
    return height;
}
void setHeight(float height){
    this->height=height;
}
float getVolume(){
     return this->volume =3.14 * radius * radius *height;
 
}
void printVolume(){
    cout<<getVolume()<<endl;
}

};

int main(){
   Cylinder* cy;
       cy=new Cylinder();
    int choice;
do{
cout<<"0.Exit\n1. set radius and height\n2. calculate volume \n3.printVolumeOnConsole"<<endl;

cin>>choice;
switch(choice){
    case 1:
        cy->setHeight(10.0);
        cy->setRadius(10.0);
    break;
    case 2:
        cy->getVolume();
     break;
    case 3: 
        cy->printVolume();
    break;
    default:
    cout<<"Enter correct Choice!!!";
    break;
    
}
}while(choice!=0);
return 0;
}
