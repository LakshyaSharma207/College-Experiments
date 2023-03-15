#include<iostream>

using namespace std;

int main()
{
	int bsize[20], psize[20],flag[20], bno, pno, allocation[20], infrag[20], tinfrag=0;
	for(int i = 0; i < 10; i+=1)
	{
		allocation[i] = -1;
		infrag[i] = 0;
		flag[i] = 0;
	}
	//inputs from user
	cout << "Enter no. of blocks = ";
	cin >> bno;
	for(int i = 0; i < bno; i+=1)
    {
        cout << "\nEnter size of block " << i + 1 << " = ";
        cin >> bsize[i];
    }
	cout << "\nEnter no. of processes = ";
	cin >> pno;
	for(int i = 0; i < pno; i+=1)
    {
        cout << "\nEnter size of process " << i + 1 << " = ";
        cin >> psize[i];
    }
	
    //First Fit Algorithm
	for (int i = 0; i < pno; i+=1){
        for (int j = 0; j < bno; j+=1){
            if (flag[j] == 0 && bsize[j] >= psize[i]){
                allocation[i] = j;
                flag[j] = 1;
                break;
            }
        }
    }
    cout << "\nFor First Fit Algorithm - ";
	cout<<"\n\nprocess no.\tprocess size\t\tblock no.\t\tblock size";
	for(int i= 0; i < pno; i+=1)
	{
		cout << "\n" << i + 1 << "\t\t" << psize[i];
		if(allocation[i] != -1){
			cout<<"\t\t\t"<< allocation[i] + 1<<"\t\t\t"<< bsize[allocation[i]];
			infrag[i] = bsize[allocation[i]] - psize[i];
			tinfrag+=infrag[i];
		}
		else{
			cout<<"\t\t\tNot allocated"<<"\t\t"<<" - ";
		}
	}
	cout << "\nInternal Fragmentation = " << tinfrag << "\n\n";
	
	// Best-Fit Algorithm
	for(int i = 0; i < 10; i+=1)
	{
		allocation[i] = -1;
		infrag[i] = 0;
		flag[i] = 0;
	}
	tinfrag = 0;
    for (int i = 0; i < pno; i+=1)
    {
        int bestIdx = -1;
        for (int j = 0; j < bno; j+=1)
        {
            if (flag[j] == 0 && bsize[j] >= psize[i])
            {
                // Check for best fit
                if (bestIdx == -1 || bsize[j] < bsize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            allocation[i]=bestIdx;
            flag[bestIdx] = 1;
        }
    }
    cout << "\nFor Best Fit Algorithm - ";
    cout<<"\n\nprocess no.\tprocess size\t\tblock no.\t\tblock size";
	for(int i= 0; i < pno; i+=1)
	{
		cout << "\n" << i + 1 << "\t\t" << psize[i];
		if(allocation[i] != -1){
			cout<<"\t\t\t"<< allocation[i] + 1<<"\t\t\t"<< bsize[allocation[i]];
			infrag[i] = bsize[allocation[i]] - psize[i];
			tinfrag+=infrag[i];
		}
		else{
			cout<<"\t\t\tNot allocated"<<"\t\t"<<" - ";
		}
	}
	cout << "\nInternal Fragmentation = " << tinfrag << "\n\n";
	
	// Worst-Fit Algorithm
	for(int i = 0; i < 10; i+=1)
	{
		allocation[i] = -1;
		infrag[i] = 0;
		flag[i] = 0;
	}
	tinfrag = 0;
    for (int i = 0; i < pno; i+=1)
    {
        int wrstIdx = -1;
        for (int j = 0; j < bno; j+=1)
        {
            if (flag[j] == 0 && bsize[j] >= psize[i])
            {
                // Check for worst fit
                if (wrstIdx == -1 || bsize[j] > bsize[wrstIdx])
                {
                    wrstIdx = j;
                }
            }
        }
        if (wrstIdx != -1)
        {
            allocation[i]=wrstIdx;
            flag[wrstIdx] = 1;
        }
    }
    cout << "\nFor Worst Fit Algorithm - ";
    cout<<"\n\nprocess no.\tprocess size\t\tblock no.\t\tblock size";
	for(int i= 0; i < pno; i+=1)
	{
		cout << "\n" << i + 1 << "\t\t" << psize[i];
		if(allocation[i] != -1){
			cout<<"\t\t\t"<< allocation[i] + 1<<"\t\t\t"<< bsize[allocation[i]];
			infrag[i] = bsize[allocation[i]] - psize[i];
			tinfrag+=infrag[i];
		}
		else{
			cout<<"\t\t\tNot allocated"<<"\t\t"<<" - ";
		}
	}
	cout << "\nInternal Fragmentation = " << tinfrag;
	cout << "\n\nThus Best Fit has least internal fragmentation and most allocations.";
}


