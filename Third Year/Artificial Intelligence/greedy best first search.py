n = int(input("Enter the number of nodes in the graph ="))
graph = []
print("Enter the adjacency matrix row by row -")
for i in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

# Heuristic cost from each node to the goal node (F)
heuristic = []
for i in range(n):
    cost = int(input(f"Enter cost of node {i}="))
    heuristic.append(cost)

print("The graph you entered is:")
for row in graph:
    print(row)

priorQueue = [(heuristic[0], 0, ["A"])]
visited = [0] * n

while priorQueue != []:
    priorQueue.sort()
    currentCost, currentNode, currentPath = priorQueue.pop(0)
    visited[currentNode] = 1
    if currentNode == (n - 1):  # Goal node
        print(f'Final path using Greedy Best First Search: {" -> ".join(currentPath)}')
        break;
    else:
        for i in range(n):
            if graph[currentNode][i] == 1 and visited[i] == 0:
                newPath = currentPath + [chr(65 + i)]
                hcost = heuristic[i]
                priorQueue.append((hcost, i, newPath))
