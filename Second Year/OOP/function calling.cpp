#include <iostream>  

void change(int data) //call by value
{
    data = 5;  
}

void swap(int *x, int *y)  //call by reference
{  
    int swap;  
    swap=*x;  
    *x=*y;  
    *y=swap;  
} 

int main()  
{  
    int data = 3;  
    change(data);  
    std::cout << "Value of the data is: " << data;  
    
    int x=50, y=10;    
    std::cout << "\nValue of x before swapping: " << x;
    std::cout << "\nValue of y before swapping: " << y;
    swap(&x, &y);  // passing value to function  
    std::cout << "\n\nValue of x after swapping is: "<< x;  
    std::cout << "\nValue of y after swapping is: "<< y;
}  
