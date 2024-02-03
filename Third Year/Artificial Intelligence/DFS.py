      #   A  B  C  D  E
graph = [[0, 1, 0, 0, 1],
         [1, 0, 1, 0, 0],
         [0, 1, 0, 1, 0],
         [0, 0, 1, 0, 1],
         [1, 0, 0, 1, 0]]
while(1):
    startNode = int(input("Enter starting node (1-5) = "))
    if startNode >= 1 and startNode <= 5:
        break

visited = [0, 0, 0, 0, 0] # stack
dfs = [startNode - 1] 
order = []
while dfs:
    currentNode = dfs.pop()
    if currentNode not in order:
        order.append(currentNode)
    for i in range(4, -1, -1):
        if graph[currentNode][i] == 1 and visited[currentNode] == 0:
            if visited[i] == 1:
                continue
            else:
                dfs.append(i)
                
    visited[currentNode] = 1
    
print("Order: ", list(map(lambda o: chr(o + 65), order)))
