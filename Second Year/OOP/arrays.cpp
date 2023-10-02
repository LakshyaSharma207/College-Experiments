#include<iostream>

int main()
{
    int arr1[5], arr2[5], arr3[10];
	  int i, k, pos;
    std::cout << "Enter elements for First Array - ";
    for(i=0; i<5; i++)
    {
        std::cin >> arr1[i];
        arr3[i] = arr1[i];
    }
    
    k = i;
    std::cout << "Enter elements for Second Array - ";
    for(i=0; i<5; i++)
    {
        std::cin >> arr2[i];
        arr3[k] = arr2[i];
        k++;
    }
    
    std::cout << "\nMerged Array is -\n";
    for(i=0; i<k; i++)
    {
        std::cout << arr3[i] << ", ";
    }
    
    std::cout << "\nEnter position (from 0) of element you want to search = ";
    std::cin >> pos;
    for(i=0; i<k; i++)
    {
        if(i == pos)
        {
            std::cout << "Element at " << i << "position is " << arr3[i];
        }
    }

}
