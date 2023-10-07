#include <iostream>

class Doctor
{
    char doctor[20];
    char area[20];
    public:
    void dinput()
    {
        std::cout << "\nEnter Name = ";
        std::cin >> doctor;
        std::cout << "\nEnter Area = ";
        std::cin >> area;
    }
    Doctor operator < (Doctor &x)
    {
        Doctor y;
        if(x.area < y.area)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
};

int main()
{
    int size, i, j;
    std::cout << "Enter size of list of doctors = ";
    std::cin >> size;
    Doctor a[size];
    std::cout << "\nNow enter details of MCGM Hospital - ";
	for(i=0; i < size; i+=1)
	{
		std::cout << "\nEnter details for doctor " << i+1 << " - ";
		a[i].dinput();
	}
	
	for(i = 1; i < size; i+=1)
    {
        j = i - 1;
        while(a[i] < a[j] && j>=0)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1]=a[i];
    }
    
}
