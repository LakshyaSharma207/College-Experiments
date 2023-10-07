#include <iostream>

using namespace std;

int main() 
{
	int n,pi[20],bt[20],wt[20],ct[20],tat[20],i,j,k,p,q,at[20];
	cout<<"Enter total number of processes:";
	cin>>n;
	cout<<"Enter Process Arrival Time -\n";
	for(i=0;i<n;i++) 
	{
		cout<<"P["<<i+1<<"]:";
		cin>>at[i];
		pi[i]=i+1;
	}
	
	cout<<"Enter Process Burst Time -\n";
	for(i=0;i<n;i++) 
	{
		cout<<"P["<<i+1<<"]:";
		cin>>bt[i];
	}
		//sorting
    for (i=0;i<n;i++) 
    {
        for (j=i+1;j<n;j++)
        {
            if(at[i]>at[j]) 
            {
                k=at[i];
                at[i]=at[j];
                at[j]=k;
                p=bt[i];
                bt[i]=bt[j];
                bt[j]=p;
                q=pi[i];
                pi[i]=pi[j];
                pi[j]=q;
            }
        }
    }
	//completion time
	for(i=0;i<n;i++) 
	{
	    ct[i]=0; 
		for (j=0;j<=i;j++)
		{
		    ct[i]=ct[i]+bt[j];
		}
	}
	//turn around time
	for(i=0;i<n;i++)
	{
	    tat[i]=ct[i]-at[i];
	}
	//waiting time
	for (i=0;i<n;i++) 
	{
	    wt[i]=tat[i]-bt[i];
	}
	
	cout << "\nProcess id " << " Arrival Time " << " Burst time " << " Completion Time" <<" Turn around time " << " Waiting time \n";
	for(i=0;i<n;i++)
	{
	    cout<< pi[i] <<" \t\t" << at[i] <<" \t\t"<< bt[i] <<" \t\t" << ct[i]<<" \t\t"<< tat[i] <<" \t\t" << wt[i] <<"\n";
	}
}
