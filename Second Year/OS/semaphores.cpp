#include<iostream>
using namespace std;

int readsem=0, mutex=0, readcount=0, writecount=0;
char resource[100];

void semwait(int *sem)
{
    *sem -= 1;
}

void semsignal(int *sem)
{
    *sem += 1;
}

void readerenter()
{
    if(writecount == 0)
    {
        semwait(&readsem);
        readcount++;
        semwait(&mutex);
        cout<<readcount<<" readers are reading.\n";
        cout<<"Contents of shared resource: "<<resource<<"\n";
        semsignal(&readsem);
    }
    else{
        cout<<"Writer has not exited, please wait....\n";
    }
}

void readerexit()
{
    if(readcount > 0)
    {
        semwait(&readsem);
        readcount--;
        semsignal(&readsem);
        cout<<readcount<<" readers are reading.\n";
        if(readcount == 0){
            semsignal(&mutex);
        }
    }
    else if(readcount == 0){
        cout<<"There are no readers currently reading.\n";
    }
    else{
        cout<<"Writer has not exited, please wait....\n";
    }
}

void writerenter()
{
    if(writecount == 1){
        cout<<"Only one writer at a time!!\n";
    }
    else if(readcount == 0 && writecount == 0)
    {
        semwait(&mutex);
        writecount++;
        cout<<"Input = ";
        cin>>resource;
        semsignal(&mutex);
    }
    else if(readcount > 0){
        cout<<"Readers have not exited, please wait....\n";
    }
}

void writerexit()
{
    if(writecount > 0)
    {
        semwait(&mutex);
        writecount--;
        cout<<"Writer has exited.\n";
        semsignal(&mutex);
    }
    else if(writecount == 0){
        cout<<"No writer is currently writing....\n";
    }
    else if(readcount > 0){
        cout<<"Readers have not exited, please wait....\n";
    }
}

int main()
{
    int op;
    while(1){
        cout<<"\n\n1. Enter a reader";
        cout<<"\n2. Exit a reader";
        cout<<"\n3. Enter writer";
        cout<<"\n4. Exit writer";
        cout<<"\n5. Exit Program";
        cout<<"\nEnter your choice = ";
        cin>>op;
        
        if(op == 1){
            readerenter();
        }
        if(op == 2){
            readerexit();
        }
        if(op == 3){
            writerenter();
        }
        if(op == 4){
            writerexit();
        }
        if(op == 5){
            break;
        }
    }
    cout<<"\n\nExiting Program.....\n";
}
