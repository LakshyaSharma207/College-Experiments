#include <stdio.h>

int enqueue(int);
int dequeue();

int visited[5] = {0}, bfs[5], front = 0, rear = 0;

int main()
{
    int graph[5][5] = {0, 1, 1, 0, 1,
                       1, 0, 1, 0, 0,
                       1, 1, 0, 1, 0,
                       0, 0, 1, 0, 1,
                       1, 0, 0, 1, 0};
                       
    int startNode, i;
    printf("Enter Starting Node (1-5) = ");
    scanf("%d", &startNode);
    startNode -=1;
    enqueue(startNode);
    visited[startNode] = 1;

    printf("\nBFS order - \n");
    while(front!=rear) {
        int currentNode = dequeue();
        printf("%d,", currentNode + 1);
        for(i = 0; i < 5; i += 1) {
            if(graph[currentNode][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    
    // printf("\nBFS order - ");
    // for(i = fron; i < 5; i++) {
    //     printf("%d, ", visited[i]);
    // }
}

int enqueue(int index) {
    if(rear > 4) {
        printf("Queue full.");
    }
    else {
        bfs[rear] = index;
        rear += 1;
    }
}

int dequeue() {
    if(front > rear) {
        printf("Queue empty");
    }
    else {
        front += 1;
        return bfs[front - 1];
    }
}
