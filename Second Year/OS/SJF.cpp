//non-preemptive SJF
#include<iostream>

using namespace std;
void swap(int *a, int *b) 
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

class Process{
    int ct,bt,at,wt,tbt;
    public:
    void input()
    {
        cout << "Enter Process Arrival Time = ";
        cin >> at;
        cout << "Enter Process Burst Time = ";
        cin >> bt;
    }
    
    void sort(int num,Process obj[])
    {
        for(int i=0;i<num;i+=1) 
        {
            for(int j=i+1;j<num;j+=1) 
            {
                if(obj[i].at>obj[j].at)
                {
                    swap(obj[i].at, obj[j].at);
                    swap(obj[i].bt, obj[j].bt);
                }
            }
        }
    }
    
    void calculate(int num, Process obj[])
    {
        tbt = 0;
        for (int i = 0; i < num; i++)
        {
            tbt += obj[i].bt;
            obj[i].ct = tbt;
            obj[i].wt = obj[i].ct - obj[i].at - obj[i].bt;
        }
    }
    
    void display(int num, Process obj[])
    {
        cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\n";
        for(int i=0; i<num; i++) 
        {
            cout << "P["<<i+1<<"]" << "\t\t" << obj[i].at <<"\t\t" << obj[i].bt << "\t\t" << obj[i].ct << "\t\t" << obj[i].wt << "\n";
        }
    }
};

int main() 
{
    int num;
    cout << "Enter no. of processes = ";
    cin >> num;
    Process a[num], temp;
    cout<<"Enter Processes -\n";
    for(int i=0;i<num;i+=1) 
	{
		a[i].input();
	}
    //arrange Arrival
    temp.sort(num, a);
    temp.calculate(num, a);
    
    cout << "Final Result...\n";
    temp.display(num, a);
}
