#include <iostream>

class Employee
{
    private:
    char employeename[40];
    int employeeid;
    char edepartment[20];
    float salary;
    
    public:
    
    void readData()
    {
        std::cout << "Enter Employee name = ";
        std::cin >> employeename;
        std::cout << "Enter Employee ID number = ";
        std::cin >> employeeid;
        std::cout << "Enter Employee department name = ";
        std::cin >> edepartment;
        std::cout << "Enter Employee salary in USD= ";
        std::cin >> salary;
    }
    
    void display()
    {
        std::cout << "\nThe Employee details are -";
        std::cout << "\nName: " << employeename;
        std::cout << "\nID: " << employeeid;
        std::cout << "\nDepartment: " << edepartment;
        std::cout << "\nSalary: " << salary;
    }
    friend class Sales;
};

class Sales
{
    float sales;
    public:
    
    void  readsales()
    {
        std::cout << "\nEnter the employee's sales this month = ";
        std::cin >> sales;
    }
    
    void incentives(Employee t)
    {
        if(sales>=50 && sales<=100)
        {
            std::cout << "\nIncentives based on sales this month are = " << t.salary/10;
        }
        if(sales>=100 && sales<=150)
        {
            std::cout << "\nIncentives based on sales this month are = " << t.salary/5;
        }
        if(sales>150)
        {
            std::cout << "\nIncentives based on sales this month are = " << 3*t.salary/10;
        }
    }
    
    void performance()
    {
        if(sales>=50 && sales<=100)
        {
            std::cout << "\nSales this month were 'Satisfactory!!', Needs more improvement!";
        }
        
        if(sales<50)
        {
            std::cout << "\nSales this month were 'Poor!!', Work Harder! ";
        }
        
        if(sales>=101 && sales<=150)
        {
            std::cout << "\nSales this month were 'Good!!', Keep it up!";
        }
        
        if(sales>150)
        {
            std::cout << "\nSales this month were 'Excellent!!', Too bad you only get 30 percent pay raise :( ";
        }
    }
};

int main()
{
    std::cout << "Hello World\n";
    Employee a;
    Sales b;
    a.readData();
    a.display();
    b.readsales();
    b.incentives(a);
    b.performance();
}
