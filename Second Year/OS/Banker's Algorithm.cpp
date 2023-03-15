//Banker's Algorithm 
#include <iostream>

using namespace std;

int main()
{
	int nop, nor;
	cout << "Enter number of processes = ";
	cin >> nop;
	cout << "Enter number of resource types = ";
	cin >> nor;
	int allocation[nop][nor];
	int max[nop][nor];
	int need[nop][nor];
	int available[nor];
	int request[nor];
	int finish[nop];
	int safeSeq[nop];
	int work[nor];
	
	for(int i=0;i<nop;i+=1)
	{
		for(int j=0;j<nor;j+=1)
		{
		    cout << "Enter allocated resources at ["<<i<<"]["<<j<<"] = ";
			cin >> allocation[i][j];		
		}
	}
	for(int i=0;i<nop;i+=1)
	{
		for(int j=0;j<nor;j+=1)
		{
		    cout << "Enter max resources required at ["<<i<<"]["<<j<<"] = ";
			cin>>max[i][j];		
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	for(int j=0;j<nor;j+=1)
	{
	    cout << "Enter available resources of type "<<j+1<<" = ";
	    cin >> available[j];
	}
	for(int j=0;j<nor;j+=1)
    {
        cout << "Enter requested resources of type "<<j<< " for P1 = ";
        cin >> request[j];
    }
	int flag, count=0, canFinish, checkrequest;
	//resource request algorithm
	flag = 1;
	for(int j=0;j<nor;j+=1)
	{
	    if(request[j] > need[1][j])
	    {
	        flag = 0;
	        break;
        }
	    if(request[j] > available[j]) 
	    {
            flag = 0;
            break;
        }
    }
    if(flag == 1)      //Have the system pretend to have allocated the requested resources
    {
        for(int j=0;j<nor;j+=1) 
        {
            available[j] -= request[j];
            allocation[1][j] += request[j];
            need[1][j] -= request[j];
        }
        for(int j=0;j<nor;j+=1)
        {
            work[j] = available[j];
        }
        for(int j=0;j<nop;j+=1)
        {
            finish[j]=0;
        }
        count = 0;
        while(count<nop) //safety check algorithm to check safety of request
	    {
            for(int i=0;i<nop;i+=1)
        	{
        	    if(finish[i]==0)
        		{
                    canFinish = 1;
                    for(int j=0;j<nor;j+=1) 
                    {
                        if (need[i][j] > work[j]) 
                        {
                            canFinish = 0;  
                            break;
                        }
        		    }
        			if(canFinish == 1)
        			{
        			    for(int k=0;k<nor;k+=1)
        				{
        				    work[k] = work[k] + allocation[i][k];
        			    }
        				finish[i] = 1;
        				safeSeq[count] = i;
        				count+=1;
        			}
        	    }
            }
        }
        checkrequest=0;
        for(int i=0;i<nop;i+=1)
        {
            if(finish[i]==1)
            {
    		    checkrequest+=1;
    		}
    	}
        if(checkrequest == nop) 
        {
            cout << "Hence the new system state is safe, so we can immediately grant the request for process P1\n";
            flag = 5;
        }
        else if(checkrequest < nop) // restore the old state if current state not safe
        {
            for(int j=0;j<nor;j+=1) 
            {
                available[j] += request[j];
                allocation[1][j] -= request[j];
                need[1][j] += request[j];
            }
            cout << "old allocation restored!\n";
        }
    }
    else if(flag == 0)
    {
        cout << "Process exceed maximum claim.\n";
    }
        
	for(int j=0;j<nor;j+=1)
	{
	    work[j] = available[j];
	}
	count=0;
	while(count<nop) //safety check algorithm to check if system still in safe state
	{
		for(int i=0;i<nop;i+=1)
		{
		    if(finish[i]==0)
		    {
                canFinish = 1;
                for(int j=0;j<nor;j+=1) 
                {
                    if(need[i][j] > work[j]) {
                        canFinish = 0;  
                        break;
                    }
		        }
				if(canFinish == 1)
				{
				    for(int k=0;k<nor;k+=1)
				    {
				        work[k] = work[k] + allocation[i][k];
				    }
				    finish[i] = 1;
				    safeSeq[count] = i;
				    count+=1;
				}
		    }
		    else
		    {
		        count+=1;
		    }
	    }
	}
	int k=0;
	for(int i=0;i<nop;i+=1)
	{
		if(finish[i]==1){
		    k+=1;
		}
	}
	if(k<nop)
	{
		cout<<"Unsafe state as there is a deadlock in proccess.";
	}
	else if(k==nop)
	{
		cout<<"Safe state as there is no deadlock in any process. Safe Sequence is - \n";
		for (int i = 0; i < nop ; i+=1){
        cout << "P " << safeSeq[i] << ", ";
		}
	}
	else
	{
	    cout << "re-enter resources properly!";
	}
}

