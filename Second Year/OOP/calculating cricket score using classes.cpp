#include <iostream>
#include <string.h>

class Cricket
{
    char pname[40];
    char region[20];
    float battingavg;
    float bowlingavg;
    
    public:
    void readData()
    {
        std::cout << "\n Enter a Player Name: ";
        std::cin >> pname;
        std::cout << "\n Enter the Name of their region= ";
        std::cin >> region;
        std::cout << "\n Enter their Batting Average= ";
        std::cin >> battingavg;
        std::cout << "\n Enter their Bowling Average= ";
        std::cin >> bowlingavg;
    }
    
    void generateList(Cricket player[], int i)
    {
        char commonplayer[i][40];
        int k=0;
        for(int j=0;j<i;j+=1)
        {
            if(player[j].battingavg > 30 && player[j].bowlingavg < 25)
            {
                strcpy(commonplayer[k],player[j].pname);
                k+=1;
            }
        }
        std::cout << "List of Common Players are- ";
        for(int j=0;j<k;j+=1)
        {
            std::cout << "\n" << j+1 << ". " << commonplayer[j];
        }
    }
    void sortList(Cricket player[], int i)
    {
        int op;
        std::cout << "\nSort based on 1. Batting Avg. or 2. Bowling Avg.? ";
        std::cin >> op;
        Cricket ctemp;
        if(op == 1)
        {
        //sort based on batting Average
        for(int j=0;j<i;j+=1)
        {
            for(int k=j+1; k<=i; k+=1)
            {
                if(player[j].battingavg < player[k].battingavg)
                {
                    ctemp = player[j];
                    player[j] = player[k];
                    player[k] = ctemp;
                }
            }
        }
        }
        //sort based on bowling Average
        if(op == 2)
        {
            for(int j=0;j<i;j+=1)
        {
            for(int k=j+1; k<=i; k+=1)
            {
                if(player[j].bowlingavg < player[k].bowlingavg)
                {
                    ctemp = player[j];
                    player[j] = player[k];
                    player[k] = ctemp;
                }
            }
        }
        }
        std::cout << "\nSorted list!! Use Display to view it.";
    }
    
    void displayList(Cricket player[], int i)
    {
        std::cout << "Data:- ";
        for(int j=0;j<i;j+=1)
        {
            std::cout << "\nName: " << player[j].pname;
            std::cout << "\nRegion: " << player[j].region;
            std::cout << "\nBatting Average: " << player[j].battingavg;
            std::cout << "\nBowling Average: " << player[j].bowlingavg;
        }
    }
};

int main()
{
    int max;
    std::cout << "Enter number of players = ";
    std::cin >> max;
    Cricket player[max], ptemp;
    int op,i=0;
    while(1)
    {
        std::cout << "Enter option-\n 1. Enter data of new player\n 2. Display Data of players\n 3. Exit\n 4. Sort List\n 5. Generate List of Common Players\n Enter option = ";
        std::cin >> op;
        if(op == 1)
        {
            if(i>=max)
            {
                std::cout << "List is Full!";
            }
            else
            {
                player[i].readData();    
                i+=1;
            }
        }
        if(op == 2)
        {
            ptemp.displayList(player, i);
        }
        if(op == 3)
        {
            std::cout << "Breaking out.....";
            break;
        }
        if(op == 4)
        {
            ptemp.sortList(player, i);
        }
        if(op == 5)
        {
            ptemp.generateList(player, i);
        }
        else
        {
            std::cout << "\nEnter option again in numerical\n";
        }
    }
}
