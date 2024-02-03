      #   A  B  C  D  E
graph = [[0, 1, 1, 0, 0], #A
         [1, 0, 0, 1, 0], #B
         [1, 0, 0, 1, 1], #C
         [0, 1, 1, 0, 1], #D
         [0, 0, 1, 1, 0]] #E

cost = [[0, 3, 2, 0, 0],
        [3, 0, 0, 4, 0],
        [2, 0, 0, 2, 3],
        [0, 1, 2, 0, 1],
        [0, 0, 3, 1, 0]]

priorQueue = [(0, 0, ['A'])]  # (cost, node, path)
visited = [0, 0, 0, 0, 0]

while priorQueue != []:
    priorQueue.sort()
    currentCost, currentNode, currentPath = priorQueue.pop(0)
    # index = cumCost.index(min(cumCost))
    # currentNode = priorQueue.pop(index)
    visited[currentNode] = 1
    if currentNode == 4:  # Goal node
        print(f'Final path: {" -> ".join(currentPath)}')
        print(f'total cost = {currentCost}')
        break;
    else:
        for i in range(5):
            if graph[currentNode][i] == 1 and visited[i] == 0:
                # priorQueue.append(i)
                # cumCost.append(cumCost[index] + cost[currentNode][i])
                newPath = currentPath + [chr(65 + i)]
                newCost = currentCost + cost[currentNode][i]
                priorQueue.append((newCost, i, newPath))
                
    
