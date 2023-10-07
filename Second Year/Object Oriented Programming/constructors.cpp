#include <iostream>

class Employee
{
    char ename[40];
    int id;
    char department[40];
    float salary;
    float DA;
    float HRA;
    float TA;
    float GrossSalary;
    
    public:
    
    Employee(){ //constructor
        std::cout << "Enter Employee ID to proceed = ";
    }
    
    Employee(int a)  //constructor overloading
    {
        id = a;
        
        std::cout << "\nEnter further Employee Details-";
        std::cout << "\nEnter Employee Name = ";
        std::cin >> ename;
        std::cout << "\nEnter Employee Department Name = ";
        std::cin >> department;
        std::cout << "\nEnter Employee Basic Salary = ";
        std::cin >> salary;
    }
    
    void display()
    {
        DA = salary/2;
        HRA = 0.3*salary;
        TA = salary/10;
        GrossSalary = salary + DA + HRA + TA;
        
        std::cout << "Employee Details - ";
        std::cout << "\nName: " << ename;
        std::cout << "\nID: " << id;
        std::cout << "\nDepartment: " << department;
        std::cout << "\nBasic Salary: " << salary;
        std::cout << "\nDearness Allowance: " << DA;
        std::cout << "\nHRA: " << HRA;
        std::cout << "\nTA: " << TA;
        std::cout << "\nGross Salary: " << GrossSalary;
    }
    ~Employee()
    {
        std::cout << "\nDestructor called here, function ended.";
    } // two objects so execute twice
};

int main()
{
    int x;
    std::cout << "Hello World\n";
    Employee obj1;
    std::cin >> x;
    Employee obj2(x);
    obj2.display();
}
