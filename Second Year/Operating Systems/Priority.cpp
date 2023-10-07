//Priority scheduling

#include <iostream>
using namespace std;

void swap(int *a, int *b) 
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

class Process{
	int at,bt,ct,tat,wt,pid,prior;
	public:
	void insert(){
	    cout<<"Enter Process ID = ";
	    cin>>pid;
	    cout<<"Enter Arrival Time = ";
	    cin>>at;
	    cout<<"Enter Burst Time = ";
	    cin>>bt;
	    cout<<"Enter Priority = ";
	    cin>>prior;
	}
	void sort(int num,Process obj[])
    {
        for(int i=0;i<num;i+=1) 
        {
            for(int j=i+1;j<num;j+=1) 
            {
                if(obj[i].prior>obj[j].prior)
                {
                    swap(obj[i].at, obj[j].at);
                    swap(obj[i].bt, obj[j].bt);
                    swap(obj[i].pid, obj[j].pid);
                    swap(obj[i].prior, obj[j].prior);
                }
            }
        }
    }
    void calculate(int num, Process obj[])
    {
        obj[0].wt=0;
        for(int i=1;i<num;i++)
        {
            obj[i].wt=0;
            for(int j=0;j<i;j++)
            {
                obj[i].wt+=obj[j].bt;
            }
            obj[i].tat=obj[i].bt+obj[i].wt;
        }
    }
    void display(int num, Process obj[])
    {
        int avgwait=0;
        cout << "Process ID\tPriotity\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurn-Around-Time\n";
        for(int i=0; i<num; i++) 
        {
            cout << "P["<<obj[i].pid<<"]" << "\t\t" << obj[i].prior << "\t\t" << obj[i].at <<"\t\t" << obj[i].bt << "\t\t" << obj[i].ct << "\t\t\t" << obj[i].wt << "\t\t\t" << obj[i].tat << "\n";
            avgwait+=obj[i].wt;
        }
        cout << "Average waiting time = " << avgwait/num;
    }
};

int main()
{
	int max;
	cout<<"Enter no. of Process = ";
	cin>>max;
	Process obj[max],temp;

	for(int i=0; i<max; i+=1)
	{
		cout<<"Details for Process "<<i+1<<"- ";
		obj[i].insert();
	}
	temp.sort(max, obj);
	temp.calculate(max,obj);
	temp.display(max, obj);
}