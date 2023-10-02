#include <iostream>
#include <string.h>

class Bill
{
    char cname[50];
    long int cnumber{};
    char ctype[15];
    long int currentmr{};
    long int lastmr{};
    char month[10];
    long int amount{};
    public:
    void readData()
    {
        std::cout << "Write consumer name = ";
        std::cin >> cname;
        std::cout << "Write consumer number = ";
        std::cin >> cnumber;
        std::cout << "Write consumer type (out of Commercial or non-C) = ";
        std::cin >> ctype;
        std::cout << "Write Current meter reading = ";
        std::cin >> currentmr;
        std::cout << "Write Last meter reading = ";
        std::cin >> lastmr;
        std::cout << "Write Bill Month = ";
        std::cin >> month;
    }
    
    int calculateBill()
    {
        long int meter{currentmr - lastmr};
        if(strcmp(ctype,"Commercial"))
        {
            if (meter<=200)
            {
                amount = 5*meter;
            }
            else
            {
                amount = 10*meter;
            }
        }
        if(strcmp(ctype,"Non-commercial"))
        {
            if (meter<=100)
            {
                amount = 3*meter;
            }
            else
            {
                amount = 5*meter;
            }
        }
     
        return 0;
    }
    
    void printBill(){
        std::cout << "\n Printing Bill......";
        std::cout << "\nComsumer Name: " << cname;
        std::cout << "\nConsumer Number: " << cnumber;
        std::cout << "\nConsumer Type: " << ctype;
        std::cout << "\nCurrent Meter Reading: " << currentmr;
        std::cout << "\nLast Meter Reading: " << lastmr;
        std::cout << "\nBill Month: " << month;
        std::cout << "\nTotal Amount: " << amount;
        std::cout << "\nPlease pay Bill at the earliest!!";
    }
};

int main()
{
    std::cout<<"Hello World\n";
    Bill b;
    b.readData();
    b.calculateBill();
    b.printBill();
    
    return 0;
}
