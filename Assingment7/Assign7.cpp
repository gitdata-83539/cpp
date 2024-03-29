


#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {

    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
      
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {

    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {

    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    Employee *emp[5];
    int choice;
    int mgr=0;
    int slmn=0;
    int slmgr=0;
    int index=0;


    do
    {

    cout<<"0. EXIT   1.ACCEPT EMPLOYEE  2. Display the count of all employees with respect to designation   3. Display All Managers  4. Display All Salesman   5. Display All SalesManagers"<<endl;
    cout<<"enter choice : ";
    cin>>choice;

    switch (choice)
        {
        case 0:
            cout<<"thanks for using"<<endl;
            break;

        case 1:
        {
           if(index<5)
              {   
                  char c;
                  cout<<"enter the new choice --> A. Accept manager  B.accept salesman  C.accept salesmanager"<<endl;
                  cout<<"enter choice : ";
                  cin>>c;
                      switch(c)           
                            {
                                
                              case 'a':
                                {
                                    
                                        emp[index]=new Manager();
                                        emp[index]->accept();
                                        index++;
                                       
                                }
                                    
                                break;

                            
                            case 'b':
                               {
                                   
                                        emp[index]=new Salesman();
                                        emp[index]->accept();
                                        index++;
                                      
                                }
                                
                                break;

                    
                            case 'c':
                                {
                                    
                                        emp[index]=new SalesManager();
                                        emp[index]->accept();
                                        index++;
                                    
                                }
                                
                                break;

                            default:
                                cout<<"enter a valid choice"<<endl;
                             break;

                            }
              }

              else
              {
                cout<<"No vacancy"<<endl;
              }
        }
                   break;
              
        case 2:
        {
            for (int i = 0; i < index; i++)
           {
                  if(typeid(*emp[i]).name()==typeid(Manager).name())
                  {
                    mgr++;
                  }
                 else if(typeid(*emp[i]).name()==typeid(Salesman).name())
                  {
                    slmn++;
                  }
                 else if(typeid(*emp[i]).name()==typeid(SalesManager).name())
                  {
                    slmgr++;
                  }
            }
         cout<<"number of MANAGERS :        "<<mgr<<endl;
         cout<<"number of SALESMAN :        "<<slmn<<endl;
         cout<<"number of SALESMANAGER :    "<<slmgr<<endl;

         cout<<"TOTAL number of employees : "<<mgr+slmn+slmgr<<endl;
        }   
            break;
         
    //6. Display All Managers  7. Display All Salesman   8. Display All SalesManagers
       
        case 3:
            {
            

            cout<<" Information about MANAGER "<<endl;
            
             int count=0;

             for (int i = 0; i < index; i++)
                 {
                  if(typeid(*emp[i])==typeid(Manager))
                  {
                     emp[i]->display();
                     count++;
                    
                  }
                 }

                if (count==0)
                {
                    cout<<"    THERE ARE NO MANAGERS IN THE COMPANY  "<<endl;
                }
                
            }
            break;

        case 4:
            {

            cout<<"Information about SALESMAN  "<<endl;

            int count=0;
             for (int i = 0; i < index; i++)
                 {
                  if(typeid(*emp[i])==typeid(Salesman))
                  {
                     emp[i]->display();
                     count++;
                    
                  }
                 }

                if (count==0)
                {
                    cout<<" THERE ARE NO SALESMAN IN THE COMPANY  "<<endl;
                }
            }
            break;

        case 5:
        {

            cout<<" Information about SALESMANAGER "<<endl;

            int count=0;
             for (int i = 0; i < index; i++)
                 {
                  if(typeid(*emp[i])==typeid(SalesManager))
                  {
                     emp[i]->display();
                     count++;
                     
                  }
                 }
                
                if (count==0)
                {
                    cout<<" THERE ARE NO SALESMANAGERS IN THE COMPANY   "<<endl;
                }
         }
            
            break;        
        
        default:
           cout<<"enter a valid choice"<<endl;
            break;
        }
    } while (choice!=0);

    for(int i=0;i<index;i++)
    {
        delete emp[i];
    }
    
 return 0;
 }   
    
    
    
    return 0;
}
